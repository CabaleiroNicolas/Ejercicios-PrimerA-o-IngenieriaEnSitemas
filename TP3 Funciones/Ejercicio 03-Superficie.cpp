#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


int a;
int b;
const float PI = 3.14;


void CalMayMin(int &may, int &men)
{
	
	if(a > b)
	{
		may = a;
		men = b;
	}
	else
	{
		may = b;
		men = a;
	}
}

void AreaCuad(int may, int &supCua)
{
	supCua = may * may;
}

void AreaCir(int men, int &supCir )
{
	supCir = (PI) * (men * men);
}

main()
{
int may;
int men;
int supCua;
int supCir;


	printf("Ingrese dos numeros enteros distintos entre si: ");
	scanf("%d %d", &a, &b);
	
	CalMayMin(may, men);
	printf("\nMayor: %d\n", may);
	printf("Menor: %d\n", men);
	
	AreaCuad(may, supCua);
	printf("\nEl area del cuadrado es: %d\n\n", supCua);
	printf("______________________________________________\n\n");
	
system("pause");
system("cls");
	
	AreaCir(men, supCir);
	printf("\n\nEl area del circulo es: %d\n\n", supCir);
	printf("_______________________________________________\n\n");
	
system("pause");

}

