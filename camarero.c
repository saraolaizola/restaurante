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
	EspacioA_(str);
	sscanf(str, "%s",frmt_str);
	size = strlen(frmt_str);
	c->nombre = (char *) malloc ((size+1) * sizeof(char));
	strcpy (c->nombre, frmt_str);
	clear_if_needed(str);

	printf("Apellido: \n");
	fgets(str,MAX_LEN,stdin);
	EspacioA_(str);
	sscanf(str, "%s",frmt_str);
	size = strlen(frmt_str);
	c->apellido = (char *) malloc ((size+1) * sizeof(char));
	strcpy (c->apellido,frmt_str);
	clear_if_needed(str);
	
	printf("DNI (sin letra): \n");
	do
	{
		fgets(str,20,stdin);
		sscanf(str,"%d",&c->dni);
		clear_if_needed(str);
		if (strlen(str)!=9)
		{
			printf("Error. Introducir los 8 digitos.\n");
		}
	} while (strlen(str)!=9);

	printf("Telefono: \n");
	do
	{
		fgets(str,20,stdin);
		sscanf(str,"%d",&c->tel);
		clear_if_needed(str);
		if (strlen(str)!=10)
		{
			printf("Error. Introducir los 9 digitos.\n");
		}
	} while (strlen(str)!=10);

	printf("%s %s, dni: %d y tel: %d \n", c->apellido, c->nombre, c->dni, c->tel);
}

void printCamarero(t_camarero c)
{
	printf("%s %s, dni: %d, tel: %d\n", c.nombre, c.apellido, c.dni, c.tel);
}

void MostrarCamareros(t_camarero *c, int total)
{
	printf("\nCamareros:\n");
	for (int i=0; i<total; i++)
	{
		printCamarero(c[i]);
		//printf("%s %s, dni: %d, tel: %d\n", c[i].nombre, c[i].apellido, c[i].dni, c[i].tel);
	}
}