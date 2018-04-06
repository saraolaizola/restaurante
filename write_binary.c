#include "camarero.h"
#include "utilidades.h"
#include "categoria.h"
#include "producto.h"
#include "comanda.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//FICHEROS DE TEXTO

void EscribirCamarero(t_camarero c[], int total)
{
	FILE *f = fopen("camareros.txt","w");

	if (!f)
	{
		printf("No se ha podido abrir el fichero\n");
	}
	else
	{
		fputc(total,f);
		fprintf(f,"\n");
		for (int i=0;i<total;i++)
		{
			fprintf(f,"%s %s %d %d",c[i].nombre,c[i].apellido,c[i].dni,c[i].tel);
			fprintf(f, "\n");
		}
		fclose(f);
	}
}

void EscribirCategoria(t_categoria c[], int total)
{
	FILE *f = fopen("categorias.txt","w");

	if (!f)
	{
		printf("No se ha podido abrir el fichero\n");
	}
	else
	{
		fputc(total,f);
		fprintf(f,"\n");
		for (int i=0;i<total;i++)
		{
			fprintf(f,"%d %s %d",c[i].id,c[i].nombre,c[i].orden);
			fprintf(f, "\n");
		}
		fclose(f);
	}
}

void EscribirProducto(t_producto p[], int total)
{
	FILE *f = fopen("productos.txt","w");

	if (!f)
	{
		printf("Error al abrir el archivo \n");
	}
	else
	{
		fputc(total,f);
		fprintf(f,"\n");
		for (int i=0;i<total;i++)
		{
			fprintf(f,"%d %s %f %s",p[i].id,p[i].nombre,p[i].precio,p[i].categoria);
			fprintf(f, "\n");
		}
		fclose(f);
	}
}


//FICHERO BINARIO 

void EscribirComanda (t_comanda c[], int total)
{
	FILE *f = fopen("comandas.bin","wb");

	if (!f)
	{
		printf("Error al abrir el fichero\n");
	}
	else
	{
		fputc(total, f); 
		printf("%d\n",total);
		fwrite(c,sizeof(t_comanda),total,f);
	}
}