#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void Multiplo(int n)
{
   int resultado = 0;
	
	for (int i = 1; i <= 10; i++)
	{
		resultado = n * i;
		printf("%d x %d = %d\n",n, i, resultado);
	}
}

void SubMultiplo(int n)
{
	int resultado = 0;
	int resto = 0;
	
	for (int i = 1; i <= n; i++)
	{
		resultado = n / i;
		resto = n % i;
		
		if(resto == 0)
		{
			printf("%d / %d = %d\n", n, i, resultado);
		}
	}
	
}


main()
{
	int valores = 0;
	int numero = 0;
	
	printf("Ingrese valores a calcular: ");
	scanf("%d", &valores);
	
	system("cls"); 
	 
	for (int i = 1; i <= valores; i++)
	{
		printf("\nNumero %d de %d: ",i ,valores);
		scanf("%d", &numero);
		
		system("cls");
		
		
			if ((numero > 0) && (numero < 150))
			{
				Multiplo(numero);
			}
	
			if((numero >= 150) && (numero < 301))
			{
				SubMultiplo(numero);
			}
		
	}
	
	
	system("pause");
}
