#include "utilidades.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void clear_if_needed(char *str)
{
	if (str[strlen(str) - 1] != '\n')
	{
		int c;    
    	while ( (c = getchar()) != EOF && c != '\n');
    }
}


int comprobarClave()
{
	FILE *f;
	int clave;
	char str [10];

	printf("Introducir clave administrador: \n");
	fgets(str,10,stdin);
	sscanf(str,"%d",&clave);
	clear_if_needed(str);

	f = fopen("clave.txt","r");

	if (!f)
	{
		printf("No se ha podido abrir el fichero\n");
	}
	else
	{
		int d;
		char str [10];
		while (fgets(str,10,f))	//mientras me devuelva algo
		{
			sscanf(str,"%d",&d);
			if(d!=clave)
			{
				printf("Error, la clave no coincide");
				return -1;
			}
			else
			{
				return 0;
			}
		}

	}
}

void cambiarClave()
{
	FILE* f;
	int clave;
	char str [10];

	printf("Introducir nueva clave: \n");
	fgets(str,10,stdin);
	sscanf(str,"%d",&clave);
	clear_if_needed(str);

	if (!f)
	{
		printf("No se ha podido abrir el fichero\n");
	}
	{
		f = fopen("clave.txt","w");

		fprintf(f,"%d", clave);

		fclose(f);
	}
}