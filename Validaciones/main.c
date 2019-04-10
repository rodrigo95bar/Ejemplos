#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define LEN 5
int main()
{
  int myArray[LEN];


  getArray(int myArray,int LEN,"Ingrese un valor","Error");
  showArray(int myArray,int LEN);

  return 0;
}
