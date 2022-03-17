#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

//variables
 int main(){
	
	float notaParciales = 0;
	float notaIntegradores = 0;
	float notaTrabajoFinal = 0;

	const float PORCENTAJE_PARCIALES = 0.40;
	const float PORCENTAJE_INTEGRADORES = 0.20;
	const float PORCENTAJE_TRABAJO_FINAL = 0.40;

	float notaFinal = 0;

	printf("\nIngrese la nota de parcial: ");
	scanf("%f", &notaParciales);

	printf("\nIngrese la nota de trabajos integradores: ");
	scanf("%f", &notaIntegradores);

	printf("\nIngrese la nota del trabajo final: ");
	scanf("%f", &notaTrabajoFinal);

	notaFinal = (notaParciales * PORCENTAJE_PARCIALES) +
 	(notaIntegradores * PORCENTAJE_INTEGRADORES) + (notaTrabajoFinal * PORCENTAJE_TRABAJO_FINAL);
 
 	system("cls");
 
 	printf("\n\nLa nota final del alumno es: %.2f\n\n\n", notaFinal);
 	
 	if (notaFinal <= 5){
	 printf("Es un Burro :(\n\n");
	 }
	 else {
	 	printf("\nEstuvo bien :) \n\n\n");
	 }
 
	system("pause");
}
					
		

