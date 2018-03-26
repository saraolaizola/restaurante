#ifndef _CATEGORIA_H
#define _CATEGORIA_H

#define DEBUG

typedef struct
{
	int id;
	char * nombre;
	int orden;
	
} t_categoria;

void MostrarCategorias(t_categoria categoria[], int total);
char * Categoria (t_categoria c[],int num, int total);

#endif