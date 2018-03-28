#include "categoria.h"
#include "producto.h"
#include "utilidades.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 30

void AltaCategoria(t_categoria *c,t_categoria categorias[],int total)
{
	char str [MAX_LEN];
	char frmt_str [MAX_LEN];
	int size,orden;

	c->id = total;

	printf("Nombre: \n");
	fgets(str,MAX_LEN,stdin);
	EspacioA_(str);
	sscanf(str, "%s",frmt_str);
	clear_if_needed(str);
	size = strlen(frmt_str);
	c->nombre = (char *) malloc ((size+1) * sizeof(char));
	strcpy (c->nombre, frmt_str);

	if (total!=0)
	{
		do 
		{
			MostrarCategorias(categorias,total);
			printf("Orden de la nueva categoria: \n");
			fgets(str,3,stdin);
			clear_if_needed(str);
			sscanf(str,"%d",&orden);
			if ((orden<0)||(orden>(total+1)))
			{
				printf(" Error. No hay tantas categorias\n");
			}
		} while ((orden<0)||(orden>(total+1)));
		sscanf(str,"%d",&c->orden);
		if ((orden<total)||(orden==total))
		{
			OrdenarCategorias(categorias,orden,total);
		}
	}
	else
	{
		c->orden=1;
	}
}

void OrdenarCategorias(t_categoria c[], int orden, int total)
{
	int i;
	t_categoria temp;

	for (i=orden;i<total+1;i++)
	{
		c[i-1].orden=(i+1);
	}

	for (i=total;i>orden-1;i--)
	{
		temp = c[i];
		c[i] = c[i-1];
		c[i-1] = temp;
	}
}

void MostrarCategorias(t_categoria c[], int total)
{
	for (int i=0;i<total;i++)
	{
		printf("%d %s\n",c[i].orden,_AEspacio(c[i].nombre));
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
			EspacioA_ (nombre);
		}
	}
	return nombre;
}