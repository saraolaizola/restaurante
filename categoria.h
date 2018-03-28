#ifndef _CATEGORIA_H
#define _CATEGORIA_H

#define DEBUG

typedef struct
{
	int id;
	char * nombre;
	int orden;
	
} t_categoria;

void AltaCategoria(t_categoria *c,t_categoria categorias[],int total);
void OrdenarCategorias(t_categoria c[], int orden, int total);
void MostrarCategorias(t_categoria categoria[], int total);
char * Categoria (t_categoria c[],int num, int total);

#endif