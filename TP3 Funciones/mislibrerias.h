#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int Mayor(int a, int b, int c)
{
	int mayor = 0;
	
	if ((a >= b) && (a >= c))
	{
		mayor = a;
	}
	
	if ((c >= a) && (c >= b))
	{
		mayor = c;
	}
	
	if ((b >= a) && (b >= c))
	{
		mayor = b;
	}
	return mayor;
}


int Menor(int a, int b, int c)
{
	int menor = 0;
	
if ((a <= b) && (a <= c))
	{
		menor = a;
	}
	
	if ((b <= a) && (b <= c))
	{
		menor = b;
	}
	
	if ((c <= b) && (c <= a))
	{
		menor = c;
	}
		
	return menor;
}


float Promediar(int a, int b, int c)
{
	float resultado = 0.0;
	
	resultado = (float) (a + b + c) / 3;
	
	return resultado;
}


int Multiplicar(int a, int b, int c)
{
	int resultado = 0;
	
	resultado = a * b * c;
	
	return resultado;	
}


float Dividir(int a, int b)
{
	float resultado = 0.0;
	if(b != 0)
	{
	resultado = a / b;
	}
	return resultado;
}


int Sumar(int a, int b)
{
	int resultado = 0;
	
	resultado = a + b;
	
	return resultado;
}


int Restar(int a, int b)
{
	int resultado;
	
	resultado = a - b;
	
	return resultado;
}

