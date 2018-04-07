#ifndef _COMANDA_H
#define _COMANDA_H

#define DEBUG

#include "producto.h"
#include "categoria.h"

typedef struct
{
	int dni;
	int fechayhora;
	float total;
	float media;

} t_comanda;

void AltaComanda(t_comanda *c,int dni,int **cuentas, int mesa);
void ImprimirComanda (t_producto *prod,int totP, int **cuentas, int mesa);

#endif