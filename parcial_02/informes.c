#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "informes.h"
#include "controller.h"
#include "entregas.h"
#include "parser.h"

int generarArchivoInformes(char* fileName,LinkedList* listaFotos)
{
    int size;
    int retorno = -1;
    int a4R_10X15;
    int b5R_13X18;
    int c6R_15X20;
    int d8R_20X25;
    int POLAROID_11X9;
    int POLAROID_10X10;
    int fotosMaxima;
    //int cantidadTotal;
    //float cantidadBultos;
    //float cantidadPesos;

    FILE* fp = fopen(fileName,"w+");
    if(fp != NULL && listaFotos!= NULL)
    {
        size = informe_cantidadTotalFotos(listaFotos);
        a4R_10X15 = informe_cantidadFotosPorTipo(listaFotos,1);
        b5R_13X18 = informe_cantidadFotosPorTipo(listaFotos,2);
        c6R_15X20 = informe_cantidadFotosPorTipo(listaFotos,3);
        d8R_20X25 = informe_cantidadFotosPorTipo(listaFotos,4);
        POLAROID_11X9 = informe_cantidadFotosPorTipo(listaFotos,5);
        POLAROID_10X10 = informe_cantidadFotosPorTipo(listaFotos,6);


       // fotosMaxima = informe_cantidadMaximaDeFotos(listaFotos);
        //cantidadBultos = informe_cantidadBultosPorEntrega(listaFotos);
        //cantidadPesos = informe_pesoTotalPorEntrega(listaFotos);

        fprintf(fp,"*******************\n");
        fprintf(fp,"Informe de ventas\n");
        fprintf(fp,"*******************\n");
        fprintf(fp,"- Cantidad total de fotos reveladas: %d\n",size);
        fprintf(fp,"- Cantidad de fotos por tipo POLAROID:  %d (POLAROID_11X9) %d (POLAROID_10X10) \n",POLAROID_11X9,POLAROID_10X10);
        fprintf(fp,"- Cantidad maxima de bultos fotosdos: %d\n",fotosMaxima);
        //fprintf(fp,"- Promedio de bultos por fotos: %.2f\n",cantidadBultos/size);
        //fprintf(fp,"- Promedio de peso por fotos: %.2f\n",cantidadPesos/size);
        fprintf(fp,"*******************");


        fclose(fp);
        retorno = 1;
    }
    return retorno;
}

int informe_cantidadTotalFotos(LinkedList* pArrayListFotos)
{
    int auxReturn = -1;
    int size;
    int i;
    int cantidadTotal;
    Fotos* pFotos;

      if(pArrayListFotos != NULL)
    {
        size = ll_len(pArrayListFotos);
        auxReturn = 0;
        for(i=0;i<size;i++)
        {
            pFotos = ll_get(pArrayListFotos,i);
            if(pFotos != NULL && pFotos->cantidad )
            {
                cantidadTotal += ll_contar(pArrayListFotos,fotos_contarCantidad);
            }

}
}
return auxReturn;
}

int informe_cantidadFotosPorTipo(LinkedList* pArrayListFotos,int tipo)
{
    int auxReturn = -1;
    int i;
    int size;

    if(pArrayListFotos != NULL && (tipo >= 1 || tipo <= 6))
    {
        size = ll_len(pArrayListFotos);
        auxReturn = 0;
        for(i=0;i<size;i++)
        {
            if(tipo == 1)
            {
                auxReturn = ll_contar(pArrayListFotos,fotos_contarByTipo1);
            }
            if(tipo == 2)
            {
                auxReturn = ll_contar(pArrayListFotos,fotos_contarByTipo2);
            }
            if(tipo == 3)
            {
                auxReturn = ll_contar(pArrayListFotos,fotos_contarByTipo3);
            }
            if(tipo == 4)
            {
                auxReturn = ll_contar(pArrayListFotos,fotos_contarByTipo4);
            }
            if(tipo == 5)
            {
                auxReturn = ll_contar(pArrayListFotos,fotos_contarByTipo5);
            }
            else
            {
                auxReturn = ll_contar(pArrayListFotos,fotos_contarByTipo6);
            }

        }
    }
    return auxReturn;
}
/*
int informe_cantidadMaximaDeFotos(LinkedList* pArrayListFotos)
{
    int auxReturn = -1;
    int i;
    int size;
    Fotos* pFotos;
    int maximo = 0;

    if(pArrayListFotos != NULL)
    {
        size = ll_len(pArrayListFotos);
        auxReturn = 0;
        for(i=0;i<size;i++)
        {
            pFotos = ll_get(pArrayListFotos,i);
            if(pFotos != NULL && pFotos->cantidad > maximo)
            {
                maximo = pFotos->cantidad;
            }
        }
        auxReturn = maximo;
    }

    return auxReturn;
}
*/
/*
int informe_cantidadBultosPorEntrega(LinkedList* pArrayListFotos)
{
    int auxReturn = -1;
    int i;
    int size;
    Fotos* pFotos;
    int cantidadTotal = 0;
    float promedio;

    if(pArrayListFotos != NULL)
    {
        size = ll_len(pArrayListFotos);
        auxReturn = 0;
        for(i=0;i<size;i++)
        {
            pFotos = ll_get(pArrayListFotos,i);
            if(pFotos != NULL && pFotos->cantidad )
            {
                cantidadTotal += ll_contar(pArrayListFotos,fotos_contarCantidad);
            }
        }
        promedio = (float)cantidadTotal/size;
        auxReturn = promedio;
    }
    return auxReturn;
}

*/

/*
int informe_pesoTotalPorEntrega(LinkedList* pArrayListFotos)
{
    int auxReturn = -1;
    int i;
    int size;
    Fotos* pFotos;
    float cantidadTotal = 0;
    float promedio;

    if(pArrayListFotos != NULL)
    {
        size = ll_len(pArrayListFotos);
        auxReturn = 0;
        for(i=0;i<size;i++)
        {
            pFotos = ll_get(pArrayListFotos,i);
            if(pFotos != NULL && pFotos->peso >= 0)
            {
                cantidadTotal += ll_contarFloat(pArrayListFotos,fotos_contarPeso);
            }
        }
        promedio = cantidadTotal/size;
        auxReturn = promedio;
    }
    return auxReturn;
}
*/
