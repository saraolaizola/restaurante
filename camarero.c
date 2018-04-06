#include "camarero.h"
#include "utilidades.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20

void AltaCamarero(t_camarero *c,t_camarero lista[],int total)
{
	char str [MAX_LEN];
	char frmt_str [MAX_LEN];
	int size,dni,unica;

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
		sscanf(str,"%d",&dni);
		clear_if_needed(str);
		unica = ClaveUnica(dni,lista,total);
		if (unica!=0)
		{
			printf("Error. DNI ya existente. \n");
		}
		if (strlen(str)!=9)
		{
			printf("Error. Introducir los 8 digitos.\n");
		}
	} while ((strlen(str)!=9)||(unica!=0));
	sscanf(str,"%d",&c->dni);
	clear_if_needed(str);

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
}

void printCamarero(t_camarero c)
{
	char *nombre = (char *) malloc ((strlen(c.nombre)+1) * sizeof(char));
	char *apellido = (char *) malloc ((strlen(c.apellido)+1) * sizeof(char));
	strcpy (nombre,c.nombre);
	strcpy (apellido,c.apellido);
	_AEspacio (nombre);
	_AEspacio (apellido);

	printf("%s %s, dni: %d, tel: %d\n",nombre,apellido, c.dni, c.tel);
}

void MostrarCamareros(t_camarero *c, int total)
{
	printf("\nCamareros:\n");
	for (int i=0; i<total; i++)
	{
		printCamarero(c[i]);
	}
}

int ClaveUnica (int dni,t_camarero *c,int total)
{
	for (int i=0; i<total; i++)
	{
		if (c[i].dni == dni)
		{
			return 1;
		}
	}
	return 0;
}

int getCamarero(t_camarero c[], int total)
{
	int dni=0;
	char str [MAX_LEN];

	printf("\n Introduzca su DNI: \n");
	fgets(str,10,stdin);
	sscanf(str,"%d",&dni);
	clear_if_needed(str);

	for (int i=0; i<total; i++)
	{
		if (c[i].dni == dni)
		{
			return dni;
		}
	}

	printf("\n Error. No coincide con ningun DNI \n");
	return 0;
}