#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int TAMANO = 100;

struct fecha{
	int dia;
	int mes;
	int Anio;
};

struct DatosPropietario{
	int NumeroDeExpediente;
	char NomYAp[TAMANO];
	int cantidadMetrosCuadrados;
	int tipoObra;
	fecha fechaAdelanto;
	float monto;
};
int Menu () {
    int opcion = 0;

    printf("MENU");
    printf("\n----\n");
    printf("\n1- Registrar Datos");
    printf("\n2- Listar Monto de un expediente.");
    printf("\n0- Salir");
    printf("\n\nOpcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void cargarMonto(int &Expediente,fecha &fechaDeAdelanto,float &monto){
	
	printf("Montos del expediente: %d\n",Expediente);
	printf("\t");
	printf("Fecha: \n");
	printf("\tDia: ");
	scanf("%d",&fechaDeAdelanto.dia);
	printf("\tMes: ");
	scanf("%d",&fechaDeAdelanto.mes);
	printf("\tAnio: ");
	scanf("%d",&fechaDeAdelanto.Anio);
	printf("Ingrese el monto: ");
	scanf("%f",&monto);

}

void ingresarDatos(DatosPropietario propietario[TAMANO],int n){
	
	for(int i=0;i<n;i++){
		printf("\nPropietario %d\n",i);
		printf("Ingrese el numero del Expediente: ");
		scanf("%d",&propietario[i].NumeroDeExpediente);
		printf("Ingrese el nombre y apellido del propietario: ");
		_flushall();
		gets(propietario[i].NomYAp);
		strlwr(propietario[i].NomYAp);
		printf("Ingrese la cantidad de metros construidos: ");
		scanf("%d",&propietario[i].cantidadMetrosCuadrados);
		printf("Ingrese el tipo de obra (0: vivienda básica, 1: vivienda de Lujo, 2: Edificio, 3: predio especial): ");
		scanf("%d",&propietario[i].tipoObra);
		
		cargarMonto(propietario[i].NumeroDeExpediente,propietario[i].fechaAdelanto,propietario[i].monto);		
	}
	

}
void mostrarMonto(DatosPropietario propietario[TAMANO],int ExpedienteABuscar,int n){
	bool encontrado=false;
	for(int i=0;i<n;i++){
		if(propietario[i].NumeroDeExpediente==ExpedienteABuscar){
			printf("\nExpediente: %d",propietario[i].NumeroDeExpediente);
			printf("\nPrpietario: ");
			puts(propietario[i].NomYAp);
			printf("Tipo de obra: ");
			switch(propietario[i].tipoObra){
				case 0:{
					printf("Vivienda Basica");
					break;
				}
				case 1:{
					printf("Vivienda de Lujo");
					break;
				}
				case 2:{
					printf("Edificio");
					break;
				}
				case 3:{
					printf("Predio especial");
					break;
				}
				default:{
					break;
				}
			
			}
			
			printf("\nFecha\t\tMonto");
			printf("\n%d/%d/%d", propietario[i].fechaAdelanto.dia, propietario[i].fechaAdelanto.mes, propietario[i].fechaAdelanto.Anio);
			printf("\t$%.2f\n",propietario[i].monto);
			encontrado=true;
		}
		
	
	}
	if(!encontrado){
		printf("\nEl expediente no fue encontrado\n");
	}
	system("pause");
}



main()
{
	
	DatosPropietario propietario[TAMANO];
	int n;
	int op;
	
	printf("\nIngresar la cantidad de propietarios (min 5): ");
	scanf("%d",&n);
	
	while(n<5)
	{
		printf("\nIngrese datos de al menos 5 propietarios: ");
		scanf("%d",&n);
	
	
	
		do
		{
		    system("cls");
		    op = Menu();
		    system("cls");
		
	        switch (op)
			{
	        case 1:
				{
	            	ingresarDatos(propietario,n);
					break;
	            }                
	                
	        case 2:
				{
	            	int ExpedienteABuscar;
	            	printf("Ingrese el expediente a buscar: ");
	            	scanf("%d",&ExpedienteABuscar);
	            	mostrarMonto(propietario,ExpedienteABuscar,n);
					break;
	            }
	                
	        case 0:
				{
	        		
	        		printf("\nCerrando Programa...");	
	        		break;
	        	}
	                	
	        default:
	            {
	            	
	            	printf("\nLa opcion ingresada NO s encuentra en el MENU.");
	            	break;
	            }
	                
	        }
	
	    }while(op != 0);	
		
	}
}
