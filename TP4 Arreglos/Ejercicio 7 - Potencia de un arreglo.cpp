#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

const int TAMANO = 10;
const int MIN = 1;
const int MAX = 10;


//---------------------------------------------------------------------------
void GenerarVectorAleatorio(int vec[TAMANO])//GENERAR VECTOR ALEATORIO
{
	for(int i = 0; i<TAMANO; i++)
	{	
		vec[i] = MIN + rand() % (MAX + 1 - MIN);	
	}	
}


//---------------------------------------------------------------------------
void MostrarVector(int vec[TAMANO])//MOSTRAR VECTOR
{	
	
	for(int i = 0; i < TAMANO; i++)
	{
		printf(" %d  ", vec[i]);
		
	}	
}


//---------------------------------------------------------------------------
void PotenciaDeA(int vecA[TAMANO], int vecB[TAMANO])//POTENCIA DE A
{
	
	for(int i = 0; i < TAMANO; i++)
	{
		vecB[i] = pow(vecA[i], i);
	
	}	
}


//---------------------------------------------------------------------------
void SumaVectorAyB(int vecA[TAMANO], int vecB[TAMANO], int vecC[TAMANO])//SUMA VECTOR A Y B
{

	for(int i = 0; i < TAMANO; i++)
	{
		vecC[i] = vecA[i] + vecB[i];
	
	}	
}


//---------------------------------------------------------------------------
main()
{
	int vectorA[TAMANO] = {0};
	int vectorB[TAMANO] = {0};
	int vectorC[TAMANO] = {0};
	
	srand(time(NULL));
	
//---------------------------------------------------------------------------	
	GenerarVectorAleatorio(vectorA);
	printf("\nVectorA: \n");
	MostrarVector(vectorA);
	
//---------------------------------------------------------------------------	
	PotenciaDeA(vectorA, vectorB);
	printf("\n\n\nVectorB: \n");
	MostrarVector(vectorB);
	
//---------------------------------------------------------------------------	
	SumaVectorAyB(vectorA, vectorB, vectorC);
	printf("\n\n\nVectorC: \n");
	MostrarVector(vectorC);
	
//---------------------------------------------------------------------------
	printf("\n\n\n");
	system("pause");
}



