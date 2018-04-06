#include "comanda.h"
#include "utilidades.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void AltaComanda(t_comanda *c,int dni)
{
	char str [3];
	time_t now;

    now = time(0);
	c->fechayhora=(int) now;
    
    printf("Nota media del servicio: \n");
	fgets(str,6,stdin);
	clear_if_needed(str);
	sscanf(str,"%f",&c->media);
    
    c->dni; 

    //getTotal() y asignarle a c
}