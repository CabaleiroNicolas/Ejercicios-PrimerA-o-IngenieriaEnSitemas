#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

main()
{
	int alumnosEgresados = 0;
	int cantidadAlumnos = 0;
	int legajo = 0;
	int carrera = 0;
	int isi = 0;
	float porcentajeIsi = 0;
	int mecanica = 0;
	float porcentajeElectrica = 0;
	int electrica = 0;
	float porcentajeMecanica = 0;
	
	
	
	
	printf("\nIngrese cantidad de alumnos que egresan: ");
	scanf("%d", &cantidadAlumnos);
	
	for(int i=1; cantidadAlumnos >= i; i++)
	{
		printf("\nIngrese legajo de alumno %d de %d: ", i, cantidadAlumnos);
		scanf("%d", &legajo);
		
		printf("\n1-> ISI");
		printf("\n2-> Mecanica");
		printf("\n3-> Electrica");
		printf("\nIngrese carrera: ");
		scanf("%d", &carrera);
		
		
		switch(carrera)
		{
			case 1:
				isi++;
				alumnosEgresados++; system("cls"); break;
			
			case 2:
				mecanica++;
				alumnosEgresados++; system("cls"); break;
			
			case 3:
				electrica++;
				alumnosEgresados++; system("cls"); break;
			
			default: printf("\nEsa carrera no existe...\n\n"); break;
		}	
	}
	
	porcentajeIsi = isi * 100 / alumnosEgresados;
	porcentajeMecanica = mecanica * 100 / alumnosEgresados;
	porcentajeElectrica = electrica * 100 / alumnosEgresados;
	
	printf("\n\nLa cantidad de alumnos egresados en ISI son: %d", isi);
	printf("\nEl porcentaje de egresados en ISI es: %.2f%%", porcentajeIsi);
	
	printf("\n\nLa cantidad de alumnos egresados en MECANICA son: %d", mecanica);
	printf("\nEl porcentaje de egresados en MECANICA es: %.2f%%", porcentajeMecanica);
	
	printf("\n\nLa cantidad de alumnos egresados en ELECTRICA son: %d", electrica);
	printf("\nEl porcentaje de egresados en ELECTRICA es: %.2f%%", porcentajeElectrica);
	

	getch();
}
