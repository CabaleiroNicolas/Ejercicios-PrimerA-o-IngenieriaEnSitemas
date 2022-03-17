#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "mislibrerias.h"

void Menu()
{
	
	printf("\n\n      MENU");
	printf("\n-------------------");
	
	printf("\n\n-(1) Mayor y Menor");
	printf("\n-(2) Promedio");
	printf("\n-(3) Suma");
	printf("\n-(4) Resta");
	printf("\n-(5) Division");
	printf("\n-(6) Producto");
	printf("\n-(7) Cambiar terna");
	printf("\n-(0) Salir...");
	printf("\n\nEleccion: ");
		
}


main()
{
	int primerNumero = 0;
	int segundoNumero = 0;
	int tercerNumero = 0;
	int eleccion = 0;
	int mayorNumero = 0;
	int menorNumero = 0;
	int suma = 0;
	int resta = 0;
	int multiplicacion = 0;
	float promedio = 0.0;
	float division = 0.0;
	
	
	
	printf("\nIngrese el primer numero: ");
		scanf("%d", &primerNumero);
		
	printf("Ingrese el segundo numero: ");
		scanf("%d", &segundoNumero);
		
	printf("Ingrese el tercer numero: ");
		scanf("%d", &tercerNumero);
	
	do
	{
			
		system("cls");
		Menu();
		scanf("%d", &eleccion);
		system("cls");
	
		if(eleccion > 0 && eleccion <= 7)
		{
		
			printf("\nTerna actual:");
			printf("\n\nPrimer numero: %d", primerNumero);
			printf("\nSegundo numero: %d", segundoNumero);
			printf("\nTercer numero: %d\n\n", tercerNumero);
		}
		
		switch(eleccion)
		{
				case 1:
				{
					printf("\nMayor y Menor:");
					mayorNumero = Mayor(primerNumero, segundoNumero, tercerNumero);
					menorNumero = Menor(primerNumero, segundoNumero, tercerNumero);
					printf("\n\nMayor: %d", mayorNumero);
					printf("\nMenor: %d\n\n", menorNumero);
					break;
				}
				
				case 2:
				{
					printf("\nPromedio:");
					promedio = Promediar(primerNumero, segundoNumero, tercerNumero);
					printf("\n\nEl promedio es = %.2f\n\n", promedio);
					break;
				}
				
				case 3:
				{
					printf("\nSuma:");
					suma = Sumar(primerNumero, tercerNumero);
					printf("\n\n%d + %d = %d\n\n", primerNumero, tercerNumero, suma);
					
					break;
				}
				
				case 4:
				{
					mayorNumero = Mayor(primerNumero, segundoNumero, tercerNumero);
					menorNumero = Menor(primerNumero, segundoNumero, tercerNumero);
					
					printf("Resta:");
					resta = Restar(mayorNumero, menorNumero);
					printf("\n\n%d - %d = %d\n\n", mayorNumero, menorNumero, resta);
					
					break;
				}
				
				case 5:
				{
					mayorNumero = Mayor(primerNumero, segundoNumero, tercerNumero);
					
					printf("Division:");
					division = Dividir(mayorNumero, segundoNumero);
					printf("\n\n%d / %d = %d\n\n", mayorNumero, segundoNumero, division);
					
					break;
				}
				
				case 6:
				{
					printf("Multiplicacion:");
					multiplicacion = Multiplicar(primerNumero, segundoNumero, tercerNumero);
					printf("\n\n%d x %d x %d = %d\n\n",primerNumero, segundoNumero, tercerNumero, multiplicacion);
					
					break;
				}
				
				case 7:
				{
					printf("\nCambio de terna\n");
					printf("\nNueva terna:");
					
					printf("\nIngrese el primer numero: ");
						scanf("%d", &primerNumero);
		
					printf("Ingrese el segundo numero: ");
						scanf("%d", &segundoNumero);
		
					printf("Ingrese el tercer numero: ");
						scanf("%d", &tercerNumero);
						
					printf("\n\nCambio de terna exitoso!\n\n");

					break;	
				}
				
				case 0:
				{
					printf("Saliendo del programa...\n\n");
					
					break;
				}
				
				default:
				{
					printf("\n\nEse numero no existe en el MENU...\n");
					printf("\nPorfavor intentar nuevamente\n\n");
						
				}

		}//switch
		system("pause");
	}//do
	while(eleccion > 0);
	
	
	
}//main

