#include <stdio.h>
#include <stdlib.h>


const int SUCURSALES = 2;
const int PRODUCTOS = 2;
const int PAISES = 3;

void CargarMatriz(int mat[PAISES][SUCURSALES][PRODUCTOS])
{
	for(int p = 0; p < PAISES; p++)
	{
		printf("\n");

		for(int f = 0; f < SUCURSALES; f++)
		{
		
			for(int c = 0; c < PRODUCTOS; c++)
			{
				printf("venta de producto %d de sucusal %d y pais %d: ", c+1, f+1, p+1);
			
				scanf("%d", &mat[p][f][c]);
				
			}
		}
	}
}



int PaisQueMasVendio(int mat[PAISES][SUCURSALES][PRODUCTOS])
{
	int pais = 0;
	int max = -100000;
	
	int suma = 0;
	
	
	for(int p = 0; p < PAISES; p++)
	{
		suma = 0;

		for(int f = 0; f < SUCURSALES; f++)
		{
		
			for(int c = 0; c < PRODUCTOS; c++)
			{
				suma = suma + mat[p][f][c];
				
			}
			
			if(suma > max)
			{
				max = suma;
				
				pais = p;
			}
		}
	}
	
	return pais;
}



void VentaSucursales(int mat[PAISES][SUCURSALES][PRODUCTOS])
{
	for(int p = 0; p < PAISES; p++)
	{
		
		printf("Ventas pais %d:\n\n",p+1);

		for(int f = 0; f < SUCURSALES; f++)
		{
			
			printf("Sucursal %d:", f+1);
			for(int c = 0; c < PRODUCTOS; c++)
			{
				printf(" %d,", mat[p][f][c]);
				
			}
			
			printf("\n");
		}
		
		printf("\n\n\n");
	}	
}



main()
{
	int matriz[PAISES][SUCURSALES][PRODUCTOS];
	
	int mejorPais = 0;
	
	
	CargarMatriz(matriz);
	
	system("cls");
	
	mejorPais = PaisQueMasVendio(matriz);
	
	printf("\nEl pais que mas vendio fue el numero =>%d<=", mejorPais+1);
	
	printf("\n\n\n");
	
	VentaSucursales(matriz);
	
	printf("\n\n\n");
	system("pause");
	
}









