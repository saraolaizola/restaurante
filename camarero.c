#include "camarero.h"
#include "utilidades.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20

void AltaCamarero(t_camarero *c)
{
	char str [MAX_LEN];
	char frmt_str [MAX_LEN];
	int size;

	printf("Nombre: \n");
	fgets(str,MAX_LEN,stdin);
	clear_if_needed(str);
	sscanf(str, "%s",frmt_str);
	size = strlen(frmt_str);
	c->nombre = (char *) malloc ((size+1) * sizeof(char));
	strcpy (c->nombre, frmt_str);

	printf("Apellido: \n");
	fgets(str,MAX_LEN,stdin);
	sscanf(str, "%s",frmt_str);
	size = strlen(frmt_str);
	c->apellido = (char *) malloc ((size+1) * sizeof(char));
	strcpy (c->apellido,frmt_str);
	clear_if_needed(str);
	
	printf("DNI: \n");
	fgets(str,8,stdin);
	sscanf(str,"%d",&c->dni);
	clear_if_needed(str);
	//comprobar que es único

	printf("Telefono: \n");
	fgets(str,8,stdin);
	sscanf(str,"%d",&c->tel);
	clear_if_needed(str);

	printf("%s %s, dni: %d y tel: %d \n", c->apellido, c->nombre, c->dni, c->tel);
}

void printCamarero(t_camarero *c)
{
	printf("%s %s, dni: %d, tel: %d\n", c->nombre, c->apellido, c->dni, c->tel);
}

void MostrarCamareros(t_camarero *c, int total)
{
	printf("MostrarCamareros\n");
	printf("   total: %d\n", total);
	if(c == NULL) printf("  c es NULO!!!!\n");
	for (int i=0; i<total; i++)
	{
		printf("   Iteracion %d\n", i);
		printf("%s %s, dni: %d, tel: %d\n", c[i].nombre, c[i].apellido, c[i].dni, c[i].tel);
		//printf("%s %s, dni: %d, tel: %d\n", (c+i)->nombre, (c+i)->apellido, (c+i)->dni, (c+i)->tel);
	}
}