#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void Intervalo (int valor1, int valor2, int N)
{
	int valoresDentro = 0;
	int valoresFuera = 0;
	int numero = 0;
	
	
	for (int i = 1; i <= N; i++)
	{
		printf("\nNumero %d de %d: ",i, N);
		scanf("%d", &numero);
		
		system("cls");
	
		if( (numero >= valor1) && (numero < valor2) )
		{
		valoresDentro++;
		}
			else
			{
			valoresFuera++;
			}

	}
	system("cls");
	printf("\nLa cantidad dentro del inervalo es: %d", valoresDentro);
	printf("\n\nLa cantidad fuera del inervalo es: %d\n\n\n", valoresFuera);
	printf("_______________________________________\n\n");
}

main()
{

	int a;
	int b;
	int n;


	printf("Ingrese el menor valor del intervalo: ");
	scanf("%d", &a);
	
	printf("\nIngrese el mayor valor del intervalo: ");
	scanf("%d", &b);
	
	printf("\nIngrese cuantos valores usara: ");
	scanf("%d", &n);
	
	system("cls");
	
	Intervalo (a, b, n);
	
	
	
	system("pause");
}
