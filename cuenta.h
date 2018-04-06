#ifndef _CUENTA_H
#define _CUENTA_H

#include "producto.h"
#include "categoria.h"

int getNumeroMesa();
int MesaOcupada(int *cuentas[],int mesa,int nueva);
void AtenderMesa();
void MostrarProductosxCategoria (t_producto p[],int totalP,int numCat,t_categoria c[],int totalCat);

#endif