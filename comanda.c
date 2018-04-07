#include "comanda.h"
#include "utilidades.h"
#include "producto.h"
#include "camarero.h"
#include "cuenta.h"

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
	float total=0;
    float nota;

    now = time(0);

    printf("Nota media del servicio (1-10):\n");
    do
    {   
        fgets(str,6,stdin);
        clear_if_needed(str);
        ComaAPunto (str);
        sscanf(str,"%f",&nota);
        if ((nota<0)||(nota>10))
        {
            printf("Error. Introducir valor valido\n");
        }
    } while ((nota<0)||(nota>10));
    
    total = totalCuenta(cuentas,mesa);
    
    c->fechayhora=(int) now;
    c->media=nota;
    c->dni=dni; 
    c->total=total;
}

void mediaCamarero(t_comanda *comanda, int totComanda, t_camarero *camarero, int totCamarero)
{
    int dni,cantidad;
    float total;

    printf("\n ** NOTA MEDIA DE LOS CAMAREROS ** \n\n");

	for (int i =0; i< totCamarero; i++)
	{
        dni = camarero[i].dni;
        cantidad=0;
        total=0,0;

		for (int j=0; j<totComanda; j++) 
        {
            if(dni==comanda[j].dni)
            {
                total += comanda[j].media;   
                cantidad++;    
            }
        }
        total= total/cantidad;
        printf("%s %s %.2f\n",camarero[i].nombre, camarero[i].apellido, total);
	}
}