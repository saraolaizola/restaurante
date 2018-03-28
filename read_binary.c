#include "camarero.h"
#include "utilidades.h"
#include "categoria.h"
#include "producto.h"
#include "read_binary.h"
#include "write_binary.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//CAMAREROS


void LeerCamareros(t_camarero c[])
{
	FILE * file;	
	int num;
	file = fopen("camareros.txt", "r");
	
	if (!file)
	{
		printf("Error al abrir el fichero\n");
	}
	else
	{
		char str [100];
		char nombre [20];
		char apellido [20];
		int dni;
		int tel;

		int primero=0;
		int i=0;

		while(fgets(str,100,file))
		{
			if (primero!=0)
			{
				sscanf(str, "%s %s %d %d",nombre,apellido,&dni,&tel);
				c[i].nombre = (char *) malloc ((strlen(nombre)+1) * sizeof(char));
				_AEspacio (nombre);
				strcpy (c[i].nombre, nombre);
				c[i].apellido = (char *) malloc ((strlen(apellido)+1) * sizeof(char));
				_AEspacio (apellido);
				strcpy (c[i].apellido, apellido);
				c[i].dni = dni;
				c[i].tel = tel;
				i++;
			}
			else
			{
				primero=1;
			}
		}
	}
}

int totalCamareros()
{
	FILE * file;	
	int num=0;

	file = fopen("camareros.txt", "r");
	
	if (!file)
	{
		printf("Error al abrir el fichero\n");
	}
	else
	{
		num = fgetc(file);
	}
	return num;
}

//CATEGORIAS

void LeerCategorias(t_categoria c[])
{
	FILE *f;
	int i=0;

	f = fopen("categorias.txt","r");

	if (!f)
	{
		printf("No se ha podido abrir el fichero\n");
	}
	else
	{
		int orden;
		char nombre [50];
		char str [100];
		int primero=0;

		while(fgets(str,100,f))
		{
			if (primero!=0)
			{
				sscanf(str, "%d %s", &orden, nombre);
				c[i].orden = orden;
				c[i].nombre = (char *) malloc ((strlen(nombre)+1) * sizeof(char));
				_AEspacio (nombre);
				strcpy (c[i].nombre, nombre);
				i++;
			}
			else
			{
				primero=1;
			}
		}
	}
}

int totalCategorias()
{
	FILE * file;	
	int num=0;

	file = fopen("categorias.txt", "r");
	
	if (!file)
	{
		printf("Error al abrir el fichero\n");
	}
	else
	{
		num = (fgetc(file)-48);
	}
	return num;
}

//PRODUCTOS

void LeerProductos(t_producto p[])
{
	FILE * file;	
	int num;

	file = fopen("productos.txt", "r");
	
	if (!file)
	{
		printf("Error al abrir el fichero\n");
	}
	else
	{
		char str [100];
		char nombre [20];
		char categoria [20];
		float precio;

		int primero=0;
		int i=0;

		while(fgets(str,100,file))
		{
			if (primero!=0)
			{
				sscanf(str, "%s %f %s",nombre,&precio,categoria);
				p[i].nombre = (char *) malloc ((strlen(nombre)+1) * sizeof(char));
				_AEspacio (nombre);
				strcpy (p[i].nombre, nombre);
				p[i].precio = precio;
				p[i].categoria = (char *) malloc ((strlen(categoria)+1) * sizeof(char));
				_AEspacio (nombre);
				strcpy (p[i].categoria, categoria);
				i++;
			}
			else
			{
				primero=1;
			}
		}
	}
}

int totalProductos()
{
	FILE * file;	
	int num=0;

	file = fopen("productos.txt", "r");
	
	if (!file)
	{
		printf("Error al abrir el fichero\n");
	}
	else
	{
		num = fgetc(file);
	}
	return num;
}