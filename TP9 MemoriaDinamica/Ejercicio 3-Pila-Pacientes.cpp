#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


struct Paciente
{
	char nombre[30];
	char telefono[15];
	int edad;
};

struct Nodo
{
	Paciente info;
	Nodo *sig;
};

int Menu()
{
	int opc = 0;
	
	printf("\n    --MENU--\n");
	printf("\n(1)- Ingresar Paciente");
	printf("\n(2)- Mostrar Pacientes");
	printf("\n(3)- Ver paciente con mayor edad");
	printf("\n(4)- Eliminar ultimo Paciente");
	printf("\n(0)- SALIR.");
	
	printf("\n\nIngrese opcion: ");
	scanf("%d", &opc);
	
	return opc;
}


void IngresarPaciente(Nodo *&tope, Paciente reg)
{
	Nodo *nuevo_nodo = new Nodo;
	
	if(nuevo_nodo != NULL)
	{
		nuevo_nodo -> info = reg;
		nuevo_nodo -> sig = tope;
		tope = nuevo_nodo;
		
		printf("\nPaciente ingresado con Exito!!");
	}
	else
	{
		printf("\nNo se pudo Ingresar el Paciente.");
	}	
	
}


void ListarPacientes(Nodo *&tope)
{
	Nodo *p;
	
	p = tope;
	
	while(p != NULL)
	{
		printf("\n\nNombre: %s", p->info.nombre);
		printf("\nTelefono: (+54) %s", p->info.telefono);
		printf("\nEdad: %d", p->info.edad);
		
		p = p->sig;
	}
	if(tope == NULL)
	{
		printf("\nNo hay Pacientes Registrados.");
	}
	
}

void PacienteMayor(Nodo *&tope, Paciente &reg)
{
	Nodo *p = tope;
	
	int pacienteMayor = -1;
	
	while(p != NULL)
	{
		if(p->info.edad > pacienteMayor)
		{
			reg = p->info;
			pacienteMayor = p->info.edad;
		}
		
		p = p->sig;
		
	}		
}



void EliminarPaciente(Nodo *&tope, Paciente &reg)
{
	Nodo *p = tope;
	
	if(p != NULL)
	{
		reg = p->info;
					
		tope = p->sig;
		
		delete p;
		
		printf("\nSe Elimino al Paciente: %s", reg.nombre);	
	}
	else
	{
		printf("\n\nNo Hay Pacientes Registrados.");
	}
	
}


main()
{
	Paciente reg;
	Nodo *pila = NULL;
	
	
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
					printf("\n      -Ingresar nuevo paciente-");
					
					printf("\n\nNombre: ");
					_flushall();
					gets(reg.nombre);
					
					printf("\nTelefono: ");
					_flushall();
					gets(reg.telefono);
					
					printf("\nEdad: ");
					scanf("%d", &reg.edad);
			
					IngresarPaciente(pila, reg);
					printf("\nPresione una Tecla para volver al Menu.");
					getch();
					break;
				}
			case 2:
				{
					printf("\n      -Lista de Pacientes");
					ListarPacientes(pila);
					printf("\n\nPresione una Tecla para volver al Menu...");
					getch();
					break;
				}
			case 3:
				{
					printf("\n      -Paciente Mayor-");
					PacienteMayor(pila, reg);
					printf("\n\nNombre: %s", reg.nombre);
					printf("\nEdad: %d", reg.edad);
					printf("\nTelefono: %s", reg.telefono);
					
					printf("\n\n");
					system("pause");
					break;
				}
			case 4:
				{
					printf("\n      -Eliminar Paciente-");
					EliminarPaciente(pila, reg);
					printf("\n\nPresione una tecla para volver al Menu.");
					getch();
					break;
				}
			case 0:
				{
					printf("\n\nCerrando Programa...\n\n");
					system("pause");
					break;
				}
			default:
				{
					printf("\n\nLa opcion no se encuentra Disponible.\n");
					printf("Porfavor presione una tecla para volver al Menu...");
					getch();
				}
		}
		
	}while(opcion != 0);
	
	
	
}
