#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct Alumno
{
	char nombre[30];
	char apellido[30];
	char carrera[30];
	char nota[30];
};


int Menu()
{
	int opc = 0;
	
	printf("\n      --MENU--");
	printf("\n\n(1)- Cargar Estudiante.");
	printf("\n(2)- Listar Estudiantes");
	printf("\n(0)- SALIR.");
	
	printf("\n\nIngrese Opcion: ");
	scanf("%d", &opc);
	
	return opc;
}


void AgregarEstudiante(FILE *arch)
{
	Alumno alu;
	
	arch = fopen("empleados.txt","at");
	
	if(arch == NULL)
	{
		arch = fopen("empleados.txt","w+t");
		
		if(arch == NULL)
		{
			printf("\nNo se pudo Crear el archivo.");
		}
	}
	
	printf("\nNombre: ");
	_flushall();
	gets(alu.nombre);
	
	strcat(alu.nombre, ";");
	
	fprintf(arch, alu.nombre);
	
	printf("\nApellido: ");
	_flushall();
	gets(alu.apellido);
	
	strcat(alu.apellido, ";");
	
	fprintf(arch, alu.apellido);
	
	printf("\nCarrera: ");
	_flushall();
	gets(alu.carrera);
	
	strcat(alu.carrera, ";");
	
	fprintf(arch, alu.carrera);
	
	printf("\nNota Promedio: ");
	_flushall();
	gets(alu.nota);
	
	strcat(alu.nota, ";");
	strcat(alu.nota, "\n");
	
	fprintf(arch, alu.nota);
	
	
	fclose(arch);	
}



void ListarEstudiantes(FILE *arch)
{
	Alumno alu;
	
	arch = fopen("empleados.txt","r+t");
	
	if(arch == NULL)
	{
		printf("\nNo se creo el archivo");
	}
	
	
	fgets(alu.nombre, sizeof(alu.nombre), arch);
	
	
	printf("\n\n");
	
	while(!feof(arch))
	{
		
		printf("Alumno: %s\n", alu.nombre);
			
		fgets(alu.nombre, sizeof(alu.nombre), arch);

	}
	
	fclose(arch);
	
}

main()
{
	FILE *arch;
	int opcion = 0;
	
	do
	{
		system("cls");
		opcion = Menu();
		system("cls");
		
		switch(opcion)
		{
			case 1:
				{
					AgregarEstudiante(arch);
					break;
				}
			case 2:
				{
					ListarEstudiantes(arch);
					system("pause");
					break;
				}
			case 0:
				{
					
					break;
				}
			default:
				{
					printf("\nLa opcion seleccionada no se encuentra en el Menu.");
					break;
				}	
			
			
			
		}
		
		
	}while(opcion != 0);
	
	
}














