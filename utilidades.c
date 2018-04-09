#include "utilidades.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 50

void clear_if_needed(char *str)
{
	if (str[strlen(str)-1] != '\n')
	{
		int c;    
    	while ( (c = getchar()) != EOF && c != '\n');
    }
}

int introducirOpcion(int opciones)
{
	int n;
	
	printf("\n Introduzca opci%cn (1-%d): ",162,opciones);
	do
	{
		n = pedirNumero();
		if ((n<0)||(n>opciones))
		{
			printf("Error. Introducir valor valido\n");
		}
	} while ((n<0)||(n>opciones));
	
	return n;
}

char* quitarEspacio (char* input)                                         
{
    int i,j;
    char *output=input;
    for (i = 0, j = 0; i<strlen(input); i++,j++)          
    {
        if (input[i]!=' ')                           
            output[j]=input[i];                     
        else
            j--;                                     
    }
    output[j]=0;
    return output;
}

char* EspacioA_ (char* input)                                         
{
    int i;
   	for (i = 0; i<strlen(input); i++)          
    {
        if (input[i]==' ')  
        {
        	input[i]='_';
        }                                           
    }
   	return input;
}

char* _AEspacio (char* input)                                         
{
    int i;
   	for (i = 0; i<strlen(input); i++)          
    {
        if (input[i]=='_')  
        {
        	input[i]=' ';
        }                                           
    }
   	return input;
}

char * toUpper (char *input)
{
	int i;
	for (i=0;i<strlen(input);i++)
	{
      toupper(input[i]);
   	}
}

char* ComaAPunto (char* input)                                         
{
    int i;
   	for (i = 0; i<strlen(input); i++)          
    {
        if (input[i]==',')  
        {
        	input[i]='.';
        }                                           
    }
   	return input;
}

float pedirFloat ()
{
	char str[MAX_LEN];
	int num,lenght,punto;
	float input=0;
	punto=0;
	num=0;

	do
	{
		fgets(str,50,stdin);
		
		clear_if_needed(str);
		ComaAPunto(str);
		lenght = strlen(str)-1;;

		for (int i=0;i<lenght;i++)
		{
			if ((!isdigit(str[i])&&(str[i]!='.')))
			{	
				num=1;
				break;
			}
			if (str[i]=='.')
				punto++;
		}
		if ((num!=0)||(punto>1))
			printf("Error. Asegurate de introducir un numero\n");

	} while (num!=0);
	
	sscanf(str,"%f",&input);

	return input;
}

int pedirNumero ()
{
	char str[MAX_LEN];
	int input,lenght,num;
	num=0;

	do
	{
		fgets(str,50,stdin);
		lenght = strlen (str)-1;

		for (int i=0;i<lenght;i++)
		{
			if (!isdigit(str[i]))
				num=1;
		}
		if (num!=0)
			printf("Error. Asegurate de introducir un numero\n");

	} while (num!=0);
	
	clear_if_needed(str);
	sscanf(str,"%d",&input);
	return input;
}

int comprobarClave()
{
	FILE *f;
	int clave;
	char str [10];

	printf("\n Introducir clave administrador: \n");
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
	else
	{
		f = fopen("clave.txt","w");

		fprintf(f,"%d", clave);

		fclose(f);
	}
}
