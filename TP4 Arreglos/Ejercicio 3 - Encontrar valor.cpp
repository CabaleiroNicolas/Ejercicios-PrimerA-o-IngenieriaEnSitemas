#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

const int TAMANO = 50;

int CargaVector(float vec[TAMANO])
{
	int i = 0;
	float numero = 0.0;
	
	printf("\nIngrese numeros (0 para finalizar)");
	printf("\nNumero: ");
	scanf("%f", &numero);
	
	
	while(numero != 0)
	{
		vec[i] = numero;
		i++;
		
		printf("Numero: ");
		scanf("%f", &numero);
	}
	return i;
}



void MostrarVector(float vec[TAMANO], int n)
{
	printf("\nVector:");
	for(int i = 0; i < n; i++)
	{
		printf(" %.2f  ", vec[i]);
		
	}
	
}


int BuscarValor(float vec[TAMANO], int n, int target)
{
	int valoresTarget = 0;
	
	for(int i = 0; i < n; i++)
	{
		if(vec[i] == target)
		{
			valoresTarget++;
		}	
	}
	return valoresTarget;
}

main()
{	
	float vector[TAMANO] = {0};
	int n = CargaVector(vector);
	float target = 0.0;
	int veces = 0;
	
	system("cls");
	
	
	printf("\nSe ingresaron %d numeros reales al vector\n", n);
	
	MostrarVector(vector, n);
	
	printf("\n\nIngrese valor a buscar en el vector: ");
	scanf("%f", &target);
	
	veces = BuscarValor(vector, n, target);
		
	if(veces > 0)
	{
		printf("\nCantidad de veces que el %.2f esta en el vector: %d\n\n", target, veces);
	}
	else
	{
		printf("\nvalor ingresado no se encuentra en la lista de valores ingresados...\n\n");
	}
	
	system("pause");
}

