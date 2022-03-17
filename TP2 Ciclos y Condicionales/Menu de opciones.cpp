
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


main()
{
	
	int numeroSuma = 0, suma=0, resultadoSuma=0;
	int numero = 0;
	float div1=0, div2=0, resultadoDiv=0;
	int multi1=0, multi2=0, resultadoMulti=0;
	int resta1=0, resta2=0, resta3=0, resta4=0, resta5=0, resultadoResta=0;
	
	
	


	
	
	do
	{
			printf("\n\n1 -> Multiplicar dos numeros y ver el resultado.");
		printf("\n2 -> Dividir dos numeros y ver el resultado.");
		printf("\n3 -> Restar cinco numeros y ver el resultado.");
		printf("\n4 -> Sumar N numeros y ver el resultado.");
		printf("\n5 -> Salir del programa.\n");
		printf("\n        Ingrese opcion: ");
		scanf("%d", &numero);
	
	system("cls");
	
		switch(numero)
		{
			case 1 : printf("\nIngrese el primer numero: ");
						scanf("%d", &multi1);
					printf("Ingrese el segundo numero: ");
						scanf("%d", &multi2);
						resultadoMulti = multi1 * multi2;
						system("cls");
						printf("\nEl resultado de la multiplicacion es: %d\n\n", resultadoMulti);
						system("pause");
						system("cls");
					break;
					
	
			case 2 : printf("\nIngrese el primer numero: ");
						scanf("%f", &div1);
					printf("Ingrese el segundo numero: ");
						scanf("%f", &div2);
						resultadoDiv = div1 / div2;
						system("cls");
						printf("\nEl resultado de la division es: %.2f\n\n", resultadoDiv); 
						system("pause");
						system("cls");
					break;
					
					
			case 3 : printf("\nIngrese el primer numero: ");
						scanf("%d", &resta1);
					printf("Ingrese el segundo numero: ");
						scanf("%d", &resta2);
					printf("Ingrese el tercer numero: ");
						scanf("%d", &resta3);
					printf("Ingrese el cuarto numero: ");
						scanf("%d", &resta4);
					printf("Ingrese el quinto numero: ");
						scanf("%d", &resta5);			
						resultadoResta = resta1 - resta2 - resta3- resta4 - resta5;
						system("cls");
						printf("\nEl resultado de la resta es: %d\n\n", resultadoResta);
						system("pause");
						system("cls");
					break;	
					
					
			case 4 : printf("\nCuantos numeros quiere sumar?: ");	
					 scanf("%d", &numeroSuma);
					 
					 for(int i = 1; i <= numeroSuma; i++)
					 {
					 	printf("\nIngrese numero %d: ", i);
					 	scanf("%d", &suma);
					 	resultadoSuma = resultadoSuma + suma;
					 }
					 	system("cls");
					 	printf("\nEl resultado de la suma es: %d\n\n", resultadoSuma);
					 	system("pause");
					 	system("cls");
					break;
				
				
			
	
		}
			
	}while(numero < 5);
	
	
}
