#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int CalcHoras(int dias)
{
	int horas = 0;
	
	horas = dias*24;
	
	return horas;
}

int CalcMin(int dias)
{
	int minutos = 0;
	
	minutos = (dias*24)*60;
	
	return minutos;
}

int CalcSeg(int dias)
{
	int segundos = 0;
	
	segundos = (dias*24)*60*60;
	
	return segundos;
}

main()
{
	int cantDias = 0;
	
	printf("Ingrese una cantidad de dias mayor a 100: ");
	scanf("%d", &cantDias);
	
	if(cantDias >= 100)
	{
		system("cls");
	
	printf("\nLa cantidad de horas en los %d dias son: %d", cantDias, CalcHoras(cantDias));
	
	printf("\n\nLa cantidad de minutos en los %d dias son: %d", cantDias, CalcMin(cantDias));
	
	printf("\n\nLa cantidad de segundos en los %d dias son: %d", cantDias, CalcSeg(cantDias));
	}
	else
	{
		printf("\n\nLa cantidad de dias ingresados es menor a 100.\n\n");
		system("pause");
	}
	getch();
}
