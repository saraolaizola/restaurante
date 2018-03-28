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
void EditarProducto(t_producto p[],t_categoria c[],int totalCat);
void MostrarProductos(t_producto p[], int total);
void EliminarProducto(t_producto p[], int total);

void prueba();

#endif