#include <stdlib.h>
#include <conio.h>
#include <stdio.h>



void AlCuadrado(int numero ,int resultado)
{
	
	resultado = numero * numero;
}


int main ()
{
	int s;
	int a = 0;
	
	
	printf("Ingrese un valor para obtener su cuadrado: ");
	scanf("%d", &a);
	
	AlCuadrado(a, s);
	system("cls");
	
	printf("EL cuadrado de %2.d es:%2.d",a, s);
	
	getch();
}


