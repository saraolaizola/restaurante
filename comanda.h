#ifndef _COMANDA_H
#define _COMANDA_H

#define DEBUG

#include "producto.h"
#include "categoria.h"
#include "camarero.h"

typedef struct
{
	int dni;
	int fechayhora;
	float total;
	float media;

} t_comanda;

void AltaComanda(t_comanda *c,int dni, int **cuentas, int mesa, t_producto *p,int totalP);
void mediaCamarero (t_comanda *c, int totC, t_camarero *camar, int totCam);

#endif