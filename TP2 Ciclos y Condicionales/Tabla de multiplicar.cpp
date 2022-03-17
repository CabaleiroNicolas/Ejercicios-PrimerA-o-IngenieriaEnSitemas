#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

main()
{
	int numero = 0;
	int multiplicacion = 0;
	
	printf("\nIngrese un numero del 1 al 10: ");
	scanf("%d",&numero);
	
	while((numero >= 1)&&(numero <= 10))
	{
		for(int i = 1; i <= 10; i++)
		{
	
			multiplicacion = numero * i;
			printf("\n%d x %d = %d", numero, i, multiplicacion);
		}
		
		
		printf("\n\nIngrese un numero del 1 al 10: ");
		scanf("%d",&numero);
	}
	
}
