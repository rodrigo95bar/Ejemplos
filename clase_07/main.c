#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define LEN_LISTA 100
//#include "funciones.h"


int main()
{
    int opcion;
    char nombre [LEN_LISTA][56];
    int posLibre;
    char buffer[20];
    int posAeliminar;
    /*strncpy(nombre[0],"toto",20);
    strncpy(nombre[1],"pepe",20);
    printf("nombre:%s\n",nombre[0]);
    printf("nombre:%s\n",nombre[1]);
    */
    int i;
//Inicialización
    for(i=0;i<LEN_LISTA;i++)
    {
        nombre[i][0] = '\0';   //Para saber si esta vacio la posición del array.
        nombre[0][0] = 'A';
        nombre[1][0] = 'B';
    }
    while(1)
    {
        getNumber(&opcion,"n)Ingresar\n2)listar\n4)Eliminar\n","error",1,10,2); //Falta el 3: Ordenar.
        printf("Su numero es: %d\n",opcion);

        switch(opcion)
        {
            case 1:
            {
                printf("Agregar nombre\n");
                 if (buscarLibre(nombre,&posLibre,LEN_LISTA)==0)
                 {
                    printf("Se encontro lugar en %d\n",posLibre);
                    getString(buffer,"Ingrese\n","Error",0,20,2);
                    //fgets(buffer,20,stdin);
                    strncpy(nombre[posLibre],buffer,20);
                    printf("Se ingreso %s\n",buffer);

                    for(i=0;i<10;i++)
                    {
                        printf(" %d: %s\n",i,nombre[i]);
                    }
                 }
                    break;
            }
            case 4:
            {
                getString(buffer,"Ingrese\n","Error",0,20,2);
                //fgets(buffer,20,stdin);buffer[strlen(buffer)]

                buscarNombre(buffer,nombre,LEN_LISTA,&posAeliminar);
                break;
            }
        }

    }
    return 0;

}
