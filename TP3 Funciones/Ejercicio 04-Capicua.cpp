#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


void Capicua(int numero, int &capicua, int aux)
{		
	
	int resto = 0;
	
		
	while (numero > 0)
	{
		aux = numero;
		
		resto = aux % 10;
		numero = numero / 10;
		capicua = capicua * 10 + resto;
	}
}



main()
{
	int numero = 0;
	int capicua = 0;
	int aux = 0;
	
	printf("Ingrese un numero de 5 cifras: ");
	scanf("%d", &numero);
	
	Capicua(numero, capicua, aux);
	
	if(capicua == aux)
	{
		printf("Es capicua");
	}
	else
	{
		printf("No es capicua");
	}
}
