#include "comanda.h"
#include "utilidades.h"
#include "producto.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void AltaComanda(t_comanda *c,int dni, int **cuentas, int mesa)
{
	char str [3];
	time_t now;
	int posicion;
	float total;

	total=0.0f;

    now = time(0);
	c->fechayhora=(int) now;
    
    printf("Nota media del servicio: \n");
	fgets(str,6,stdin);
	clear_if_needed(str);
	sscanf(str,"%f",&c->media);
    
    c->dni=dni; 

    posicion=cuentas[mesa][0];

    for(int i=1; i<posicion+1; i++)
    {
    	total+=cuentas[mesa][i+1];
    	i++;
    }

    c->total=total;

}

void ImprimirComanda (t_producto *prod,int totP, int **cuentas, int mesa)
{

	int posicion, id;


	posicion=cuentas[mesa][0];
	printf("Cuenta de la mesa %i\n", mesa);

	 for(int i=1; i<posicion+1; i++)
    {
    	id=cuentas[mesa][i];
    	i++;
    	for (int j=0; j<totP; j++)
    	{
    		if(id==prod[j].id)
    		{

    			printProducto(prod[j]);
    		}
    	}
    	
    }

}

void mediaCamarero(t_comanda *comanda, int totComanda, t_camarero *camarero, int totCamarero)
{
    int dni;
    float total;
    int cantidad;

    printf("La nota media de los camareros es la siguiente:\n");
    
	for (int i =0; i< totCamarero; i++)
	{
        dni= camarero [i];
        cantidad=0;
        total=0,0;

		for (int j=0; j<totComanda; j++) 
        {
            if(dni==comanda[j].dni)
            {
                cantidad++;

                total += comanda[j].media;
                
            }
        }

        total= total/cantidad;

        printf("%s %s %f\n",camarero[i].nombre, camarero[i].apellido, total );







	}
}