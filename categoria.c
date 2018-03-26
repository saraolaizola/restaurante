#include "categoria.h"
#include "producto.h"
#include "utilidades.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void MostrarCategorias(t_categoria c[], int total)
{
	int i;

	for (i=0;i<total;i++)
	{
		printf("%d %s\n",c[i].orden,c[i].nombre);
	}
}

char * Categoria (t_categoria c[],int num, int total)
{
	int i;
	char * nombre="\0";

	for (i=0;i<total;i++)
	{
		if (num==c[i].orden)
		{
			int size = strlen(c[i].nombre);
			nombre = (char *) malloc ((size+1) * sizeof(char));
			strcpy (nombre,c[i].nombre);
		}
	}
	return nombre;
}