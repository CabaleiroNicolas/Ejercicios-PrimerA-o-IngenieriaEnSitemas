#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int Cuadrado(int numero)
{
	int cuadrado = 0;
	int impar = 1;
	
	for (int i = 1; i <= numero; i++)
	{
		cuadrado = cuadrado + impar;
		impar = impar + 2;	
	}
	
	return cuadrado;
}



main()
{
	int num = 0;
	
	
	printf("Ingrese un numero entero: ");
	scanf("%d", &num);
	
	
	printf("\n\nEl cuadrado de %d es : %d",num ,Cuadrado (num));	
	
	getch();
}
