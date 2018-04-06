#ifndef _COMANDA_H
#define _COMANDA_H

typedef struct{
	char *dni;
	char *fechayhora;
	float total;
	float media
}t_comanda;

void altaComanda();
void anadirAcomanda();
void imprimirComanda();


#endif