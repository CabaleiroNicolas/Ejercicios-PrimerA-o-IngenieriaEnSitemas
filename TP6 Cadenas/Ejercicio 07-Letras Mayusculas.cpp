#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char cadena[100];

main()
{
	cadena frase;
	
	int longitud = 0;
	int mayusculas = 0;
	
	printf("\Ingrese una Frase (max. 100 caracteres)\n\n: ");
	_flushall();
	gets(frase);
	longitud = strlen(frase);
	
	if(longitud <= 100)
	{
		for(int i = 0; i < longitud; i++)
		{
			if(frase[i] >= 'A' &&  frase[i] <= 'Z')
			{
				mayusculas++;
			}
			
		}
		system("cls");
		printf("\nLa frase: %s", frase);
		printf("\n\nContiene '%d' Letras Mayusculas", mayusculas);
			
	}
	else
	{
		printf("\nLa frase no puede contener mas de 100 caracteres...");
	}
	
	
	printf("\n\n");
	system("pause");
}
