#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int TAMANO = 100;
const int TAMANOREGISTRO = 20;


struct fecha
{
	int dia;
	int mes;
	int anio;
};


struct DatosEmpleados
{
	char ApNom[TAMANO];
	char Domicilio[TAMANO];
	fecha FechaIngreso;
	fecha FechaProceso;
	int Antiguedad;	
};


int Menu () 
{
    int opcion = 0;

    printf("MENU");
    printf("\n----\n");
    printf("\n1- Cargar miembros");
    printf("\n2- Registrar ventas.");
    printf("\n3- Listar ventas semanal.");
    printf("\n0- Salir");
    printf("\n\nOpcion: ");
    scanf("%d", &opcion);

    return opcion;
}

float ingresarDatos(DatosEmpleados Empleado[TAMANOREGISTRO],int &i)
{
	int antiguedad[TAMANOREGISTRO];
	int continuar=0;
	
	int suma=0;
	int cantEmpleados=0;
	float promedioAntiguedad=0.0;
	do
	{
	
		printf("Empleado %d: \n",i);
		printf("\nApellido y nombre: ");
		_flushall();		
		gets(Empleado[i].ApNom);
		strlwr(Empleado[i].ApNom);
		printf("\nDomicilio: ");
		_flushall();		
		gets(Empleado[i].Domicilio);
		strlwr(Empleado[i].Domicilio);
		printf("\nIngrese la fecha de ingreso: ");
		printf("\n\tDia: ");
			scanf("%d",&Empleado[i].FechaIngreso.dia);
		printf("\tMes: ");
			scanf("%d",&Empleado[i].FechaIngreso.mes);
		printf("\tAnio: ");
			scanf("%d",&Empleado[i].FechaIngreso.anio);
			if(Empleado[i].FechaIngreso.anio<1000 || Empleado[i].FechaIngreso.anio>9999){
			printf("El anio debe tener 4 digitos: ");
			scanf("%d",&Empleado[i].FechaIngreso.anio);
			
			}
		printf("Ingrese la fecha de proceso: ");
		printf("\n\tDia: ");
			scanf("%d",&Empleado[i].FechaProceso.dia);
		printf("\tMes: ");
			scanf("%d",&Empleado[i].FechaProceso.mes);
		printf("\tAnio: ");
			scanf("%d",&Empleado[i].FechaProceso.anio);
		if(Empleado[i].FechaProceso.anio<1000 || Empleado[i].FechaProceso.anio>9999){
			printf("El anio debe tener 4 digitos: ");
			scanf("%d",&Empleado[i].FechaProceso.anio);
			
		}
		Empleado[i].Antiguedad=Empleado[i].FechaProceso.anio-Empleado[i].FechaIngreso.anio;
		printf("\nTiene una antiguedad de %d anios",Empleado[i].Antiguedad);
		cantEmpleados++;
		suma=suma+Empleado[i].Antiguedad;
		printf("\nSi desea ingresar mas empleados presione 1 : ");
		scanf("%d",&continuar);
		
		i++;
		
	}while(continuar==1);
	
promedioAntiguedad=(float)suma/cantEmpleados;	


return	promedioAntiguedad;

}


void buscarNombre(DatosEmpleados Empleado[TAMANOREGISTRO])
{
	bool encontrado=false;
	char busqueda[TAMANO];
	printf("\nIngrese el apellido y nombre a buscar: ");
	_flushall();
	gets(busqueda);
	for(int i=0;i<20;i++)
	{
		if(strcmp(Empleado[i].ApNom,busqueda)==0)
		{
			printf("\nLa antiguedad de %s es : %d anios",Empleado[i].ApNom,Empleado[i].Antiguedad);
			encontrado=true;
		}
		
	}
	
	if(!encontrado)
		{
			printf("\nEl Empleado no fue encontrado");
		}	
		
}

void listarEmpleados(DatosEmpleados Empleado[TAMANOREGISTRO],int tope){
	
	for(int i=0;i<tope;i++)
	{
		
		printf("\nEmpleado %d: ",i);
		printf("\nApellido y nombre: ");
		puts(Empleado[i].ApNom);
		printf("\nDomicilio: ");
		puts(Empleado[i].Domicilio);
		printf("\nFecha de ingreso: ");
		printf("\n\tDia: %d",Empleado[i].FechaIngreso.dia);
		printf("\n\tMes: %d",Empleado[i].FechaIngreso.mes);
		printf("\n\tAnio: %d",Empleado[i].FechaIngreso.anio);
		printf("\nFecha de Proceso: ");
		printf("\n\tDia: %d",Empleado[i].FechaProceso.dia);
		printf("\n\tMes: %d",Empleado[i].FechaProceso.mes);
		printf("\n\tAnio: %d",Empleado[i].FechaProceso.anio);
		
	}
	
}






main()
{
	int n=0;
	DatosEmpleados Empleado[TAMANOREGISTRO];
	int op;
	float promedioAntiguedad=0.0;
	promedioAntiguedad=ingresarDatos(Empleado,n);
	printf("El promedio de la antiguedad es de: %.2f",promedioAntiguedad);
	system("cls");
	buscarNombre(Empleado);
	listarEmpleados(Empleado,n);
	
}
