#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

int sexo = 0;
int edad = 0;
int patologia = 0;

int totalEncuestados = 0;
int varonesGripeA = 0;

int mujeres = 0;
float porcentajeMujeres = 0;


int main()
{
	
printf("\nIngrese edad (0 para finalizar): ");
scanf("%d" ,&edad);

		while ( edad != 0 )	{
	
		printf ("\nIngrese sexo: ");
		scanf("%d", &sexo);
		
		printf("\nIngrese patologia: ");
		scanf("%d", &patologia);
		
		totalEncuestados++;
		
			if (sexo == 2)
			{
			mujeres++;
			}
		
			if ((sexo == 1) && (patologia == 2))
			{
			varonesGripeA++;
			}
		
			system("cls");
		
			printf("\nIngrese edad (0 para finalizar): ");
			scanf("%d" ,&edad);
		
		
	}
		system("cls");
		if (totalEncuestados > 0){
		
		printf("\nTotal de pacientes encuestados: %d", totalEncuestados);
		
		printf("\n\nVarones con gripe A: %d", varonesGripeA);
		
		porcentajeMujeres = (float) mujeres * 100 / totalEncuestados;
		
		printf("\n\nPorsentaje de mujeres encuestadas: %.2f\n\n", porcentajeMujeres);
	}
		else
		{
		printf("-------------------------------");
		printf("\n\n");
		printf("No se encustaron pacientes\n\n");
		printf("-------------------------------\n\n");
}
	
	
	
	system("pause");
}
