#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void CargarVector(int vec[50], int n)
{
	printf("\nIngrese vector:\n\n");
	
	for(int i = 0; i < n; i++)
	{
		printf("vec[%d]: ", i);
		scanf("%d", &vec[i]);
	
	}

}



void MostrarVector(int vec[50], int n)
{
	
	for(int i = 0; i < n; i++)
	{
		printf(" %d  ", vec[i]);
	}
}



void BurbujaAscendente(int vec[50], int n)
{
	int aux = 0;
	int L = n-1;
	bool bandera = false;
	

	do
	{
		
		bandera = false;
		for(int i = 0; i < L; i++)
		{
			if(vec[i] > vec[i+1])
			{
				aux = vec[i];
				vec[i] = vec[i+1];
				vec[i+1] = aux;
				
				bandera = true;
			}	
		}
			L--;
	}while(bandera == true);

}




void BurbujaDescendente(int vec[50], int n)
{
	int aux = 0;
	int L = n-1;
	bool bandera = false;
	

	do
	{
		
		bandera = false;
		for(int i = 0; i < L; i++)
		{
			if(vec[i] < vec[i+1])
			{
				aux = vec[i];
				vec[i] = vec[i+1];
				vec[i+1] = aux;
				
				bandera = true;
			}	
		}
			L--;
	}while(bandera == true);

}
main()
{
	int vector[50] = {0};
	int n = 0;
	
	printf("\nIngrese tamaño del vector: ");
	scanf("%d", &n);
	
	CargarVector(vector, n);
	
	system("cls");
	
	printf("\nVector desordenado: \n\n");
	MostrarVector(vector , n);
	
	
	BurbujaAscendente(vector, n);
	printf("\n\n\nVector ordenado de manera Ascendente: \n\n");
	MostrarVector(vector, n);
	
	BurbujaDescendente(vector, n);
	printf("\n\n\nVector ordenado de manera Descendente: \n\n");
	MostrarVector(vector, n);
	
	
	printf("\n\n");
	system("pause");
}
