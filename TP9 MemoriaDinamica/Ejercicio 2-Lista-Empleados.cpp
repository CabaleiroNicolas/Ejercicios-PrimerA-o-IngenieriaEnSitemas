#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char cadena[50];

struct empleados
{
	int legajo;
	cadena Apynom;
	int edad;
};


struct nodo
{
	empleados dato;
	nodo *sgte;
};



void insertar(nodo *&lista, empleados datos)
{
	nodo *nuevo=new nodo();
	nuevo->dato=datos;
	
	nodo *aux1=lista;
	nodo*aux2;
	
	while((aux1!=NULL)&&(aux1->dato.legajo < datos.legajo))
	{
		aux2=aux1;
		aux1=aux1->sgte;
	}
	if(lista==aux1)
	{
		lista = nuevo;
	}
	else
	{
		aux2->sgte=nuevo;
	}
	
	nuevo->sgte=aux1;
}




void listar(nodo *lista)
{
	nodo *aux=new nodo();
	aux=lista;
	int i=1;
	while(aux!=NULL)
	{
		printf("\n\nDatos del empleado %d:\n", i);
		printf("\nNombre y Apellido: %s", aux->dato.Apynom);
		printf("\nLegajo: %d", aux->dato.legajo);
		printf("\nEdad: %d\n", aux->dato.edad);
		i++;
		aux=aux->sgte;
		
	}
}



void borrar(nodo *&lista, int x)
{
	if(lista!=NULL)
	{
		nodo *aux;
		nodo *antes=NULL;
		aux=lista;
		
		while((aux!=NULL)&&(aux->dato.legajo!=x))
		{
			antes=aux;
			aux=aux->sgte;
		}
		if(aux==NULL)
		{
			printf("El empleado no esta registrado...\n\n");
		}
		else
		{
			if(antes==NULL)
			{
				lista=lista->sgte;
				delete aux;
			}
			else
			{
				antes->sgte=aux->sgte;
				delete aux;
			}
		}
	}
}



main()
{  

	int n;
	int x;
	
	nodo *lista=NULL;
	
	empleados datos;
	
	printf("\nIngresar la cantidad de empleados: ");
	scanf("%d", &n);
	
	system("cls");
	
	for(int i=1; i<=n ; i++)
	{
		printf("\nIngresar los datos del empleado %d:", i);
		
		printf("\n\nApellido y Nombre: ");
		_flushall();
		gets(datos.Apynom);
		
		printf("\nLegajo: ");
		scanf("%d", &datos.legajo);
		
		printf("\nEdad: ");
		scanf("%d", &datos.edad);
		
		insertar(lista, datos);
		
		printf("\n\n");
		system("cls");
	}
	
	
	printf("\nLista de datos ingresados: ");
	listar(lista);
	
	printf("\n\n");
	system("pause");
	system("cls");
	
	printf("\nIngresar el legajo del empleado que desea borrar: ");
	scanf("%d", &x);
	
	borrar(lista,x);
	
	system("pause");
	system("cls");
	
	printf("\nLista de elementos sobrantes");
	listar(lista);	
	
	printf("\n\n");
	system("cls");
}





