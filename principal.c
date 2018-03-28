#include "producto.h"
#include "camarero.h"
#include "write_binary.h"
#include "read_binary.h"
#include "utilidades.h"
#include "categoria.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PARAM "admin"

int main (int argc, char *argv[])
{
	setvbuf(stdout, 0, _IONBF, 0);

	int c,n;

	//INICIALIZAMOS LOS ARRAY
	int totalC = totalCamareros();
	t_camarero *camareros = (t_camarero *) malloc(totalC * sizeof(t_camarero));
	LeerCamareros(camareros);

	int totalCat = totalCategorias();
	t_categoria categorias [totalCat];
	LeerCategorias(categorias);

	int totalP = totalProductos();
	t_producto *productos = (t_producto *) malloc(totalP * sizeof(t_producto));
	LeerProductos(productos);
	
	//COMIENZO APLICACION
	printf("\n**Bienvenido al Restaurante**\n");

	if ((argc < 2)||(strcmp(argv[1], PARAM) != 0))
	{
		do
		{
			printf("\n 1. Nueva mesa");
			printf("\n 2. A%cadir a mesa", 164); 	
			printf("\n 3. Imprimir cuenta");
			printf("\n 4. Salir");

			n=introducirOpcion(4);

			switch (n)
			{
				case 1:
				//Anyadir una nueva mesa
				break;

				case 2:
				//Anyadir productos a una mesa ya anyadida
				break;

				case 3:
				//Sacar la cuenta de una mesa determinada
				break;
			}
		} while (n!=4);
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
				printf("\n 3. A%cadir producto", 164); 
				printf("\n 4. Editar producto");
				printf("\n 5. Eliminar producto");
				printf("\n 6. Cambiar clave");
				printf("\n 7. Salir");
			
				n=introducirOpcion(7);
				switch (n)
				{
					case 1:
					MostrarCamareros(camareros, totalC);
					break;

					case 2:
					camareros = (t_camarero *) realloc (camareros, (totalC+1) * sizeof(t_camarero));
					AltaCamarero(&camareros[totalC]);
					totalC++;
					break;

					case 3:	
					productos = (t_producto *) realloc (productos, (totalP+1) * sizeof(t_producto));
					AltaProducto(&productos[totalP],categorias,totalCat);
					totalP++;
					break;

					case 4:
					MostrarProductos(productos, totalP);
					EditarProducto(productos,categorias,totalCat);
					break;

					case 5:
					//eliminar producto
					break;

					case 6:
					cambiarClave();
					break;
				}
			} while (n!=7);
		}
		else
		{
			printf("Clave erronea\n");
		}
	}	
			
	EscribirCamarero(camareros,totalC);
	EscribirProducto(productos,totalP);

	free(camareros);
	free(productos);

	return 0;
}