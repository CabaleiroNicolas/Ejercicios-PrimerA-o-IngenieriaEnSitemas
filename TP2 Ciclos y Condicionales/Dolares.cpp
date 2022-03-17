#include <stdio.h>
#include <stdlib.h>

main()
{
	int edad = 12;
	int ultimaCantidad = 10;
	int cantidad = 10;
	
	while(cantidad <= 1000)
	{		
		edad++;
		cantidad = cantidad * 2;
		ultimaCantidad = ultimaCantidad + cantidad;		
	}
	printf("\nLa cantidad final es: $%d", ultimaCantidad);
	printf("\nla edad final es: %d", edad);
	
	
	printf("\n\n\n");
	system("pause");
}

