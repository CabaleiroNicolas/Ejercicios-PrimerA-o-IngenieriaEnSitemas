#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int TAM = 100;

struct fecha{
    int dia;
    int mes;
    int anio;
};

struct datosCliente{
    char ApeNom[40]; 
    char dire[60]; 
    float monVehi;  
    fecha fecVenta; 
};


bool compararRegistros(fecha &A, fecha &B){
    if(A.dia == B.dia && A.mes == B.mes && A.anio == B.anio){
        return true;
    }
    return false;
}

void cargarVentas(datosCliente ventas[TAM], int tope){
    fecha fechas[TAM];
    int idxFechas = 0;

    float ventasTotales[TAM];

    printf("----- CARGUE LAS %d VENTAS EN LA SEMANA -----", tope);
    for(int i=0; i<tope; i++){
        printf("\n----- Venta %d -----", i+1);
        printf("\n\tFecha (si ingresa una fecha ya ingresada la venta se suma a ese dia):");
        printf("\n\t\tDia: ");
        scanf("%d", &ventas[i].fecVenta.dia);
        printf("\t\tMes: ");
        scanf("%d", &ventas[i].fecVenta.mes);
        printf("\t\tAnio: ");
        scanf("%d", &ventas[i].fecVenta.anio);

       
        bool existe = false;
        int c = 0;
        while(!existe && c < idxFechas){
            if(compararRegistros(ventas[i].fecVenta, fechas[c])){
                printf("\nEsa fecha fue ingresada (%d/%d/%d)", fechas[c].dia, fechas[c].mes, fechas[c].anio);
                existe = true;
            }else{
                c++;    
            }
        }
        if(!existe){
            printf("\nHa ingresado una nueva fecha.");
            fechas[idxFechas] = ventas[i].fecVenta;
            idxFechas++;
        }

        printf("\nDatos del cliente:");
        printf("\n\tApellido y nombre: ");
        _flushall();
        gets(ventas[i].ApeNom);
        printf("\tDireccion: ");
        _flushall();
        gets(ventas[i].dire);
        printf("\tMonto de venta: $");
        scanf("%f", &ventas[i].monVehi);

        
        if(!existe){
            ventasTotales[c] = ventas[i].monVehi;
        }else{
            ventasTotales[c] += ventas[i].monVehi;
        }
    }    

    printf("\n---- VENTAS ORDENADAS POR FECHA ----");
    for (int i = 0; i < idxFechas; i++){
        printf("\n");
        printf("#### %d/", fechas[i].dia);
        printf("%d/", fechas[i].mes);
        printf("%d #### : ", fechas[i].anio);
    
        printf(" $%.2f ", ventasTotales[i]);
    }


    
    float menorVenta = ventasTotales[0];
    int menorIdx = 0;

    printf("\n\n---- MENOR VENTA ----\n");
    for(int i=0; i<idxFechas; i++){
        if(ventasTotales[i] < menorVenta){
            menorIdx = i;
        }
    }
    printf("La menor venta fue en la fecha %d/%d/%d y fue de $%.2f", fechas[menorIdx].dia, fechas[menorIdx].mes, fechas[menorIdx].anio, ventasTotales[menorIdx]);
    
}

int main(){
    int N ;
    datosCliente ventas[TAM];

    printf("Ingrese N: ");
    scanf("%d", &N);

    cargarVentas(ventas, N);

}
