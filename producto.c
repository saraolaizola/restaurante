#include "producto.h"
#include "categoria.h"
#include "utilidades.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

void AltaProducto(t_producto *p, int totalP,t_categoria c[],int totalCat)
{
	p->nombre = NULL;
	p->precio = 0;
	p->categoria = NULL;

	char str [MAX_LEN];
	char frmt_str [MAX_LEN];
	int opcion;
	int size;

	p->id = totalP;

	printf("Nombre: \n");
	fgets(str,MAX_LEN,stdin);
	EspacioA_(str);
	toUpper(str);
	sscanf(str, "%s",frmt_str);
	clear_if_needed(str);
	size = strlen(frmt_str);
	p->nombre = (char *) malloc ((size+1) * sizeof(char));
	strcpy (p->nombre, frmt_str);

	printf("Precio: \n");
	p->precio = pedirFloat();

	//printf("Introduce el numero de la categoria deseada: \n");
	MostrarCategorias(c, totalCat);
	opcion = introducirOpcion(totalCat);
	strcpy(str,Categoria(c,opcion,totalCat));
	toUpper(str);
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
	printf("%s %.2f%c",nombre,p.precio,36);
}


void MostrarProductos (t_producto p[], int total)
{
	for (int i=0;i<total;i++)
	{
		printf("%d. ",i+1);
		printProducto(p[i]);
		printf("\n");
	}
}

void EditarProducto(t_producto p[],int totalP,t_categoria c[],int totalCat)
{
	int num;
	char str [3];

	num = introducirOpcion(totalP)-1;

	AltaProducto(&p[num],totalP,c,totalCat);
}

void EliminarProducto(t_producto p[], int total)
{
	int num;
	char str [5];

	num = introducirOpcion(total)-1;

	for (int i=num;i<(total-1);i++)
	{
		p[i]=p[i+1];
	}
}