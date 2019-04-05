#include <stdio.h>

int obtenerNumero (int *pNumero, char* mensaje)
{
   int numero;

   printf(mensaje);
   scanf("%d",&numero);
   *pNumero = numero;


   return 0;


}

int obtenerArray (int *pArray, int limite, char* mensaje)
{
 int i;
 int auxiliar;

 for(i=0;i<limite;i++){

 obtenerNumero(&auxiliar,mensaje);

 *(pArray + i) = auxiliar;

}

printf("%d",auxiliar);
return 0;
 }

