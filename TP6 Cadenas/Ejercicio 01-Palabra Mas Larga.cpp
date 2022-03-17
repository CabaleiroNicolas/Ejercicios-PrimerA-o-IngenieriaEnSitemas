#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
	typedef char cadena[30];
	
	cadena palabra;
	cadena palabraMasLarga;
	
	
	int comparacion = 0;
	int cantidadPalabras = 0;
	int longitudPalabra = 0;
	int longitudMaxima = 0;
	
	printf("\nIngrese palabras ('final' para finalizar)\n: ");
	
		_flushall();
		gets(palabra);
		strlwr(palabra);
		
		comparacion = strcmp(palabra, "final");

	while(comparacion != 0)
	{
		cantidadPalabras++;
		
		longitudPalabra = strlen(palabra);
		
		if(longitudPalabra > longitudMaxima)
		{
			strcpy(palabraMasLarga, palabra);
			longitudMaxima = longitudPalabra;
			
		}
		
		printf(": ");
	
		_flushall();
		gets(palabra);
		strlwr(palabra);
		
		comparacion = strcmp(palabra, "final");
		
	}
	
	system("cls");
	
	printf("\nSe ingresaron %d palabras", cantidadPalabras);
	
	printf("\n\n");
	
	printf("La palabra mas larga fue: => %s <= con %d letras", palabraMasLarga, longitudMaxima);
	
	
	printf("\n\n\n");
	system("pause");
}
