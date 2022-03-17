#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Fech
{
	int fech_dia;
	int fech_mes;
	int fech_anio;	
};

struct Nota
{
	float primerTri;
	float segundoTri;
	float tercerTri;
	
	float promAnual;
};

struct Alumnos
{
	int doc;
	char apeNom[30];
	Fech fechaNac;
	Nota notas;
	bool borrado;
};

void AgregarAlumno(Alumnos reg[30], int opc, int &i, int &prom8)
{
	
	
	if(opc == 1)
	{
		reg[i].borrado = false;
		
		printf("\nDocumento: ");
		scanf("%d", &reg[i].doc);
		
		printf("Apellido y Nombre: ");
		_flushall();
		gets(reg[i].apeNom);
		
		
		printf("\nFecha de Nacimiento: ");
		printf("\nDia: ");
		scanf("%d", &reg[i].fechaNac.fech_dia);
		printf("Mes: ");
		scanf("%d", &reg[i].fechaNac.fech_mes);
		printf("Anio: ");
		scanf("%d", &reg[i].fechaNac.fech_anio);
		
		while(reg[i].fechaNac.fech_dia < 1 || reg[i].fechaNac.fech_dia > 31 || reg[i].fechaNac.fech_mes < 1 || reg[i].fechaNac.fech_mes > 12 || reg[i].fechaNac.fech_anio > 2021)
		{
			printf("\nFecha invalida en Dia Mes o Anio, porfavor ingrese nuevamente...\n\n");
			
			system("pause");
			system("cls");
			
			_flushall();
			
			printf("\nFecha de Nacimiento: ");
			printf("\nDia: ");
			scanf("%d", &reg[i].fechaNac.fech_dia);
			printf("Mes: ");
			scanf("%d", &reg[i].fechaNac.fech_mes);
			printf("Anio: ");
			scanf("%d", &reg[i].fechaNac.fech_anio);
			
			reg[i].borrado = false;
			
		}
		
		
		printf("\nNotas: ");
		printf("\nPrimer Trimestre: ");
		scanf("%f", &reg[i].notas.primerTri);
		printf("Segundo Trimestre: ");
		scanf("%f", &reg[i].notas.segundoTri);
		printf("Tercer Trimestre: ");
		scanf("%f", &reg[i].notas.tercerTri);
		
		reg[i].notas.promAnual = (float) (reg[i].notas.primerTri + reg[i].notas.segundoTri + reg[i].notas.tercerTri) / 3;
	
		if(reg[i].notas.promAnual >= 8)
		{
			prom8++;
		}
		
		i++;
		
	}
	
	printf("\nAlumno ingresado con exito!");
	printf("\n\n");
	system("pause");
}


void EliminadoFisico(Alumnos alu[30], int &cont, int &prom8)
{
	int n = 0;
	
	int posBorrar = -1;
	
	printf("\nIngrese documento de alumno a eliminar: ");
	scanf("%d", &n);
	

	for(int i = 0; i < cont; i++)
	{
		
		if(alu[i].doc == n)
		{
			
			posBorrar = i;
			
		}
		
	}
	
	if(posBorrar >= 0)
	{
	
		if(alu[posBorrar].notas.promAnual >= 8)
		{
			prom8--;
		}
	
		for(int i = posBorrar; i < cont; i++)
		{
				
			alu[i] = alu[i+1];	
		}
		
		cont--;
		
		printf("\nAlumno eliminado Correctamente!");
	
	}
	else
	{
		printf("\nEse alumno no existe en la lista...\n\n");
	}
				
}

void EliminadoLogico(Alumnos alu[30], int &cont, int &prom8)
{
	int aBorrar;

	bool encontrado = false;
	
	printf("\nIngrese documento de alumno: ");
	scanf("%d", &aBorrar);
	
	for(int i = 0; i < cont; i++)
	{
		if((aBorrar == alu[i].doc) && (alu[i].borrado == false))
		{
			encontrado = true;	
			
			alu[i].borrado = true;
			
					
			if(alu[i].notas.promAnual >= 8)
			{
				prom8--;
			}
			
			printf("\nAlumno eliminado correctamente!...\n\n");
			
			
		}
			
					
	}	

	if(encontrado == false)
	{
		printf("\nEl alumno ingresado no se encuentra en el sistema...\n\n");
	}
	
}


void MostrarAlumnos(Alumnos alu[30], int &cont)
{
	for(int i = 0; i < cont; i++)
	{
		if(alu[i].borrado == false)
		{
		
		
			printf("\n-----------------------------------------------------------------------");
			
			printf("\nNombre: %s", alu[i].apeNom);
			printf("\nDocumento: %d", alu[i].doc);
			printf("\nFecha de nacimiento: %d/%d/%d", alu[i].fechaNac.fech_dia, alu[i].fechaNac.fech_mes, alu[i].fechaNac.fech_anio);
			
			printf("\n\nNotas:");
			printf("\nPrimer Trismestre: %.2f", alu[i].notas.primerTri);
			printf("\nSegundo Trismestre: %.2f", alu[i].notas.segundoTri);
			printf("\nTercer Trismestre: %.2f", alu[i].notas.tercerTri);
			printf("\n\nPromedio Anual: %.2f", alu[i].notas.promAnual);
			
			printf("\n-----------------------------------------------------------------------");
		}
	
	}
	
	if(cont == 0)
	{
		
		printf("\nTodavia no se ingresaron alumnos...");

		
	}
	
	printf("\n\n");
	system("pause");
	
}


void Menu(int opc, Alumnos alu[30], int &contador, int &prom8)
{
	
	switch( opc )
	{
		case 1: printf("Agregar Alumno");
				printf("\n\n");
				AgregarAlumno(alu, opc, contador, prom8);
		
				break;
				
		case 2: printf("Mostrar Alumnos:");
				printf("\n\n");
				MostrarAlumnos(alu, contador);
		
				break;
				
		case 3: printf("Promedios mayor a 8");
				printf("\n\n");
				printf("Cantidad de alumnos con promedio mayor a 8: %d\n\n", prom8);
				system("pause");
				break;
				
		case 4: printf("Eliminar Alumno Logicamente");
				printf("\n\n");
				EliminadoLogico(alu, contador, prom8);
				system("pause");
				break;
				
		case 5: printf("Eliminar Alumno Fisicamente");
				printf("\n\n");
				EliminadoFisico(alu, contador, prom8);
				system("pause");
				break;		
				
		case 0: printf("Saliendo del Programa...\n\n");
		
				break;
				
				
		default: printf("\nEsa opcion no esta en el Menu...\n\n");
				system("pause");
				break;	
					
				
	} 
		
}




main()
{
	Alumnos alu[30];
	
	int contador = 0;
	int opc = 0;
	int alumnosPromMay8 = 0;
	
	do
	{
		
		system("cls");
	
		printf("\n1- Agregar Alumno");
		printf("\n2- Mostrar Alumnos");
		printf("\n3- Mostrar Alumnos con promedio mayor a 8");
		printf("\n4- Eliminar Alumno Logicamente");
		printf("\n5- Eliminar Alumno Fisicamente");
		printf("\n0- Salir");
	
		printf("\n\nIngrese una Opcion: ");
		scanf("%d", &opc);
		
		system("cls");
		printf("\n\n");		
		Menu(opc, alu, contador, alumnosPromMay8);
	
	}while(opc != 0);
	
	
	
	system("pause");
	printf("\n\n");
}
