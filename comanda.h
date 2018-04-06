#ifndef _COMANDA_H
#define _COMANDA_H

typedef struct{
	int dni;
	int fechayhora;
	float total;
	float media
}t_comanda;

void altaComanda();
void anadirAcomanda();
void imprimirComanda();


#endif