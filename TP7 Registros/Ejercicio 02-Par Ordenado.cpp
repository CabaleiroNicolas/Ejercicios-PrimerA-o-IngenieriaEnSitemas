#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct punto{
	int x;
	int y;	
};

main(){
	
punto P1;
punto P2;
float distancia;
float distanciaUnion;
printf("\nIngrese la coordenada x de P1: ");
scanf("%d",&P1.x);	
printf("\nIngrese la coordenada y de P1: ");
scanf("%d",&P1.y);
printf("\nIngrese la coordenada x de P2: ");
scanf("%d",&P2.x);	
printf("\nIngrese la coordenada y de P2: ");
scanf("%d",&P2.y);

printf("\nCOORDENADAS...");
printf("\nP1(%d,%d); P2(%d,%d)",P1.x,P1.y,P2.x,P2.y);

distancia=sqrt(pow(P1.x,2)+pow(P1.y,2));
printf("\n\nLa distancia que hay desde P1 hasta la ordenada al origen es %.2f",distancia);

distanciaUnion=sqrt(pow(P2.x-P1.x,2)+pow(P2.y-P1.y,2));
printf("\n\nLa longitud del segmento de recta que une los dos puntos es %.2f",distanciaUnion);	
}

