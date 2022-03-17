#include <stdlib.h>
#include <stdio.h>
#include <conio.h>



float ParImpar(int valores)
{
	float promPares = 0;
	int cantPares = 0;
	int pares = 0;
	
	
	for (int i = 1; i <= n; i++)
	{
		printf("valor %d de %d: ", i, n);
		scanf("%d", &valor);
	
	if(valores % 2 == 0)
	{
		pares = pares + valores;
		cantPares++;
	}

	promPares = (float) pares / cantPares;
	}
	return promPares;
	
	
}


main()
{
	int n = 0;
	
	printf("Cuantos valores quiere ingresar?: ");
	scanf("%d", &n);
	
	
	printf("El porcentaje de los numeros pares es: %2.f", ParImpar(valor));

	getch();
}
