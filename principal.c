#include "producto.h"
#include "camarero.h"
#include "write_binary.h"
#include "read_binary.h"
#include "utilidades.h"
#include "categoria.h"
#include "comanda.h"
#include "cuenta.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PARAM "admin"
#define MESAS 20
#define POSICIONES 50 //dimension bertical array multidimensional

int main (int argc, char *argv[])
{
	setvbuf(stdout, 0, _IONBF, 0);

	int c,n,m,dni,mesa;

	int **cuentas;

	//INICIALIZAMOS LOS ARRAY
	int totalC = totalCamareros();
	t_camarero *camareros = (t_camarero *) malloc(totalC * sizeof(t_camarero));
	LeerCamareros(camareros);

	int totalCat = totalCategorias();
	t_categoria *categorias = (t_categoria *) malloc (totalCat * sizeof (t_categoria));
	LeerCategorias(categorias);

	int totalP = totalProductos();
	t_producto *productos = (t_producto *) malloc(totalP * sizeof(t_producto));
	LeerProductos(productos);

	cuentas = (int **) malloc (MESAS * sizeof (int*));
	for (int i= 0; i<MESAS; i++)
	{
		cuentas[i] = (int*) malloc (POSICIONES *sizeof (int));
		cuentas[i][0] = 0; 
	}

	int totalCom = totalComandas();
	t_comanda *comandas = (t_comanda *) malloc(totalCom * sizeof(t_comanda));
	LeerComandas(comandas);
	
	//COMIENZO APLICACION
	printf("\n **Bienvenido al Restaurante** \n");

	if ((argc < 2)||(strcmp(argv[1], PARAM) != 0))
	{
		dni = getCamarero(camareros,totalC);

		if (dni!=0)
		{
			do
			{
				printf("\n 1. Nueva comanda"); 	
				printf("\n 2. A%cadir a comanda",164);
				printf("\n 3. Imprimir cuenta");
				printf("\n 4. Salir");

				n=introducirOpcion(4);

				switch (n)
				{
					case 1:
					mesa = getNumeroMesa(MESAS);
					if (MesaOcupada(cuentas,mesa,1)==0)
					{
						AtenderMesa(cuentas,mesa,productos,totalP,categorias,totalCat);
					}
					break;

					case 2:
					mesa = getNumeroMesa(MESAS);
					if (MesaOcupada(cuentas,mesa,0)==1)
					{
						AtenderMesa(cuentas,mesa,productos,totalP,categorias,totalCat);
					}
					break;

					case 3:
					mesa=getNumeroMesa(MESAS);
					if (MesaOcupada(cuentas,mesa,0)==1)
					{
						comandas = (t_comanda *) realloc (comandas, (totalCom+1) * sizeof(t_comanda));
						AltaComanda(&comandas[totalCom],dni, cuentas, mesa,productos,totalP);
						totalCom++;

						ImprimirCuenta(productos,totalP, cuentas, mesa);
						for (int i=0;i<POSICIONES;i++)
						{
							cuentas[mesa][i]=0;
						}
					}
					break;
				}
			} while (n!=4);
		}
	}
	else
	{
		c = comprobarClave();
				
		if (c==0)
		{
			do
			{
				printf("\n 1. Consultar estad%csticas",161);
				printf("\n 2. A%cadir camarero", 164);
				printf("\n 3. A%cadir categoria", 164);
				printf("\n 4. A%cadir producto", 164); 
				printf("\n 5. Editar producto");
				printf("\n 6. Eliminar producto");
				printf("\n 7. Cambiar clave");
				printf("\n 8. Salir");
			
				n=introducirOpcion(8);
				switch (n)
				{
					case 1:
					do
					{
						printf("\n 1. Lista de los camareros");
						printf("\n 2. Nota media camareros");
						printf("\n 3. Actividad camareros"); 
						printf("\n 4.");
						printf("\n 5.");
						printf("\n 6.");
						printf("\n 7.");
						printf("\n 8. Salir");
						m = introducirOpcion(8);
						switch(m)
						{
							case 1:
							MostrarCamareros(camareros,totalC);
							break;

							case 2:
							mediaCamarero(comandas,totalCom, camareros,totalC);
							break;

							case 3:
							actividadCamarero(comandas,totalCom,camareros,totalC);
							break;
							//...
						}
					}while(m!=8);
					break;

					case 2:
					camareros = (t_camarero *) realloc (camareros, (totalC+1) * sizeof(t_camarero));
					AltaCamarero(&camareros[totalC],camareros,totalC);
					totalC++;
					break;

					case 3:
					categorias = (t_categoria *) realloc (categorias, (totalCat+1) * sizeof(t_categoria));
					AltaCategoria(&categorias[totalCat],categorias,totalCat);
					totalCat++;
					break;

					case 4:	
					productos = (t_producto *) realloc (productos, (totalP+1) * sizeof(t_producto));
					AltaProducto(&productos[totalP],totalP,categorias,totalCat);
					totalP++;
					break;

					case 5:
					MostrarProductos(productos,totalP);
					EditarProducto(productos,totalP,categorias,totalCat);
					break;

					case 6:
					MostrarProductos(productos,totalP);
					EliminarProducto(productos,totalP);
					totalP--;
					productos = (t_producto *) realloc (productos, (totalP) * sizeof(t_producto));
					break;

					case 7:
					cambiarClave();
					break;
				}
			} while (n!=8);
		}
	}	
			
	EscribirCamarero(camareros,totalC);
	EscribirCategoria(categorias,totalCat);
	EscribirProducto(productos,totalP);
	EscribirComanda (comandas, totalCom);

	free(camareros);
	free(categorias);
	free(productos);
	free(comandas);

	camareros=0;
	categorias=0;
	productos=0;

	return 0;
}