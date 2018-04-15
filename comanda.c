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
    
    c->fechayhora=(int)now;
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
        printf(" %s %s %.2f\n",camarero[i].nombre, camarero[i].apellido, total);
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
     
    linea();
    printf("\n  ** PRECIO MEDIO GASTADO POR MESA ** \n\n");
        
    total=0,0;

    for (int i =0; i<totComanda; i++)
    {
        total+=comanda[i].total;

    }
    precio= total/totComanda;

    printf("\n  HAN GASTADO UNA MEDIA DE %.2f POR MESA \n", precio );
    linea();
}

void mediaServicio (t_comanda *comanda, int totComanda)
{
    
    float total, media;
     
    linea();
    printf("\n  ** MEDIA DEL SERVICIO DEL RESTAURANTE ** \n\n");
        
    
    total=0,0;

    for (int i =0; i<totComanda; i++)
    {
        total+=comanda[i].media;
        
    }
    media= total/totComanda;

    printf(" La valoracion del servicio por parte de los \n cliente ha logrado un %.2f/10 de media \n", media );
    linea();
}

void importeXmes (t_comanda *comanda, int totComanda)
{
    float total=0;
    int mes1,mes2;

    time_t now,fecha;
    struct tm *tm;
    char * meses [12] = {"ENERO","FEBRERO","MARZO","ABRIL","MAYO","JUNIO","JULIO","AGOSTO","SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"};

    now = (time_t) comanda[totComanda].fechayhora;
    tm = localtime (&now); 
    mes1 = tm->tm_mon;

    linea();
    printf("\n   ** INGRESOS POR MES ** \n\n\n");
    for (int i=totComanda;i>0;i--)
    {
        fecha = (time_t) comanda[i].fechayhora;
        tm = localtime (&fecha);
        mes2 = tm->tm_mon;
         
        if (mes2==mes1)
        {
            total = total + comanda[i].total;
        }
        else
        {
            printf(" - %s %04d %.2f \n",meses[mes2],tm->tm_year+1900,total);
            mes1=mes2;
            total=0;
        }
    }
    printf(" - %s %04d %.2f \n",meses[mes2],tm->tm_year+1900,total); //ultimo mes

    linea();

}

void PrecioMedioProductosxCategoria (t_producto p[],int totalP,t_categoria c[],int totalCat)
{
    int cant;
    float med, precioTot;

    linea();

    printf("\n   ** PRECIO MEDIO DE PRODUCTOS POR CATEGORIA ** \n\n");
    
    for (int i =0; i < totalCat; i ++)
    {
        med=0;
        cant=0;
        precioTot=0;

        for (int j =0; j<totalP; j ++)
        {
            if ( strcmp(c[i].nombre,p[j].categoria)==0)
            {
                precioTot += p[j].precio;
                cant++;
            }
        }
        med = precioTot/cant;
        printf (" %s : %.2f%c \n",c[i].nombre,med,36);
    }

    linea();
}