#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

int numero = 0;
int ultimoNumero = 0;
int n = 0;
int i = 1;

main()
{
	printf("\nIngrese cantidad de valores: ");
	scanf("%d", &numero);
	system("cls");
	
	
	
while(numero >= i)
	{
	printf("\n\nIngrese el valor %d de %d de 3 cifras: ", i, numero);
	scanf("%d", &n);
		i++;
		
		if((n >= 100) && (n <= 999))
		{
		ultimoNumero = n % 10;
		printf("La ultima cifra de %d es: %d", n, ultimoNumero);	
		}
			else
			{
			printf("\nEl numero no tiene 3 cifras\n\n");
			system("pause");
			}
	} 
	getch();
}
