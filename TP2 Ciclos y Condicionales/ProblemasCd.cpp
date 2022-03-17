#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

float capacidadDisco = 0;
float cd = 0;

	main()
	{
		printf("\n\nIngrese la capacidad en GB del Disco duro: ");
		scanf("%f", &capacidadDisco);
		
		cd = capacidadDisco*1024 / 700;
		
		printf("\n\nPara almacenar %.2f GB de disco duro se necesitan: ", capacidadDisco);
		
		printf("%.2f CD virgenes\n\n\n\n\n\n\n", cd);
		
		return 0;
	}
