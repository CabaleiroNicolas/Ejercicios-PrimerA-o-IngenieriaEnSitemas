#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char cadena[200];

main()
{
	cadena poema;
	int longitud = 0;
	
	int vocales = 0;
	int mayusculas = 0;
	int minusculas = 0;
	int digitos = 0;
	int espacios = 0;
	int signos = 0;
	
	printf("\nIngrese el Poema\n\n: ");
	_flushall();
	gets(poema);
	longitud = strlen(poema);
	
	if(longitud <= 200)
	{
	
		
		for(int i = 0; i < longitud; i++)
		{
			switch(poema[i])
			{
				case 'a': case 'e':case 'i':case 'o':case 'u':case 'A':case 'E':case 'I':case 'O':case 'U':
					vocales++;
			}
			
			if(poema[i] >= 'a' && poema[i] <= 'z')
			{
				minusculas++;
			}
			if(poema[i] >= 'A' && poema[i] <= 'Z')
			{
				mayusculas++;
			}
			
			switch(poema[i])
			{
				case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':case '0':
					digitos++;
			}
			
			if(poema[i] == ' ')
			{
				espacios++;
			}
			
			switch(poema[i])
			{
				case ':':case',':case '.':case ';':case '-':case '_':case'{':case '}':case'+':case'"':case'#':case'%':case'/':case'(':case')':case'=':case'?':case'¿':case'!':case'¡':
					signos++;
			}
		}
		system("pause");
		printf("\n\n");
		system("cls");
		
		printf("\nEl siguiente poema: ");
		puts(poema);
		
		printf("\n\nTiene...");
		
		printf("\n Vocales: %d", vocales);
		printf("\n Mayusculas: %d", mayusculas);
		printf("\n Minusculas: %d", minusculas);
		printf("\n Digitos: %d", digitos);
		printf("\n Signos: %d", signos);
		printf("\n Espacios: %d", espacios);
		printf("\n Caracteres en Total: %d", longitud);
		
	}
	else
	{
		system("cls");
		printf("\nLa longitud del poema no puede ser mayor a 200 caracteres...");
	}
	
	printf("\n\n");
	system("pause");
}
