#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>


typedef char string[30];

int Menu()
{
    int opcion = 0;

    printf("\n    -MENU-\n\n");
    printf("\n1)- Ingresar venta");
    printf("\n2)- Mostrar Ventas");
    printf("\n3)- Importe Por Vendedor");
    printf("\n4)- Importe por Mes");
    printf("\n5)- Ventas por Contado o Credito");
    printf("\n6)- Cambiar Metodo de Pago");
    printf("\n7)- Eliminar Venta Logicamente");
    printf("\n8)- Eliminar Venta Fisicamente");
    printf("\n9)- Mostrar Total de Ventas");
    printf("\n10)- Restaurar Ventas Eliminadas");
    printf("\n11)- Ordenar Archivo por Factura");
    printf("\n0)- SALIR");

    printf("\n\nIngrese Opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

struct Fecha
{
    int dd;
    int mm;
    int aaaa;
};

struct Venta
{
    int numVendedor;
    string nomVendedor;
    int numFactura;
    float montoVenta;
    int formaVenta;
    Fecha fech;
    bool borrado;
};


void IngresarVenta(FILE *arch)
{
	Venta reg;
	
	
	printf("\nNumero Vendedor: ");
    scanf("%d", &reg.numVendedor);
    while((reg.numVendedor < 1)||(reg.numVendedor > 3))
    {
        printf("\nERROR. El numero de empleado tiene que estar entre 1 - 3...\n\n");
        system("pause");
        system("cls");
	    printf("\nNumero Vendedor: ");
	    scanf("%d", &reg.numVendedor);
	}
	
    printf("Nombre vendedor: ");
    _flushall();
    gets(reg.nomVendedor);
    
    printf("Nro de Factura: ");
    scanf("%d", &reg.numFactura);
    
    printf("Monto de venta: ");
    scanf("%f", &reg.montoVenta);
    
    printf("Forma de pago 1(Contado) 2(Credito): ");
    scanf("%d", &reg.formaVenta);
    while((reg.formaVenta < 1)||(reg.formaVenta > 2))
    {
    	printf("\nla forma de pago solo puede ser 1 o 2... ");
    	printf("Forma de pago 1(Contado) 2(Credito): ");
    	scanf("%d", &reg.formaVenta);
													                                     
    }
    
    printf("\n\nFecha de venta\n");
    printf("DD: ");
    scanf("%d", &reg.fech.dd);
    printf("MM: ");
    scanf("%d", &reg.fech.mm);
    printf("AAAA: ");
    scanf("%d", &reg.fech.aaaa);
    
    reg.borrado = false;
    
    fseek(arch, 0, SEEK_END);
    
    fwrite(&reg, sizeof(Venta), 1, arch);
    
    printf("\n\nVenta registrada exitosamente!.\n");

}


void MostrarVentas(FILE *arch)
{
	Venta reg;
	
	rewind(arch);
	
	fread(&reg, sizeof(Venta), 1, arch);
	
	while(!feof(arch))
	{
		
		if(reg.borrado == false)
		{
		
			printf("\n\n\nNumero de Vendedor: %d", reg.numVendedor);
			printf("\nNombre de Vendedor: %s", reg.nomVendedor);
			printf("\nNumero de Factura: %d", reg.numFactura);
			printf("\nMonto: %.2f", reg.montoVenta);
			switch(reg.formaVenta)
			{
				case 1:printf("\nForma de pago: Contado");
				break;
				
				case 2:printf("\nForma de pago: Credito");
				break;
			}
			
			printf("\nFecha de venta: %d/%d/%d", reg.fech.dd, reg.fech.mm, reg.fech.aaaa);
		}	
			fread(&reg, sizeof(Venta), 1, arch);	
	}	
}


void CalcularImportePorVendedor(FILE *arch)
{
	Venta reg;
	
	string apeNom;
	int suma = 0;
	int numComparacion = 0;
	
	rewind(arch);
	
	suma = 0;
	bool encontrado;
	
	printf("\nIngrese Apellido y Nombre del vendedor: ");
	_flushall();
	gets(apeNom);
	
	fread(&reg, sizeof(Venta), 1, arch);
	
	while(!feof(arch))
	{
		
		if(reg.borrado == false)
		{
			numComparacion = strcmp(apeNom, reg.nomVendedor);
			
			if(numComparacion == 0)
			{
				suma = suma + reg.montoVenta;
				encontrado = true;
			}
			
		}
		
		
		fread(&reg, sizeof(Venta), 1, arch);
	}
	
	if(encontrado == true)
	{
		printf("\nEl importe realizado por el vendedor es: $%d", suma);	
	}
	else
	{
		printf("\n\nEl Vendedor ingresado no se encuentra registrado en el sistema...\n");
	}	
}


void CalcularVentaPorMes(FILE *arch)
{
	Venta reg;
	
	rewind(arch);
	
	int mesBuscar = 0;
	bool encontrado;
	int suma = 0;
	
	printf("\nIngrese Mes: ");
	scanf("%d", &mesBuscar);
	
	fread(&reg, sizeof(Venta), 1, arch);
	
	while(!feof(arch))
	{
		if(reg.borrado == false)
		{
			if(mesBuscar == reg.fech.mm)
			{
				suma = suma + reg.montoVenta;
				encontrado = true;
			}
			
		}
		
		fread(&reg, sizeof(Venta), 1, arch);
		
	}
	
	if(encontrado == true)
	{
		switch(mesBuscar)
		{
			case 1:
				{
					printf("\nEl importe en el mes de ENERO fue: %d",suma);
					break;
				}	
			case 2:
				{
					printf("\nEl importe en el mes de FEBRERO fue: %d",suma);
					break;
				}
			case 3:
				{
					printf("\nEl importe en el mes de MARZO fue: %d",suma);
					break;
				}
			case 4:
				{
					printf("\nEl importe en el mes de ABRIL fue: %d",suma);
					break;
				}
			case 5:
				{
					printf("\nEl importe en el mes de MAYO fue: %d",suma);
					break;
				}
			case 6:
				{
					printf("\nEl importe en el mes de JUNIO fue: %d",suma);
					break;
				}
			case 7:
				{
					printf("\nEl importe en el mes de JULIO fue: %d",suma);
					break;
				}
			case 8:
				{
					printf("\nEl importe en el mes de AGOSTO fue: %d",suma);
					break;
				}
			case 9:
				{
					printf("\nEl importe en el mes de SEPTIEMBRE fue: %d",suma);
					break;
				}
			case 10:
				{
					printf("\nEl importe en el mes de OCTUBRE fue: %d",suma);
					break;
				}
			case 11:
				{
					printf("\nEl importe en el mes de NOVIEMBRE fue: %d",suma);
					break;
				}
			case 12:
				{
					printf("\nEl importe en el mes de DICIEMBRE fue: %d",suma);
					break;
				}
			default:
				{
					printf("\nEl Mes seleccionado no es Valido...");
					break;
				}
		}
	}
	else
	{
		printf("\nNo se registraron ventas en el Mes seleccionado...");
	}	
}

void CalcularVentaCreditoContado(FILE *arch)
{
	Venta reg;
	
	rewind(arch);
	
	int mesBuscar = 0;
	bool encontrado;
	int suma = 0;
	int contado = 0;
	int credito = 0;
	
	printf("\nIngrese Mes: ");
	scanf("%d", &mesBuscar);
	
	fread(&reg, sizeof(Venta), 1, arch);
	
	while(!feof(arch))
	{
		if(reg.borrado == false)
		{
			if(mesBuscar == reg.fech.mm)
			{
				encontrado = true;
				
				if(reg.formaVenta == 1)
				{
					contado++;
				}
				else
				{
					credito++;
				}
			}
			
		}
		
		fread(&reg, sizeof(Venta), 1, arch);
		
	}
	
	if(encontrado == true)
	{
		switch(mesBuscar)
		{
			case 1:
				{
					printf("\nEn el mes de ENERO se registraron  %d ventas de contado y %d a credito", contado ,credito);
					break;
				}	
			case 2:
				{
					printf("\nEn el mes de FEBRERO se registraron %d ventas de contado y %d a credito", contado ,credito);
					break;
				}
			case 3:
				{
					printf("\nEn el mes de MARZO  se registraron %d ventas de contado y %d a credito", contado ,credito);
					break;
				}
			case 4:
				{
					printf("\nEn el mes de ABRIL  se registraron %d ventas de contado y %d a credito", contado ,credito);
					break;
				}
			case 5:
				{
					printf("\nEn el mes de MAYO  se registraron %d ventas de contado y %d a credito", contado ,credito);
					break;
				}
			case 6:
				{	
					printf("\nEn el mes de JUNIO se registraon %d ventas de contado y %d a credito", contado ,credito);
					break;
				}
			case 7:
				{	
					printf("\nEn el mes de JULIO se registraon %d ventas de contado y %d a credito", contado ,credito);
					break;
				}
			case 8:
				{
					printf("\nEn el mes de AGOSTO se registraon %d ventas de contado y %d a credito", contado ,credito);
					break;
				}
			case 9:
				{
					printf("\nEn el mes de SEPTIEMBRE se registraon %d ventas de contado y %d a credito", contado ,credito);
					break;
				}
			case 10:
				{
					printf("\nEn el mes de OCTUBRE se registraon %d ventas de contado y %d a credito", contado ,credito);
					break;
				}
			case 11:
				{	
					printf("\nEn el mes de NOVIEMBRE se registraon %d ventas de contado y %d a credito", contado ,credito);
					break;
				}
			case 12:
				{
					printf("\nEn el mes de DICIEMBRE se registraon %d ventas de contado y %d a credito", contado ,credito);
					break;
				}
			default:
				{
					printf("\nEl Mes seleccionado no es Valido...");
					break;
				}
		}
	}
	else
	{
		printf("\nNo se registraron ventas en el Mes seleccionado...");
	}	
}

	
	

void CambiarMetodoDePago(FILE *arch)
{
	Venta reg;
	
	int aBuscar = 0;
	bool encontrado = false;
	
	printf("\nIngrese Numero de Factura: ");
	scanf("%d", &aBuscar);

	rewind(arch);
	
	fread(&reg, sizeof(Venta), 1, arch);
	
	while((!feof(arch)) && (encontrado == false))
	{
		if(aBuscar == reg.numFactura && reg.borrado == false)
		{
			switch(reg.formaVenta)
			{
				case 1: printf("\nAnterior Meotodo: CONTADO"); break;
				
				case 2: printf("\nAnterior Meotodo: CREDITO"); break;
			}
			
			printf("\nIngrese nuevo metodo de Pago 1(Contado), 2(Credito): ");
			scanf("%d", &reg.formaVenta);
			
			while((reg.formaVenta < 1) || (reg.formaVenta > 2))
			    {
			    	printf("\nEl metodo de pago solo puede ser 1 o 2... ");
			    	printf("\n\nIngrese nuevo metodo de Pago 1(Contado) 2(Credito): ");
			    	scanf("%d", &reg.formaVenta);
																                                     
			    }
			
			fseek(arch, (long) -sizeof(Venta), SEEK_CUR);
			fwrite(&reg, sizeof(Venta), 1, arch);
			
			printf("\nMetodo de pago cambiado exitosamente...");
			
			encontrado = true;
			
		}
		else
		{
			fread(&reg, sizeof(Venta), 1, arch);
		}
		
	}
	
	if(encontrado == false)
	{
		printf("\nNo se encontro Nro de Factura...");
	} 

}


void EliminarLogicamente(FILE *arch)
{
	Venta reg;
	
	int aBuscar = 0;
	bool encontrado;
	int confirm;
	
	printf("\nIngrese Numero de Factura a Eliminar: ");
	scanf("%d", &aBuscar);
	
	rewind(arch);
	
	fread(&reg, sizeof(Venta), 1, arch);
	
	encontrado = false;
	
	while(!feof(arch) && encontrado == false)
	{
		if(reg.numFactura == aBuscar && reg.borrado == false)
		{
			encontrado = true;	
				
			printf("\nSeguro quiere Eliminar logicamente la venta de: %s", reg.nomVendedor);
			printf("\nNro de Factura: %d", reg.numFactura);
			
			printf("\n\n1 para si/2 para no: ");
			scanf("%d", &confirm);
			
			if(confirm == 1)
			{
				
				reg.borrado = true;
					
				fseek(arch, (long) -sizeof(Venta), SEEK_CUR);
								
				fwrite(&reg, sizeof(Venta), 1, arch);
				
				printf("\nVenta Eliminada de Manera Logica correctamente...");
				
			}
			else
			{
				printf("\nBorrado Cancelado...");
			}
		}
		else
		{
			fread(&reg, sizeof(Venta), 1, arch);
		}
	
	}
	
	if(encontrado == false)
	{
		printf("\nNo se encontro Nro de Factura...");
	} 	
}



void MostrarTotalVentas(FILE *arch)
{
	Venta reg;
	
	rewind(arch);
	
	fread(&reg, sizeof(Venta), 1, arch);
	
	while(!feof(arch))
	{
		
		printf("\n\n\nNumero de Vendedor: %d", reg.numVendedor);
		printf("\nNombre de Vendedor: %s", reg.nomVendedor);
		printf("\nNumero de Factura: %d", reg.numFactura);
		printf("\nMonto: %.2f", reg.montoVenta);
		switch(reg.formaVenta)
		{
			case 1:printf("\nForma de pago: Contado");
			break;
				
			case 2:printf("\nForma de pago: Credito");
			break;
		}
			
		printf("\nFecha de venta: %d/%d/%d", reg.fech.dd, reg.fech.mm, reg.fech.aaaa);
		
		if(reg.borrado == false)
		{
			printf("\nEstado: ACTIVO");
		}
		else
		{
			printf("\nEstado: BORRADO");
		}
		
		fread(&reg, sizeof(Venta), 1, arch);	
	}		
}



void RestaurarVentaEliminada(FILE *arch)
{
	Venta reg;
	
	int aBuscar = 0;
	bool encontrado = false;
	
	rewind(arch);
	
	printf("\nIngrese Numero de Factura a Restaurar: ");
	scanf("%d", &aBuscar);
	
	fread(&reg, sizeof(Venta), 1, arch);
	
	while((!feof(arch)) && (encontrado == false))
	{
		if(reg.numFactura == aBuscar)
		{
			
			encontrado = true;
				
			reg.borrado = false;
				
			fseek(arch, (long) -sizeof(Venta), SEEK_CUR);
			fwrite(&reg, sizeof(Venta), 1, arch);
			
			printf("\nVenta Restaurada Correctamente...");
		
		}
		else
		{
			fread(&reg, sizeof(Venta), 1, arch);
		}
	
	}
	
	if(encontrado == false)
	{
		printf("\nNo se encontro Nro de Factura...");
	} 
}


void OrdenarPorFactura(FILE *arch)
{
	int cont = 0;
	Venta reg;
	Venta vec[20];
	bool band = false;
	int L = 0;
	Venta aux;
	char confirm;
	
	rewind(arch);
	
	fread(&reg, sizeof(Venta), 1, arch);
	
	while(!feof(arch))
	{
		vec[cont] = reg;
		
		fread(&reg, sizeof(Venta), 1, arch);
		cont++;	
	}
	
	L = cont - 1;
	
	do
	{
		band = false;
		
		for(int i = 0; i < L; i++)
		{	
			if(vec[i].borrado == false)
			{
				if(vec[i].numFactura > vec[i+1].numFactura)
				{
					aux = vec[i];
					vec[i] = vec[i+1];
					vec[i+1] = aux;
					
					band = true;
				}	
			}	
		}
		L--;
		
	}while(band == true);
	
	printf("\nArchivo Ordenado Correctamente!!...\n");
	printf("\nDesea Listarlo s/n: ");
	_flushall();
	scanf("%c", &confirm);
	
	if(confirm == 's' || confirm == 'S')
	{
		for(int i = 0; i < cont; i++)
		{	
			
			if(vec[i].borrado == false)
			{
				printf("\n\n\nNumero de Vendedor: %d", vec[i].numVendedor);
				printf("\nNombre de Vendedor: %s", vec[i].nomVendedor);
				printf("\nNumero de Factura: %d", vec[i].numFactura);
				printf("\nMonto: %.2f", vec[i].montoVenta);
				switch(vec[i].formaVenta)
				{
					case 1:printf("\nForma de pago: Contado");
					break;
					
					case 2:printf("\nForma de pago: Credito");
					break;
				}
				
				printf("\nFecha de venta: %d/%d/%d", vec[i].fech.dd, vec[i].fech.mm, vec[i].fech.aaaa);
					
			}
			
		}
		
	}	
}


void BorradoFisico(FILE *arch, FILE *aux)
{
	Venta reg;
	char confirm;

	aux = fopen("auxiliar.dat","r+b");
	
	if(aux == NULL)
	{
		aux = fopen("auxiliar.dat","w+b");
	}

	printf("\nSeguro quiere Eliminar Permanentemente Todas las ventas marcadas como Borrado Logico s/n: ");
	_flushall();
	scanf("%c", &confirm);
	
	if(confirm == 'S' || confirm == 's')
	{	
		
		rewind(arch);
		
		fread(&reg, sizeof(Venta), 1, arch);
		
		while(!feof(arch))
		{
			if(reg.borrado == false)
			{
				fwrite(&reg, sizeof(Venta), 1, aux);
			}
			
			fread(&reg, sizeof(Venta), 1, arch);
		}
		
		fclose(arch);
		fclose(aux);
		
		remove("ventas.dat");
		rename("auxiliar.dat","ventas.dat");
		
		printf("\nArchivos Marcados como Borrado Logico Eliminados Permanentemente...");
	}
}

main()
{
    FILE *arch_vent;
    
    FILE *auxiliar;
    
    int opc;

    arch_vent = fopen("ventas.dat","r+b");

    if(arch_vent == NULL)
    {
       arch_vent = fopen("ventas.dat","w+b");

       if(arch_vent == NULL)
       {
           printf("\nERROR. No se pudo abrir el archivo");
           exit(1);
       }
    }

		
	
	do
	{
		system("cls");	
		opc = Menu();
		system("cls");
	
		    switch (opc)
		    {
			    case 1: 
			        {
			        	system("cls");
			            printf("\n-Ingresar Venta-\n\n");
			            IngresarVenta(arch_vent);
			            printf("\n\n");
			            break;
			        }
			        
			    case 2: 
			        {
			        	system("cls");
			            printf("\n-Mostrar Ventas-\n");
			            MostrarVentas(arch_vent);
			            printf("\n\n");
			            break;
			        }  
			        
				case 3: 
			        {
			        	system("cls");
			            printf("\n-Importe por Vendedor-\n");
			            CalcularImportePorVendedor(arch_vent);
			            printf("\n\n");
			            break;
			        } 
					
				case 4: 
			        {
			        	system("cls");
			            printf("\n-Importe por Mes-\n");
			            CalcularVentaPorMes(arch_vent);
			            printf("\n\n");
			            break;
			        } 
					
				case 5: 
			        {
			        	system("cls");
			            printf("\n-Importe por Mes-\n");
			            CalcularVentaCreditoContado(arch_vent);
			            printf("\n\n");
			            break;
			        } 
					
				case 6: 
			        {
			        	system("cls");
			            printf("\n-Cambiar Metodo de Pago-\n");
			            CambiarMetodoDePago(arch_vent);
			            printf("\n\n");
			            break;
			        }  
			        
			        
			    case 7: 
			        {
			        	system("cls");
			            printf("\n-Eliminacion Logica-\n");
			            EliminarLogicamente(arch_vent);
			            printf("\n\n");
			            break;
			        }
			    case 8: 
			        {
			        	system("cls");
			            printf("\n-Eliminacion Fisica de Ventas en Borrado Logico-\n");
						BorradoFisico(arch_vent, auxiliar);
			            printf("\n\n");
			            break;
			        }
			        
			              
			    case 9: 
			        {
			        	system("cls");
			            printf("\n-Mostrar Total de Ventas-\n");
			            MostrarTotalVentas(arch_vent);
			            printf("\n\n");
			            break;
			        } 
			        
			    case 10: 
			        {
			        	system("cls");
			            printf("\n-Restaurar Venta Eliminada-\n");
			            RestaurarVentaEliminada(arch_vent);
			            printf("\n\n");
			            break;
			        }
			        
			    case 11: 
			        {
			        	system("cls");
			            printf("\n-Ordenar Archivo por Nro de Factura-\n");
						OrdenarPorFactura(arch_vent);
			            printf("\n\n");
			            break;
			        }
			        
			        		
				case 0: 
			        {
			        	system("cls");
			            printf("\n\nCerrando Programa...");
			            printf("\n\n");
			            break;
			        } 
		        
		        
		    
			    default:
			    	{
			    		printf("\nLa opcion elegida no se encuentra en el MENU...\n\n");
			    		
			    	}
			        break;
		    }
		    
		    system("pause");
		    
	}while(opc != 0);
	
	fclose(arch_vent);
}
