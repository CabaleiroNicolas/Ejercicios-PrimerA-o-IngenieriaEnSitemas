#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

main()
{
	int numero = 0;
	int menor25 = 0;
	int mayor12 = 0;
	int entre19y28 = 0;
	
	printf("\nIngrese un numero (cero para finalizar): ");
	scanf("%d", &numero);
	
	do
	{
		if(numero < 25)
		{
			menor25++;
		}
		
		if(numero > 12)
		{
			mayor12++;	
		}
		
		if((numero > 19)&&(numero < 28))
		{
			entre19y28++;
		}
		
		system("cls");
		printf("\nIngrese un numero (cero para finalizar): ");
		scanf("%d", &numero);
		

	}while(numero > 0);
	
	printf("\nNumeros menores que 25: %d", menor25);
	printf("\nNumeros mayores que 12: %d", mayor12);
	printf("\nNumeros entre 19 y 28: %d", entre19y28);
	
	
	
	getch();
}
