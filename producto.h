#ifndef _PRODUCTO_H
#define _PRODUCTO_H

#include "categoria.h"

#define DEBUG

typedef struct 
{
	char * nombre;
	float precio; 
	char * categoria;

} t_producto;

void AltaProducto(t_producto *p, t_categoria c[],int totalCat);
void printProducto(t_producto p);
void MostrarProductos (t_producto p[], int total);
void EditarProducto(t_producto p[],t_categoria c[],int totalCat);
void EliminarProducto(t_producto p[], int total);

#endif