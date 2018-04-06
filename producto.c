#include "producto.h"
#include "categoria.h"
#include "utilidades.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

void AltaProducto(t_producto *p, t_categoria c[],int totalCat)
{
	p->nombre = NULL;
	p->precio = 0;
	p->categoria = NULL;


	char str [MAX_LEN];
	char frmt_str [MAX_LEN];
	int opcion;
	int size;

	printf("Nombre: \n");
	fgets(str,MAX_LEN,stdin);
	EspacioA_(str);
	sscanf(str, "%s",frmt_str);
	clear_if_needed(str);
	size = strlen(frmt_str);
	p->nombre = (char *) malloc ((size+1) * sizeof(char));
	strcpy (p->nombre, frmt_str);

	printf("Precio: \n");
	fgets(str,6,stdin);
	clear_if_needed(str);
	sscanf(str,"%f",&p->precio);

	printf("Introduce el numero de la categoria deseada: \n");
	MostrarCategorias(c, totalCat);
	fgets(str,2,stdin);
	sscanf(str,"%d",&opcion);
	clear_if_needed(str);
	strcpy(str,Categoria(c,opcion,totalCat));
	
	size = strlen(str);
	p->categoria = (char *) malloc ((size+1) * sizeof(char));
	strcpy (p->categoria,str);
}

void printProducto(t_producto p)
{
	char *nombre = (char *) malloc ((strlen(p.nombre)+1) * sizeof(char));
	char *categoria = (char *) malloc ((strlen(p.categoria)+1) * sizeof(char));
	strcpy (nombre,p.nombre);
	strcpy (categoria,p.categoria);
	_AEspacio (nombre);
	_AEspacio (categoria);
	printf("%s %.2f%c %s\n",nombre,p.precio,36,categoria);
}


void MostrarProductos (t_producto p[], int total)
{
	for (int i=0;i<total;i++)
	{
		printf("%d. ",i+1);
		printProducto(p[i]);
	}
}

void EditarProducto(t_producto p[],t_categoria c[],int totalCat)
{
	int num;
	char str [3];

	printf("\n Introduzca el numero del producto a modificar:\n");
	fgets(str,3,stdin);
	clear_if_needed(str);
	sscanf(str,"%d",&num);

	AltaProducto(&p[num],c,totalCat);
}

void EliminarProducto(t_producto p[], int total)
{
	int num;
	char str [5];

	printf("\n Introduzca el numero del producto a eliminar:\n");
	fgets(str,5,stdin);
	clear_if_needed(str);
	sscanf(str,"%d",&num);

	for (int i=num;i<(total-1);i++)
	{
		p[i]=p[i+1];
	}
}

void MostrarProductosxCategoria (t_producto p[],int totalP,int numCat,t_categoria c[],int totalCat)
{
	char str [50];
	char *nombre;
	
	strcpy(str,Categoria(c,numCat,totalCat));
	nombre = (char *) malloc ((strlen(str)+1) * sizeof(char));
		
	for (int i=0;i<totalP;i++)
	{
		if (strcmp(str,p[i].categoria)==0)
		{
			printProducto(p[i]);
		}
	}	
}