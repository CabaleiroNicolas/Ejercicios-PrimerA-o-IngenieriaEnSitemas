#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct datoCliente
{
	int codCli = 0;
	
	char apeNom[40];
	char direc[60];
	
	float monMax = 0.0;
};


void MostrarDatos(int n, datoCliente reg[100])
{
	
	for(int i = 0; i < n; i++)
	{
	
		printf("\nDatos de cliente %d", i+1);
		
		printf("\n\nCodigo: %d", reg[i].codCli);
		
		printf("\nNombre y apellido: ");
		puts(reg[i].apeNom);
		
		printf("Domicilio: ");
		puts(reg[i].direc);
		
		printf("Credito maximo: %.2f", reg[i].monMax);
		
		printf("\n\n\n");
	}	
}


main()
{
	
	datoCliente reg[100];
	
	int numClientes = 0;
	int cantMontoSup = 0;
	
	printf("\nIngrese cantidad de clientes: ");
	scanf("%d", &numClientes);
	
	system("cls");
	
	for(int i = 0; i < numClientes; i++)
	{
		printf("\nIngrese datos de Cliente %d", i+1);
		
		printf("\n\nCodigo: ");
		scanf("%d", &reg[i].codCli);
		
		
		printf("Nombre y Apellido: ");
		_flushall();
		gets(reg[i].apeNom);
		
		
		printf("Domicilio: ");
		_flushall();
		gets(reg[i].direc);
		
		printf("Monto maximo de credito: ");
		scanf("%f", &reg[i].monMax);
		
		if(reg[i].monMax >= 30000)
		{
			cantMontoSup++;
		}
		
		system("cls");
		printf("\n");	
	}
	
	
	MostrarDatos(numClientes, reg);
	
	printf("\n\n");
	
	printf("\nCantidad de clientes con creditos mayores a $30000: %d", cantMontoSup);
	
	printf("\n\n");
	system("pause");
		
}




