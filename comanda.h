#ifndef _COMANDA_H
#define _COMANDA_H

#define DEBUG

typedef struct
{
	int dni;
	int fechayhora;
	float total;
	float media;

} t_comanda;

void AltaComanda(t_comanda *c,int dni);

#endif