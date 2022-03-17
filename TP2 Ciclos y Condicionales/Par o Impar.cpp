#include <stdlib.h>
#include <conio.h>
#include <stdio.h>




int main ()
{
	
int valor = 0;
int valorPar = 0;
int valorImpar = 0;

	printf("\nIngrese un valor entero (0 para finalizar): ");
	scanf("%d", &valor);
	
	while(valor != 0)
	{
	
	if(valor%2 == 0)
	{
	valorPar = valorPar + valor;
	printf("\nIngrese un valor entero (0 para finalizar): ");
	scanf("%d", &valor);
	}
	else 
	{
	valorImpar = valorImpar + valor;
	
	printf("\nIngrese un valor entero (0 para finalizar): ");
	scanf("%d", &valor);
	}
	
}
system("cls");
	printf("______________________________________________________");
	printf("\n\nSuma de valores par: %d", valorPar);
	printf("\n\nSuma de valores impar: %d\n\n", valorImpar);
	printf("______________________________________________________\n\n");
	
	system("pause");
	
}


