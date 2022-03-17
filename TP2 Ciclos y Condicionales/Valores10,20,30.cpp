#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

main()
{
int num30 = 0;
int num20 = 0;
int num10 = 0;
int num = 0;
int numDistinto = 0;
	
	printf("\n\nIgrese un valor (-1 para terminar): ");
	scanf("%d" ,&num);
	
	while (num >= 0)
	{
	
			if((num != 30)&&(num != 20)&&(num != 10))
		{
			numDistinto++;
		}
			if(num == 30)
		{
			num30++;	
		}
			if(num == 20)
		{
			num20++;
		}
			if(num == 10)
		{
			num10++;
		}
	
		printf("\nIngrese un valor (-1 para terminar): ");
		scanf("%d" ,&num);
	}
	system("cls");
	
	printf("\nValores 30 ingresados: %d", num30);
	printf("\nValores 20 ingresados: %d", num20);
	printf("\nValores 10 ingresados: %d", num10);
	printf("\n\nValores distintos a 10, 20 y 30 ingresados: %d\n\n", numDistinto);
	
	system("pause");
}
