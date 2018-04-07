#ifndef _CUENTA_H
#define _CUENTA_H

#include "producto.h"
#include "categoria.h"

int getNumeroMesa();
int MesaOcupada(int *cuentas[],int mesa,int nueva);
void AtenderMesa(int *cuentas[],int mesa,t_producto p[],int totalP,t_categoria c[],int totalCat);
int MostrarProductosxCategoria (t_producto p[],int totalP,int numCat,t_categoria c[],int totalCat);
int getProducto(t_producto p[],int totalP,int numCat,t_categoria c[],int totalCat, int opcion);
void printCuenta (int *cuentas[],int mesa);
int getPrecio(t_producto p[],int totalP,int numCat,t_categoria c[],int totalCat, int opcion);

#endif