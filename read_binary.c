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

void LeerCamareros(t_camarero camareros[])
{
	FILE * file;	
	int num;

	file = fopen("camarero.bin", "rb");
	
	if (!file)
	{
		printf("Error al abrir el fichero\n");
	}
	else
	{
		num = fgetc(file);
		
		fread(camareros, sizeof(t_camarero), num, file);
	}
}

int totalCamareros()
{
	FILE * file;	
	int num=0;

	file = fopen("camarero.bin", "rb");
	
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
		char str [50];
		int primero=0;

		char *line = NULL;
		size_t len = 0;
		ssize_t read;

		while(fgets(str,50,f))
		{
			if (primero!=0)
			{
				sscanf(str, "%d %s", &orden, nombre);
				c[i].orden = orden;
				c[i].nombre = (char *) malloc ((strlen(nombre)+1) * sizeof(char));
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

void LeerProductos(t_producto productos[])
{
	FILE * file;	
	int num;

	file = fopen("producto.bin", "rb");
	
	if (!file)
	{
		printf("Error al abrir el fichero\n");
	}
	else
	{
		num = fgetc(file);
		
		fread(productos, sizeof(t_producto), num, file);
		//Se guarda bien?¿
	}
}

int totalProductos()
{
	FILE * file;	
	int num=0;

	file = fopen("producto.bin", "rb");
	
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