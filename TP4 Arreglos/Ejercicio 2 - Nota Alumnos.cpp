#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void CargarNotas(int vec[50], int n)
{
	int verifica = 0;
	
	for(int i = 0; i < n; i++)
	{
		printf("\nIngrese nota del alumno %d: ", i+1);
		scanf("%d", &verifica);
		
		
		while((verifica > 10) || (verifica < 1))
		{
			
			printf("\nLa nota no puede ser mayor a 10 ni menor a 1...\n\n");
			printf("\nIngrese nuevamente nota del alumno %d: ", i+1);
			scanf("%d", &verifica);
			system("cls");
			
		}//while
		vec[i] = verifica;
	}//for	
}//funcion

void MayorYMenorNota(int vector[50], int n, int &mayor, int &menor)
{	
	for(int i = 0; i < n; i++)
	{
		if(vector[i] < menor)
		{
			menor = vector[i];
		}//if
		
		if(vector[i] > mayor)
		{
			mayor = vector[i];
		}//if
	}//for
}//funcion


float PromedioNotas(int vector[50], int n)
{
	float promedio = 0.0;
	int suma = 0;
	
	for(int i = 0; i < n; i++)
	{
		suma = suma + vector[i];
	}//for
	promedio = (float)suma / n;
	
	return promedio;
}//funcion


int SuperiorPromedio(int vector[50],float vecPromedio, int n)
{
	int mayorAlPromedio = 0;
	
	for(int i = 0; i < n; i++)
	{
		if(vector[i] > vecPromedio)
		{
			mayorAlPromedio++;
		}//if	
	}//for
	return mayorAlPromedio;
}//funcion


void AprobadosDesaprobados(int vector[50], int n, int &aprobados, int &desaprobados)
{

	for(int i = 0; i < n; i++)
	{
		if(vector[i] >= 6)
		{
			aprobados++;
		}//if
		else
		{
			desaprobados++;
		}//else
	}//for
}//funcion


void MostrarNotas(int vector[50], int n)
{
	
	for(int i = 0; i < n; i++)
	{
		printf(" %d  ", vector[i]);
	}
		
}

main()
{
	int vectorNotas[50] = {0};
	int alumnos = 0;
	
	int mayor = 0;
	int menor = 1000;
	
	int aprobados = 0;
	int desaprobados = 0;
	
	
	printf("\nIngrese cantidad de alumnos: ");
	scanf("%d", &alumnos);
	
	CargarNotas(vectorNotas, alumnos);
	
	system("cls");
	
	printf("\n\nNotas:");
	MostrarNotas(vectorNotas, alumnos);
	printf("\n--------------------------------------");
	
	
	MayorYMenorNota(vectorNotas, alumnos, mayor, menor);
	
	printf("\n\n\nLa menor nota de los alumnos es: %d", menor);
	printf("\n\nLa mayor nota de los alumnos es: %d", mayor);
	
	printf("\n\nEl promedio de la notas de los alumnos es: %.2f", PromedioNotas(vectorNotas, alumnos));
	
	printf("\n\nLa cantidad de notas mayores al promedio son: %d", SuperiorPromedio(vectorNotas, PromedioNotas(vectorNotas, alumnos), alumnos));
	
	AprobadosDesaprobados(vectorNotas, alumnos, aprobados, desaprobados);
	
	printf("\n\nLa cantidad de alumnos desaprobados es: %d", desaprobados);
	printf("\n\nLa cantidad de alumnos aprobados es: %d\n\n", aprobados);
	
	system("pause");
}

