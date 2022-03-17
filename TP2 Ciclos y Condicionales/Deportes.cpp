#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

main()
{
	int nroSocio = 0;
	int edad = 0;
	int deporte = 0;
	int sexo = 0;
	
	int socioEdad30y50Futbol = 0;
	int socioFemenino = 0;
	int socioMasculino = 0;
	int socioMenor16 = 0;

	printf("\nIngrese numero de socio (0 para teminar): ");
	scanf("%d", &nroSocio);
	
	
		while(nroSocio > 0)
		{
			printf("\nIngrese edad: ");
			scanf("%d", &edad);
			
			printf("\nIngrese sexo(1-Maculino   Femenino-2): ");
			scanf("%d", &sexo);
			
			printf("\nIngrese deporte: ");
			scanf("%d", &deporte);
			
			if((edad >= 30) && (edad <= 50) && (deporte == 1))
			{
				socioEdad30y50Futbol++;
			}
			
			if(sexo == 1)
			{
				socioMasculino++;
			}
			
			else 
			{
				socioFemenino++;
			}
			
			if(edad <= 16)
			{
				socioMenor16++;
			}
			
			system("cls");
			
		printf("\nIngrese numero de socio (0 para teminar): ");
		scanf("%d", &nroSocio);
		}
		
		system("cls");
	

	printf("\n\nSocios entre 30 y 50 años que practican futbol: %d", socioEdad30y50Futbol);
	printf("\n\nSocios Masculinos: %d", socioMasculino);
	printf("\n\nSocios Femeninos: %d", socioFemenino);
	printf("\n\nSocios menores de 16 años: %d", socioMenor16);
	



		
	
	getch();
}
