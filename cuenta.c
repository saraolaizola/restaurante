#include "cuenta.h"
#include "producto.h"
#include "categoria.h"
#include "utilidades.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int getNumeroMesa(int MESAS)
{
	int mesa;
	char str[5];
	
	printf("Introducir numero de la mesa (1-%d)\n",MESAS);
	
	do
	{	
		fgets(str,5,stdin);
		sscanf(str,"%d",&mesa);
		clear_if_needed(str);

		if((mesa<0)||(mesa>MESAS))
		{
			printf("Error. Introducir un valor valido\n");
		}

	} while ((mesa<0)||(mesa>MESAS));

	mesa = mesa-1; 

	return mesa;
}

int MesaOcupada(int *cuentas[],int mesa,int nueva)
{
	if (cuentas[mesa][0]==0)		//!cuentas[mesa][0]) //saber que esta vacio sin que deje de funcionar
	{
		if (nueva==0)
		{
			printf("Error. Mesa vacia\n");
		}
		return 0;
	}
	else
	{
		if (nueva==1)
		{
			printf("Error. Mesa ocupada\n");
		}
		return 1;
	}
}

void AtenderMesa(int *cuentas[],int mesa,t_producto p[],int totalP,t_categoria c[],int totalCat)
{
	int opcion,id,totalPxCat,cantidad, precio;
	char str [4];

	int posicion = (cuentas[mesa][0]);

	for (int i=1;i<totalCat+1;i++)
	{
		do
		{
			totalPxCat = MostrarProductosxCategoria(p,totalP,i,c,totalCat);
			printf(" Seleccionar opcion: \n");
			fgets(str,4,stdin);
			clear_if_needed(str);
			sscanf(str,"%d",&opcion);
			
			if ((totalPxCat+1)!=opcion)
			{
				//cuentas[mesa] = (int *) realloc (cuentas, (posicion+3) * sizeof(int));
				id = getProducto(p,totalP,i,c,totalCat,opcion);
				posicion++;
				cuentas[mesa][posicion]=id; 	
			
				//printf("Cantidad: \n");
				//fgets(str,4,stdin);
				//clear_if_needed(str);
				//sscanf(str,"%d",&cantidad);
				posicion++;
				precio= getPrecio(p,totalP,i,c,totalCat,opcion);
				cuentas[mesa][posicion]=precio;	
			}
		} while ((totalPxCat+1)!=opcion);
	}
	cuentas[mesa][0]=posicion;
}

int MostrarProductosxCategoria (t_producto p[],int totalP,int numCat,t_categoria c[],int totalCat)
{
	char str [50];
	char *nombre;
	char *categoria;
	int num = 1;
	
	strcpy(str,Categoria(c,numCat,totalCat));
	categoria = (char *) malloc ((strlen(str)+1) * sizeof(char));
	nombre = (char *) malloc ((strlen(str)+1) * sizeof(char));
	strcpy(categoria,str);
	strcpy(nombre,str);
	
	_AEspacio(nombre);
	printf(" ** %s **\n\n",nombre);

	for (int i=0;i<totalP;i++)
	{
		if (strcmp(categoria,p[i].categoria)==0)
		{
			printf(" %d. ",num);
			printProducto(p[i]);
			num++;
		}
	}	
	printf(" %d. Pasar a siguiente categoria\n\n",num);

	return (num-1);
}

int getProducto(t_producto p[],int totalP,int numCat,t_categoria c[],int totalCat, int opcion)
{
	char str [50];
	char *nombre;
	int num=1;
	int id;

	strcpy(str,Categoria(c,numCat,totalCat));
	nombre = (char *) malloc ((strlen(str)+1) * sizeof(char));
	strcpy(nombre,str);

	for (int i=0;i<totalP;i++)
	{
		if (strcmp(nombre,p[i].categoria)==0)
		{
			if (num==opcion)
			{
				id = p[i].id;
			}
			num++;
		}
	}	
	return id;
}

float getPrecio(t_producto p[],int totalP,int numCat,t_categoria c[],int totalCat, int opcion)
{
	char str [50];
	char *nombre;
	int num=1;
	float precio;

	strcpy(str,Categoria(c,numCat,totalCat));
	
	nombre = (char *) malloc ((strlen(str)+1) * sizeof(char));
	strcpy(nombre,str);

	for (int i=0;i<totalP;i++)
	{
		if (strcmp(nombre,p[i].categoria)==0)
		{
			if (num==opcion)
			{
				precio = p[i].precio;
			}
			num++;
		}
	}	
	return precio;
}


void ImprimirCuenta (t_producto *prod,int totP, int **cuentas, int mesa)
{
	int posicion, id;
	float total;
	time_t now;
    struct tm *tm;

   linea();
	printf("\n ** RESTAURANTE MISAJO ** \n");
	printf("   Cuenta de la mesa %d \n", mesa+1);

    now = time(0);
	tm = localtime (&now);
	printf ("    %04d/%02d/%02d %02d:%02d \n",tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,tm->tm_hour,tm->tm_min);

	linea();
	
	posicion=cuentas[mesa][0];
	
	for(int i=1; i<posicion+1; i++)
    {
    	id=cuentas[mesa][i];
    	i++;
    	for (int j=0; j<totP; j++)
    	{
    		if(id==prod[j].id)
    		{
    			printf(" - ");
    			printProducto(prod[j]);
    		}
    	}	
    }
    total = totalCuenta(cuentas,mesa);
    linea();
    printf("     TOTAL = %.2f \n",total);
   	linea();
}

void linea()
{
	printf("\n -------------------------\n");
}

float totalCuenta(int **cuentas, int mesa)
{
	float total=0;
	int posicion = cuentas[mesa][0];

    for(int i=1; i<posicion+1; i++)
    {
    	total+=cuentas[mesa][i+1];
    	i++;
    }

    return total;
}