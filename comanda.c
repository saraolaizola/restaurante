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


void AltaComanda(t_comanda *c,int dni, int **cuentas, int mesa, t_producto *p,int totalP)
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
        nota = pedirFloat();
        if ((nota<0)||(nota>10))
        {
            printf("Error. Introducir valor valido\n");
        }
    } while ((nota<0)||(nota>10));
    
    total = totalCuenta(cuentas,mesa,p,totalP);
    
    c->fechayhora=(int) now;
    c->media=nota;
    c->dni=dni; 
    c->total=total;
}

void mediaCamarero(t_comanda *comanda, int totComanda, t_camarero *camarero, int totCamarero)
{
    int dni,cantidad;
    float total;

    linea();
    printf("\n   ** NOTA MEDIA DE LOS CAMAREROS ** \n\n");

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
        printf(" - %s %s %.2f\n",camarero[i].nombre, camarero[i].apellido, total);
	}
    linea();
}

void actividadCamarero (t_comanda *comanda, int totComanda, t_camarero *camarero, int totCamarero)
{
    int dni,cantidad;
    float total;

    linea();
    printf("\n  ** ACTIVIDAD DE LOS CAMAREROS ** \n");
    printf(" (Camarero/Num.Comandas/Imp.Total)\n\n");


    for (int i =0; i< totCamarero; i++)
    {
        dni = camarero[i].dni;
        cantidad=0;
        total=0,0;

        for (int j=0; j<totComanda; j++) 
        {
            if(dni==comanda[j].dni)
            {
                total += comanda[j].total;   
                cantidad++;    
            }
        }
        printf(" %s %s  x%d  %.2f%c\n",camarero[i].nombre, camarero[i].apellido,cantidad,total,36);
    }
    linea();
}

void valorMedioComandas (t_comanda *comanda, int totComanda)
{
    
    float total, precio;
     

    printf("\n  ** PRECIO MEDIO GASTADO POR CLIENTES ** \n");
        
    
    total=0,0;

    for (int i =0; i<totComanda; i++)
    {
        total+=comanda[i].total;
        


    }
    precio= total/totComanda;

    printf("Los clientes han gastado una media de %.2f por mesa \n", precio );
}