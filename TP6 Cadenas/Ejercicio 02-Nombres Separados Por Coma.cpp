#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char cadena[100];

void MostrarNombres(cadena nombres)
{
	int longitud = strlen(nombres);
	
	if(longitud == 0)
		{
			printf("La cadena esta vacia");
		}
	
	for(int i = 0; i < longitud; i++)
	{
				
		if(nombres[i] == ',')
		{
			printf("\n");
		}
		else
		{
			printf("%c", nombres[i]);
		}	
	}
}


int LongitudDeCadena(cadena nombres)
{

	int c = 0;
	
	while(nombres[c] != '\0')
	{
		c++;
	}

	return c;
}


main()
{
	
	cadena nombres;
	
	int longitud = 0;
	
	printf("\ningrese nombres separados por coma: \n");
	
	_flushall();
	gets(nombres);
	
	printf("\n");
	
	MostrarNombres(nombres);
	
	printf("\n");
	
	longitud = LongitudDeCadena(nombres);
	
	printf("\nLa longitud de la cadena es de: %d", longitud);
	
	printf("\n\n\n");
	system("pause");
}
