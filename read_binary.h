#ifndef _READ_BINARY_H
#define _READ_BINARY_H

#include "camarero.h"
#include "producto.h"
#include "categoria.h"

#define DEBUG

void LeerCamareros(t_camarero camareros[]);
int totalCamareros();

void MostrarCamareros(t_camarero camareros[], int total);
void LeerCategorias(t_categoria categoria[]);
int totalCategorias();

void LeerProductos(t_producto productos[]);
int totalProductos();

#endif