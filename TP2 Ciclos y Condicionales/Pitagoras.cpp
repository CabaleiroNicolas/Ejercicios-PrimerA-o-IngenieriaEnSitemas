#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

float a = 0;
float b = 0;
float h = 0;
float op = 0; 


	int main ()
	{
		printf("\nQue desea saber?\n");
		printf("\nCateto - presione 1\n");
		printf("\nHipotenusa - presione 2\n\n");
		
		scanf("%f", &op);
	
		while (op>0)
			{
				
				
			if(op==2)
			
			{
			printf("\nIngrese el valor del cateto X: ");
			scanf("%f", &b);
			
			printf("\nIngrese el valor del cateto y: ");
			scanf("%f", &a);
			
				h = sqrt((pow(a,2) + pow(b,2)));
				printf("\n\nLa distania es: %f\n\n", h);
			}
			
					else
					{
					printf("\nIngrese el valor de la hipotenusa: ");
					scanf("%f", &h);
	
					printf("\nIngrese el valor del cateto: ");
					scanf("%f", &b);
					
						a = sqrt((pow(h,2) - pow(b,2)));
						printf("La distancia es: %.2f\n\n", a);
						
					}
				
		}
			printf("\nQue desea saber?\n");
		printf("\nCateto - presione 1\n");
		printf("\nHipotenusa - presione 2\n\n");
		
		scanf("%f", &op);	
	}
		
			
