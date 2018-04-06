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
	if (!cuentas[mesa]) //vacia
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

void AtenderMesa()
{
	
}

void MostrarProductosxCategoria (t_producto p[],int totalP,int numCat,t_categoria c[],int totalCat)
{
	char str [50];
	char *nombre;
	int num=1;
	
	strcpy(str,Categoria(c,numCat,totalCat));
	nombre = (char *) malloc ((strlen(str)+1) * sizeof(char));
	
	printf(" **%s\n**", nombre);

	for (int i=0;i<totalP;i++)
	{
		if (strcmp(str,p[i].categoria)==0)
		{
			printf("%d\n",num);
			printProducto(p[i]);
			num++;
		}
	}	
}