#ifndef _READ_BINARY_H
#define _READ_BINARY_H

#include "camarero.h"
#include "producto.h"
#include "categoria.h"

#define DEBUG

void LeerCamareros(t_camarero camareros[]);
int totalCamareros();

void LeerCategorias(t_categoria categoria[]);
int totalCategorias();

void LeerProductos(t_producto productos[]);
int totalProductos();

void LeerComandas(t_comanda comandas[]);
int totalComandas();

#endif