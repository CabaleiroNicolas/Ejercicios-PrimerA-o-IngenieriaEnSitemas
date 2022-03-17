#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct nodo
{
	int dato;
	nodo *sgte;
};

void insertar(nodo *&lista, int x)
{
	nodo *nuevo=new nodo();
	nuevo->dato=x;
	
	nodo *aux1=lista;
	nodo*aux2;
	
	while((aux1!=NULL)&&(aux1->dato < x))
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


void borrar(nodo *lista, int x)
{
	if(lista!=NULL)
	{
		nodo *aux;
		nodo *antes=NULL;
		aux=lista;
		
		while((aux!=NULL)&&(aux->dato!=x))
		{
			antes=aux;
			aux=aux->sgte;
		}
		if(aux==NULL)
		{
			printf("\El elemento no existe.");
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


void listar(nodo *lista)
{
	nodo *aux=new nodo();
	aux=lista;
	int i=1;
	while(aux!=NULL)
	{
		printf("\nNumero %d: %d",i,aux->dato);
		
		i++;
		aux=aux->sgte;
	}
}


main()
{
	int n;
	int dato;
	int x;
	nodo *lista=NULL;
	
	printf("\nIngresar cantidad de datos: ");
	scanf("%d", &n);
	
	for(int i=1; i<=n ; i++)
	{
	    printf("\nIngresar el valor %d: ", i);
		scanf("%d", &dato);
		
		insertar(lista, dato);
	}
	
	system("cls");
	
	printf("\nLista de datos ingresados: \n");
	listar(lista);
	
	printf("\n\nDigite un dato para eliminar de la lista: ");
	scanf("%d", &x);
	borrar(lista,x);
	
	system("cls");
	
	printf("\nLista de elementos sobrantes\n");
	listar(lista);
	
	printf("\n\n");
	system("pause");
}

