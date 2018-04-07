#include "cuenta.h"
#include "producto.h"
#include "categoria.h"
#include "utilidades.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int getNumeroMesa()
{
	int mesa;
	char str[5];

	printf("Introducir numero de la nueva mesa: \n");
	fgets(str,5,stdin);
	sscanf(str,"%d",&mesa);
	clear_if_needed(str);
}

int MesaOcupada(int *cuentas[],int mesa,int nueva)
{
	if (3==3)		//!cuentas[mesa][0]) //saber que esta vacio sin que deje de funcionar
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

	printf("%d\n", cuentas[mesa][0]);

	int posicion = (cuentas[mesa][0])*2;

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
			
				printf("Cantidad: \n");
				fgets(str,4,stdin);
				clear_if_needed(str);
				sscanf(str,"%d",&cantidad);
				posicion++;
				cuentas[mesa][posicion]=cantidad;	
			}
		} while ((totalPxCat+1)!=opcion);
	}
}

int MostrarProductosxCategoria (t_producto p[],int totalP,int numCat,t_categoria c[],int totalCat)
{
	char str [50];
	char *nombre;
	int num = 1;
	
	strcpy(str,Categoria(c,numCat,totalCat));
	_AEspacio(str);
	nombre = (char *) malloc ((strlen(str)+1) * sizeof(char));
	strcpy(nombre,str);
	
	printf(" ** %s **\n\n",nombre);

	for (int i=0;i<totalP;i++)
	{
		if (strcmp(nombre,_AEspacio(p[i].categoria))==0)
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
	_AEspacio(str);
	nombre = (char *) malloc ((strlen(str)+1) * sizeof(char));
	strcpy(nombre,str);

	for (int i=0;i<totalP;i++)
	{
		if (strcmp(nombre,_AEspacio(p[i].categoria))==0)
		{
			printf("numero %d\n",num);

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
	_AEspacio(str);
	nombre = (char *) malloc ((strlen(str)+1) * sizeof(char));
	strcpy(nombre,str);

	for (int i=0;i<totalP;i++)
	{
		if (strcmp(nombre,_AEspacio(p[i].categoria))==0)
		{
			printf("numero %d\n",num);

			if (num==opcion)
			{
				precio = p[i].precio;
			}
			num++;
		}
	}	
	return precio;

}



void printCuenta (int *cuentas[],int mesa)
{
	
}