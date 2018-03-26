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
	char str [MAX_LEN];
	char frmt_str [MAX_LEN];
	int opcion;
	int size;

	printf("Nombre: \n");
	fgets(str,MAX_LEN,stdin);
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
	//comprobar que no es null 
	size = strlen(str);
	p->categoria = (char *) malloc ((size+1) * sizeof(char));
	strcpy (p->categoria,str);
}


void EditarProducto(t_producto p[],t_categoria c[],int totalCat)
{
	int num;
	char str [3];

	printf("Introduzca el numero del producto a modificar:\n");
	fgets(str,3,stdin);
	clear_if_needed(str);
	sscanf(str,"%f",&num);

	AltaProducto(&p[num],c,totalCat);
}

void MostrarProductos(t_producto *p, int total)
{
	for (int i=0; i<total; i++)
	{
		printf("%d. %s %.2feuros %s\n",i,(p+i)->nombre,(p+i)->precio,(p+i)->categoria);
	}
}