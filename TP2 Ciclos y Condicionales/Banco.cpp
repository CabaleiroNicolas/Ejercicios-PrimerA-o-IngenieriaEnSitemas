#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>



main()
{
	int numeroCuenta = 0;
	int dni = 0;
	float saldo = 0;
	int cuentas = 0;
	float saldosAcreedores = 0;
	
	
	
	printf("Cuantas cuentas quiere ingresar? (0 para finalizar): ");
	scanf("%d", &cuentas);
	
	if(cuentas != 0)
	{

	for(int i = 1; cuentas >= i; i++)
	{
		
		
			
		printf("\n\n\n\nIngrese los datos de la cuenta %d de %d", i, cuentas);
		
		printf("\n\nNumero de cuenta: ");
		scanf("%d", &numeroCuenta);
		
		printf("\nDNI: ");
		scanf("%d", &dni);
		
		printf("\nSaldo de la cuenta: ");
		scanf("%f", &saldo);

		
		printf("\nDocumento: %d", dni);
		printf("\nNumero de cuenta: %d" ,numeroCuenta);
		
		if(saldo > 0)
		{
			printf("\nEstado de cuenta: Acreedor");
			saldosAcreedores = saldosAcreedores + saldo;
		}
		
		if(saldo == 0)
		{
			printf("\nEstado de cuenta: Nulo");
		}
		
		if(saldo < 0)
		{
			printf("\nEstado de cuenta: Deudor");
		}
		
		printf("\n____________________________________________");
		}
		
		printf("\n\nLa suma de los saldos acreedores es: %.2f\n\n", saldosAcreedores);

	}

	printf("\n\n");
	system("pause");
}
  	

  	

