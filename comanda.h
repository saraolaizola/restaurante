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
void actividadCamarero (t_comanda *comanda, int totComanda, t_camarero *camarero, int totCamarero);
void valorMedioComandas (t_comanda *comanda, int totComanda);
void mediaServicio (t_comanda *comanda, int totComanda);
void PrecioMedioProductosxCategoria (t_producto p[],int totalP, t_categoria c[],int totalCat);

#endif