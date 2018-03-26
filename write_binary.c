#include "camarero.h"
#include "utilidades.h"
#include "categoria.h"
#include "producto.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


void EscribirCamarero(t_camarero c[], int total)
{
	FILE *f = fopen("camarero.bin","wb");

	if (!f)
	{
		printf("Error al abrir el archivo \n");
	}
	else
	{
		fputc(total, f); 
		printf("%d\n",total);
		fwrite(c,sizeof(t_camarero),total,f);
	}
}

void EscribirProducto(t_producto *p, int total)
{
	FILE *f = fopen("producto.bin","wb");

	if (!f)
	{
		printf("Error al abrir el archivo \n");
	}
	else
	{
		fputc(total, f); 
		fwrite(p,sizeof(t_producto),total,f);
	}
}

