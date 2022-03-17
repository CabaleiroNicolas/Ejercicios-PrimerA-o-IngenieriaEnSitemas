#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int Menu()
{
	int opc = 0;
	
	printf("\n      --MENU--");
	printf("\n\n(1)- Ingresar frase de Jose Luis");
	printf("\n(2)- Ingresar frase de Maria Emilia");
	printf("\n(3)- Mostrar frase de Jose Luis");
	printf("\n(4)- Mostrar frase de Maria Emilia");
	printf("\n(5)- Combinar Frases");
	printf("\n(6)- Mostrar Frases Combinadas");
	printf("\n(7)- Eliminar Archivos 1 y 2");
	printf("\n(0)- SALIR.");
	
	printf("\n\nIngrese Opcion: ");
	scanf("%d", &opc);
	
	return opc;
}


void IngresarFraseJose(FILE *arch, char frase[80])
{
	arch = fopen("Archivo1.txt", "at");
	
	if(arch == NULL)
	{
		arch = fopen("Archivo1.txt", "wt");
	}
	
	printf("\n\nIngrese frase (ENTER para terminar): ");
	_flushall();
	gets(frase);
	
	fputs(strcat(frase, "\n"), arch);
	
	fclose(arch);
	
}

void IngresarFraseMaria(FILE *arch, char frase[80])
{
	arch = fopen("Archivo2.txt", "at");
	
	if(arch == NULL)
	{
		arch = fopen("Archivo2.txt", "wt");
	}
	
	printf("\n\nIngrese frase (ENTER para terminar): ");
	_flushall();
	gets(frase);
	
	fputs(strcat(frase, "\n"), arch);
	
	fclose(arch);
	
}


void MostrarFrasesDeJose(FILE *arch, char frases[80])
{
	arch = fopen("archivo1.txt","rt");
	
	if(arch != NULL)
	{
				
		fgets(frases, sizeof(frases), arch);
		
		while(!feof(arch))
		{
			strlwr(frases);
			printf("%s", frases);
			
			fgets(frases, sizeof(frases), arch);
			
		}
		
	}
	else
	{
		printf("\nEl archivo de Jose NO fue Creado.");
	}
	
	fclose(arch);
}



void MostrarFrasesDeMaria(FILE *arch, char frases[80])
{
	arch = fopen("archivo2.txt","rt");
	
	if(arch != NULL)
	{
		
		fgets(frases, sizeof(frases), arch);
		
		while(!feof(arch))
		{
			strupr(frases);
			printf("%s", frases);
			
			fgets(frases, sizeof(frases), arch);
			
		}
	}
	else
	{
		printf("\nEl archivo de Maria NO fue Creado.");
	}
	
	fclose(arch);
}



void CombinarFrases(FILE *arch1, FILE *arch2, FILE *arch3, char jose[80], char maria[80], char combinado[160])
{
	arch1 = fopen("archivo1.txt","rt");
	arch2 = fopen("archivo2.txt","rt");
	arch3 = fopen("archivo3.txt","wt");
	
	if((arch1 != NULL) && (arch2 != NULL))
	{
	
	
		fgets(jose, sizeof(arch1), arch1);
		fgets(maria, sizeof(arch2), arch2);
		
		while((!feof(arch1)) && (!feof(arch2)))
		{
		
			fputs(jose, arch3);
			fputs(maria, arch3);
			
			fgets(jose, sizeof(arch1), arch1);
			fgets(maria, sizeof(arch2), arch2);
	
		}
		
		while (!feof(arch1))	
		{
			fputs(jose, arch3);
			fgets(jose, sizeof(arch1), arch1);
		}
	
		while (!feof(arch2))	
		{
			fputs(maria, arch3);
			fgets(maria, sizeof(arch2),arch2);
		}
		
		printf("\nFrases Combinadas Exitosamente!!...\n\n");
	}
	else
	{
		printf("\n\nNo se creo archivo de Jose o Maria\n\n");
	}
	
	fclose(arch1);
	fclose(arch2);
	fclose(arch3);
}


void MostrarFrasesCombinadas(FILE *arch, char combinadas[160])
{
	arch = fopen("archivo3.txt","rt");
	
	if(arch != NULL)
	{
	
		fgets(combinadas, sizeof(combinadas), arch);
		
		while(!feof(arch))
		{
			printf("%s", combinadas);
			
			fgets(combinadas, sizeof(combinadas), arch);
		}
	
	}
	else
	{
		printf("\nLas Frases No fueron Combinadas.");
	}
	
	fclose(arch);
}



void Eliminar(FILE *arch1, FILE *arch2)
{
	remove("archivo1.txt");
	remove("archivo2.txt");
}

main()
{
	FILE *arch1;
	FILE *arch2;
	FILE *arch3;
	
	char fraseJose[80];
	char fraseMaria[80];
	char combinado[160];
	
	int opcion = 0;
	
	do
	{
		system("cls");
		opcion = Menu();
		system("cls");
	
		switch(opcion)
		{
			case 1:
				{
					printf("\n    -Ingresar Frases Jose Luis-");
					IngresarFraseJose(arch1, fraseJose);
					break;
				}
			case 2:
				{	
					printf("\n    -Ingresar Frases Maria Emilia-");
					IngresarFraseMaria(arch2, fraseMaria);
					break;
				}
			case 3:
				{	
					printf("\n     -Frases de Jose-\n\n");
					MostrarFrasesDeJose(arch1, fraseJose);
					printf("\n\n");
					system("pause");
					break;
				}
			case 4:
				{
					printf("\n     -Frases de Maria-\n\n");
					MostrarFrasesDeMaria(arch2, fraseMaria);
					printf("\n\n");
					system("pause");
					break;
				}
			case 5:
				{
					printf("\n     -Combinar Frases-\n\n");
					CombinarFrases(arch1, arch2, arch3, fraseJose, fraseMaria, combinado);
					system("pause");
					break;
				}
			case 6:
				{
					printf("\n     -Frases Combinadas-\n\n");
					MostrarFrasesCombinadas(arch3, combinado);
					printf("\n\n");
					system("pause");
					break;
				}
			case 7:
				{
					printf("\n     -Eliminar Archivos 1 y 2-\n\n");
					Eliminar(arch1, arch2);
					printf("Archivos Eliminados con Exito!!...\n\n");
					system("pause");
					break;
				}
			case 0:
				{
					printf("\nCerrando Programa...");
					break;
				}
		}
				
	}while(opcion != 0);
}














