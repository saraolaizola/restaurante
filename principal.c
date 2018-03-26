#include "producto.h"
#include "camarero.h"
#include "write_binary.h"
#include "read_binary.h"
#include "utilidades.h"
#include "categoria.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 2

int main (void)
{
	setvbuf(stdout, 0, _IONBF, 0);

	char str [MAX_LEN];
	int n, opcion,c;
	
	int totalC = totalCamareros();
	t_camarero *camareros = (t_camarero *) malloc(totalC * sizeof(t_camarero));
	LeerCamareros(camareros);

	int totalCat = totalCategorias();
	t_categoria categorias [totalCat];
	LeerCategorias(categorias);

	int totalP = totalProductos();
	t_producto *productos = (t_producto *) malloc(totalP * sizeof(t_producto));
	LeerProductos(productos);

	printf("Bienvenido al Restaurante\n");

	do 
	{
		printf("\n 1. Administrador");
		printf("\n 2. Camarero");
		printf("\n 3. Salir");

		printf("\n\n Introduzca opci%cn (1-3): ",162);
		fgets(str,MAX_LEN,stdin);
		clear_if_needed(str);
		sscanf(str,"%d",&opcion);

		switch (opcion)
		{
			case 1:
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
					
						printf("\n\n Introduzca opci%cn (1-7): ",162);
						fgets(str,MAX_LEN,stdin);
						sscanf(str,"%d",&n);
						clear_if_needed(str);

						switch (n)
						{
							case 1:
							MostrarCamareros(&camareros[0], totalC);
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
				break;

			case 2:
				do
				{
					printf("\n 1. Nueva mesa");
					printf("\n 2. A%cadir a mesa", 164); 	
					printf("\n 3. Imprimir cuenta");
					printf("\n 4. Salir");

					printf("\n\n Introduzca opci%cn (1-4): ",162);
					fgets(str,MAX_LEN,stdin);
					clear_if_needed(str);
					sscanf(str,"%d",&n);

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
			break;
		}
	} while (opcion!=3);

	EscribirCamarero(camareros,totalC);
	//EscribirProducto(productos,totalP);

	//free(camareros);
	//free(productos);

	return 0;
}