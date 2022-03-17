#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char cadena[20];

const int MIN_EMPLEADOS = 2;

struct VentaSemanal
{
	float lunes;
	float martes;
	float miercoles;
	float jueves;
	float viernes;	
};


struct Empleado
{
	char apeNom[30];
	int documento;
	float ventSem[5];
};


int Menu()
{
	int opc = 0;
	
	printf("\n--MENU--\n");
	printf("\n(1)- Registrar Empleados");
	printf("\n(2)- Registrar Ventas");
	printf("\n(0)- Salir");
	
	printf("\n\nIngrese Opcion: ");
	scanf("%d", &opc);

	return opc;	
}

void RegistrarEmpleados(Empleado reg[20], int &cont, int &emplFaltantes)
{
	int opc = 0;
	
	if(emplFaltantes > 0)
	{
	
		for(int i = 0; i < MIN_EMPLEADOS; i++)
		{
			printf("\n-INGRESAR EMPLEADOS-\n");
			
			printf("\nRegistrar Minimo %d Empleados (Quedan %d).\n", MIN_EMPLEADOS, emplFaltantes);
			printf("\nApellido y Nombre: ");
			_flushall();
			gets(reg[i].apeNom);
			printf("DNI: ");
			scanf("%d", &reg[i].documento);
				
			printf("\n\nEmpleado Registrado Existosamente!!\n");
			emplFaltantes--;
			cont++;
			system("pause");
			system("cls");

		}
	}
	
	do
	{		
		printf("\n-INGRESAR EMPLEADOS-\n");
		
		if(emplFaltantes <= 0)
		{
			printf("\nRegistrar Minimo %d Empleados (Ya puede Salir).\n", MIN_EMPLEADOS);
			printf("\nPresione 0 Para Salir.");
			printf("\nPresione 1 para Registrar mas Empleados.\n");
			printf("Opcion: ");
			scanf("%d", &opc);
				
			if(opc == 1)
			{
				printf("\nApellido y Nombre: ");
				_flushall();
				gets(reg[cont].apeNom);
				printf("DNI: ");
				scanf("%d", &reg[cont].documento);
				
				printf("\n\nEmpleado Registrado Existosamente!!\n");
				system("pause");
				system("cls");
				cont++;
			}
			else
			{
				printf("\nRegresando al Menu...\n\n");
			}
		}
					
	}while(opc != 0);
}


void RegistrarVentas(Empleado reg[20], int cont)
{
	char name[30];
	char dia[10];
	bool encontrado = false;
	int pos = 0;
	
	cadena diasSemana[100] = {"lunes","martes","miercoles","jueves","viernes"};
	
	
	printf("\nApellido y Nombre de Empleado: ");
	_flushall();
	gets(name);
	
	for(int i = 0; i < cont; i++)
	{
		if(strcmp(name, reg[i].apeNom) == 0)
		{
			pos = i;
			encontrado = true;
			
		}
	}
	
	if(encontrado == true)
	{
		printf("\nDia de venta: ");
		_flushall();
		gets(dia);
			
		for(int i = 0; i < 5; i++)
		{ 
				
			if(strcmp(dia, diasSemana[i]) == 0)
			{
				switch(i)
				{
					case 0:
						{
							printf("\nIngrese monto de venta del dia Lunes: ");
							scanf("%d", &reg[pos].ventSem[i]);
							break;
						}
					case 1:
						{
							printf("\nIngrese monto de venta del dia Martes: ");
							scanf("%d", &reg[pos].ventSem[i]);
							break;
						}
					case 2:
						{
							printf("\nIngrese monto de venta del dia Miercoles: ");
							scanf("%d", &reg[pos].ventSem[i]);
							break;
						}
					case 3:
						{
							printf("\nIngrese monto de venta del dia Jueves: ");
							scanf("%d", &reg[pos].ventSem[i]);
							break;
						}
					case 4:
						{
							printf("\nIngrese monto de venta del dia Viernes: ");
							scanf("%d", &reg[pos].ventSem[i]);
							break;
						}
				}	
			}
		}	
	}
	else
	{
		printf("\nNo se encontro Empleado...");
	}	
}

void ListarVentasSemanales(Empleado reg[20], int cont)
{
	printf("\nDocumento\t\tApellido y nombre\tLun\tMart\tMierc\tJuev\tViern\tTotal\n");
	for(int i = 0; i < cont; i++)
	{
		printf("\n%d", reg[i].documento);
		printf("\t\t%s", reg[i].apeNom);
		printf("\t\t%*.2f", reg[i].ventSem[0]);	
		printf("\t%.2f",  reg[i].ventSem[1]);
		printf("\t%.2f", reg[i].ventSem[2]);
		printf("\t%.2f", reg[i].ventSem[3]);
		printf("\t%.2f", reg[i].ventSem[4]);
	}
	
}

main()
{
	
	Empleado empl[20];
	int contador = 0;
	int empleadosFaltantes = MIN_EMPLEADOS;
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
					RegistrarEmpleados(empl, contador, empleadosFaltantes);
					system("pause");
					break;
				}
			case 2:
				{
					RegistrarVentas(empl, contador);
					system("pause");
					break;
				}
			case 3:
				{
					ListarVentasSemanales(empl, contador);
					printf("\n\n");
					system("pause");
					break;
				}
			case 0: printf("\nCerrando Programa..."); break;
		}
		
		
		
		
	}while(opcion != 0);
	
	
}
