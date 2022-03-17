#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char cadena[30];


void Cargar(cadena materias[30], int nro[100], int n)
{
	for(int i = 0; i < n; i++)
	{
		
		printf("\nIngrese materia %d: ", i);
		_flushall();
		gets(materias[i]);
		strlwr(materias[i]);
		
		printf("\nIngrese nro de inscriptos en %s: ", materias[i]);
		scanf("%d", &nro[i]);
				
	}	
}


int MayorNroInscriptos(int insc[100], int n, int &max)
{
	
	int mejorMateria = 0; 
	
	for(int i = 0; i < n; i++)
	{
		if(insc[i] > max)
		{
			max = insc[i];
			
			mejorMateria = i;
		}
		
	}
	
	return mejorMateria;
}


int EncontrarInscriptos(int insc[100],cadena materia[30],cadena &materiaEncontrar, int n)
{
	int cantInscriptos = 0;
	
	int posEstudiantes = 0;
	int b = 0;
	
	
	printf("\n Ingrese materia que quiera encontrar el Nro de inscriptos de algunas de las siguientes: \n");
	
	for(int i = 0; i < n; i++)
	{
		printf("\n %s", materia[i]);	
	}
	
	printf("\n\n: ");
	_flushall();
	gets(materiaEncontrar);
	strlwr(materiaEncontrar);
	
	for(int i = 0; i < n; i++)
	{
		b = strcmp(materia[i], materiaEncontrar);
		
		if(b == 0)
		{
			posEstudiantes = i;
		}
		
	}
	
	cantInscriptos = insc[posEstudiantes];
	
	return cantInscriptos;
	
}

main()
{
	cadena materias[30];
	cadena materiaEncontrar;
	int inscriptos[100];
	
	int cantidadMaterias = 0;
	int mayInsc = -1;
	int b = 0;
	int cantidadInscriptosEnMateriaBusqueda = 0;
	
	
	
	printf("\nIngrese cantidad de materias: ");
	scanf("%d", &cantidadMaterias);
	
	printf("\n\n");
	
	Cargar(materias, inscriptos, cantidadMaterias);
	
	b = MayorNroInscriptos(inscriptos, cantidadMaterias, mayInsc);
	
	system("cls");
	printf("\n\n");
	
	printf("\n La materia con mas inscriptos fue: => %s <= Con %d estudiantes", materias[b], mayInsc);
	
	printf("\n\n");
	
	cantidadInscriptosEnMateriaBusqueda = EncontrarInscriptos(inscriptos, materias, materiaEncontrar, cantidadMaterias);
	
	printf("\n %s tiene: %d Alumnos", materiaEncontrar, cantidadInscriptosEnMateriaBusqueda);
	
	printf("\n\n\n");
	system("pause");

}
