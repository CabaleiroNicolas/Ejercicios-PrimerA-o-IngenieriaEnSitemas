#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MostrarCadenaInvertida(char cadena[120], int longitud)
{
	for(int i = longitud; i >= 0; i--)
	{
		printf("%c", cadena[i]);
	}
}

main()
{
	char cadena[120];
	int longitud = 0;
	
	printf("\nIngrese una cadena (ENTER para Finalizar)\n\n: ");
 	_flushall();
	gets(cadena);
	longitud = strlen(cadena);
	
	if(longitud <= 120)
	{
	
	
		system("cls");
		printf("\nCadena Normal\n\n");
		
		for(int i = 0; i < longitud; i++)
		{
			printf("%c", cadena[i]);
		}
		
		printf("\n\n\nCadena Invertida\n\n");
		
		MostrarCadenaInvertida(cadena, longitud);
		
	}
	else
	{
		printf("\nLa cadena no puede tener mas de 120 caracteres.");
	}
		
	printf("\n\n");
	system("pause");

}



