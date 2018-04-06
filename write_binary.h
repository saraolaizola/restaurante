#ifndef _WRITE_BINARY_H
#define _WRITE_BINARY_H

#include "camarero.h"
#include "producto.h"
#include "categoria.h"
#include "comanda.h"

#define DEBUG

void EscribirCamarero(t_camarero c[], int total);
void EscribirCategoria(t_categoria c[], int total);
void EscribirProducto(t_producto p[], int total);
void EscribirComanda (t_comanda c[], int total);

#endif