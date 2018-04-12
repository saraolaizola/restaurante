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
	int mesa,n;
	char str[5];
	
	printf("Introducir numero de la mesa (1-%d)\n",MESAS);
	
	do
	{
		mesa = pedirNumero();
		if ((mesa<0)||(mesa>MESAS))
		{
			printf("Error. Introducir valor valido\n");
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
	int opcion,id,totalPxCat,cantidad;
	char str [4];

	int posicion = (cuentas[mesa][0]);

	for (int i=1;i<totalCat+1;i++)
	{
		do
		{
			totalPxCat = MostrarProductosxCategoria(p,totalP,i,c,totalCat);
			printf(" Seleccionar opcion: \n");
			opcion = pedirNumero();
			
			if ((totalPxCat+1)!=opcion)
			{
				id = getProducto(p,totalP,i,c,totalCat,opcion);
				posicion++;
				cuentas[mesa][posicion]=id; 	
			
				posicion++;
				printf(" Cantidad: \n");
				cantidad = pedirNumero();
				//precio= getPrecio(p,totalP,i,c,totalCat,opcion);
				cuentas[mesa][posicion]=cantidad;	
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
	
	linea();
	_AEspacio(nombre);
	printf("\n     ** %s **\n\n",nombre);

	for (int i=0;i<totalP;i++)
	{
		if (strcmp(categoria,p[i].categoria)==0)
		{
			printf(" %d. ",num);
			printProducto(p[i]);
			printf("\n");
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
	int posicion,id,cantidad;
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
    	cantidad=cuentas[mesa][i+1];
    	i++;
    	for (int j=0; j<totP; j++)
    	{
    		if(id==prod[j].id)
    		{
    			printf(" - ");
    			printProducto(prod[j]);
    			printf(" (x%d) %.2f%c \n",cantidad,prod[j].precio*cantidad,36);
    		}
    	}	
    }
    total = totalCuenta(cuentas,mesa,prod,totP);
    linea();
    printf("     TOTAL = %.2f%c \n",total,36);
   	linea();
}


float totalCuenta(int **cuentas, int mesa, t_producto *productos, int totalP)
{
	float total=0;
	int posicion = cuentas[mesa][0];
	int id,cantidad;

    for(int i=1; i<posicion+1; i++)
    {
    	id = cuentas[mesa][i];
    	cantidad = cuentas[mesa][i+1];
    	for (int j=0;j<totalP;j++)
    	{
    		if (id==productos[j].id)
    		{
    			total += productos[j].precio * cantidad;
    		}
    	}
    	i++;
    }

    return total;
}