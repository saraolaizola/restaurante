#ifndef _CUENTA_H
#define _CUENTA_H

#include "producto.h"
#include "categoria.h"

int getNumeroMesa(int MESAS);
int MesaOcupada(int *cuentas[],int mesa,int nueva);

void AtenderMesa(int *cuentas[],int mesa,t_producto p[],int totalP,t_categoria c[],int totalCat);
int MostrarProductosxCategoria (t_producto p[],int totalP,int numCat,t_categoria c[],int totalCat);
int getProducto(t_producto p[],int totalP,int numCat,t_categoria c[],int totalCat, int opcion);
float getPrecio(t_producto p[],int totalP,int numCat,t_categoria c[],int totalCat, int opcion);

void linea();
void ImprimirCuenta (t_producto *prod,int totP, int **cuentas, int mesa);
float totalCuenta(int **cuentas, int mesa, t_producto *productos, int totalP);

#endif