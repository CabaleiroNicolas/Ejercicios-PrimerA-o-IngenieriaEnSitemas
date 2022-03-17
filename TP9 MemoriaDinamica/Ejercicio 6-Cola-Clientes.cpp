#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int Menu()
{
	int opc = 0;
	
	printf("\n      -Menu-");
	printf("\n*******************");
	printf("\n\n1)- Ingresar Cliente");
	printf("\n2)- Mostrar Cliente por Atender");
	printf("\n3)- Porcentaje de Clientes con Problemas Tecnicos");
	printf("\n0)- Salir...");
	
	printf("\n\nOpcion: ");
	scanf("%d", &opc);
	
	return opc;
}


struct Cliente
{
	char nroAtencion[20];
	char telefono[20];
	char reclamo;
		
};

struct Nodo
{
	Cliente info;
	Nodo *sig;	
};


void IngresarCliente(Nodo *&frente, Nodo *&fondo, Cliente reg)
{	
	Nodo *p = new Nodo;
	
	if(p != NULL)
	{
		p->info = reg;
		p->sig = NULL;
		
		if(frente == NULL)
		{
			frente = p;
			fondo = p;
		}
		else
		{
			fondo->sig = p;
			fondo = p;
		}	
		
	}
	
}


void MostrarCliente(Nodo *&frente, Nodo *&fondo)
{
	Nodo *p = frente;
	
	if(p == NULL)printf("\nNo hay Clientes por Atender...\n\n");
	
	if(p != NULL)
	{
		printf("\nSiguiente Cliente");
		printf("\n\nNro de Atencion: %s", p->info.nroAtencion);
		printf("\nTelefono: (+54)%s", p->info.telefono);
		printf("\nTipo de Reclamo: ");
		switch (p->info.reclamo)
		{
			case 'F':printf("Facturacion\n\n");break;
			case 'f':printf("Facturacion\n\n");break;
			
			case 'T':printf("Tecnico\n\n");break;
			case 't':printf("Tecnico\n\n");break;
			
			case 'C':printf("Compra\n\n");break;
			case 'c':printf("Compra\n\n");break;
		}
		
	}
	
	
}



void BorrarCliente(Nodo *&frente, Nodo *&fondo)
{
	Nodo *p = frente;
	
	if(frente != NULL)
	{
		p = frente;
		frente = frente->sig;
		
		delete p;
	}
	else
	{
		fondo = NULL;
	}
	
	
}



void CalcularPorcentajeProblemaTecnico(int tec, int cont)
{
	float porc = 0.0;
	
	porc = (float) tec*100/cont;
	
	if(cont > 0)
	{
		printf("\nPorcentaje de CLientes con Problemas Tecnicos: %.2f%%\n\n", porc);
	}
	else
	{
		printf("\nNo hay Clientes Ingresados...\n\n");
	}
}

main()
{
	Nodo *frente;
	Nodo *fondo;
	
	frente = NULL;
	fondo = NULL;
	
	Cliente reg;
	int opcion = 0;
	int problemasTecnicos = 0;
	int contador = 0;
	
	
	do
	{
		
		system("cls");
		opcion = Menu();
		system("cls");
		
		switch(opcion)
		{
			case 1:
				{
					contador++;
					
					printf("\n   -Ingresar Cliente-");
					printf("\n****************************");
					
					printf("\nNro de Atencion: ");
					_flushall();
					gets(reg.nroAtencion);
					
					printf("\nTelefono: ");
					_flushall();
					gets(reg.telefono);
					
					printf("\nTipo de Reclamo");
					printf("\nF) Facturacion");
					printf("\nC) Compra");
					printf("\nT) Tecnico");
					printf("\nOpcion: ");
					_flushall();
					scanf("%c", &reg.reclamo);
					
					if(reg.reclamo == 'T' || reg.reclamo == 't') problemasTecnicos++;
						
				
					IngresarCliente(frente, fondo, reg);
					break;
				}
			case 2:
				{
					MostrarCliente(frente, fondo);
					BorrarCliente(frente, fondo);
					system("pause");
					break;
				}
			case 3:
				{
					CalcularPorcentajeProblemaTecnico(problemasTecnicos, contador);
					system("pause");
					break;
				}
			case 0:
				{
					printf("\n\nCerrando Programa...\n\n");
					system("pause");
					break;
				}
			default: printf("\nEsa Opcion no se encuentra en el MENU...\n\n");system("pause");break;
		}
		
	}while(opcion != 0);
	

}












