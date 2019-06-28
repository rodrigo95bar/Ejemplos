#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "entregas.h"
#include "controller.h"
#include "parser.h"
#include "arraynuevo.h"
#define TRIES 3


/** \brief Alta de fotos
 *
 * \param path char*
 * \param pArrayListFotos LinkedList*
 * \return int

 */

int controller_addFotos(LinkedList* pArrayListFotos)
{
    Fotos* newFotos;
    char bufferId[1500];
    char bufferTipo[1500];
    char bufferFecha[1500];
    char bufferCantidad[1500];
    char bufferPrecio[1500];
    char bufferCuit[1500];

    int retorno = -1;

    if(pArrayListFotos != NULL)
    {
        if((getStringNumerosInt(bufferId,"Ingrese id: ","Error",TRIES)== 0)
           &&(getStringLetras(bufferTipo,"Ingrese tipo: ","Error",TRIES) == 0)
                &&(getStringNumerosInt(bufferCantidad,"Ingrese cantidad: ","Error",TRIES) == 0)
                )
        {
            newFotos = fotos_newParametros(bufferId,bufferFecha,bufferTipo,bufferCantidad,bufferPrecio,bufferCuit);
            if(newFotos != NULL)
            {
                if(ll_add(pArrayListFotos,newFotos) == 0)
                    {
                       retorno = 0;
                    }
            }
        }
    }
    return retorno;
}



/** \brief Modificar datos de fotos
 *
 * \param path char*
 * \param pArrayListFotos LinkedList*
 * \return int
 *
 *\
int controller_modifyFotos(LinkedList* pArrayListFotos)
{
    Fotos* pFotos;
    int retorno = -1;
    int size;
    char bufferId[1500];
    int auxId;
    int idBuscado;
    char bufferTipo[1500];
    char bufferCantidad[1500];

    int i;
    int option;

    if (pArrayListFotos != NULL)
    {
        size = ll_len(pArrayListFotos);
        if(getStringNumerosInt(bufferId,"Ingrese el ID de la fotos que desea modificar: ","Error\n",TRIES) == 0)
        {
            auxId = atoi(bufferId);
            for (i=0; i<size; i++)
            {
                pFotos = ll_get(pArrayListFotos,i);
                if(auxId == fotos_getId(pFotos,&idBuscado))
                {
                    do
                    {
                        printf("Elija que desea modificar: \n");
                        printf("1- Tipo de la fotos\n2- Cantidad de la fotos\n"
                               "3- Peso de la fotos\n4- Salir\n");

                        getIntInRange(&option,"Ingrese Opcion: ","Error\n",1,4,TRIES);
                        switch (option)
                        {
                        case 1:
                            if(getStringLetras(bufferTipo,"Ingrese nuevo tipo: ","Error\n",TRIES) == 0)
                            {
                                fotos_setTipo(pFotos,bufferTipo);
                                retorno = 0;
                            }
                            break;
                        case 2:
                            if(getStringNumerosInt(bufferCantidad,"Ingrese nueva cantidad: ","Error\n",TRIES) == 0)
                            {
                                fotos_setCantidad(pFotos,bufferCantidad);
                                retorno = 0;
                            }
                            break;
                        case 3:

                            break;
                        }
                    }
                    while (option != 4);
                }
            }
        }
    }
    return retorno;
}

/** \brief Baja de fotos
 *
 * \param path char*
 * \param pArrayListFotos LinkedList*
 * \return int
 *
 *

 */
int controller_removeFotos(LinkedList* pArrayListFotos)
{
    Fotos* pFotos;
    int retorno = -1;
    int size;
    char bufferId[1500];
    int auxId;
    int idBuscado;
    int i;

    if (pArrayListFotos != NULL)
    {
        size = ll_len(pArrayListFotos);
        if(getStringNumerosInt(bufferId,"Ingrese el ID de la fotos que desea bajar: ","Error\n",TRIES) == 0)
        {
            auxId = atoi(bufferId);
            for (i=0; i<size; i++)
            {
                pFotos = ll_get(pArrayListFotos,i);
                if(auxId == fotos_getId(pFotos,&idBuscado))
                {
                    ll_remove(pArrayListFotos,i);
                    fotos_delete(pFotos);
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}


/** \brief Listar fotoss
 *
 * \param path char*
 * \param pArrayListFotos LinkedList*
 * \return int
 *
 */
int controller_listFotos(LinkedList* pArrayListFotos)
{
    Fotos* pE;
    int auxId;
    int auxCantidad;
    int auxPrecio;
    char auxTipo[1500];
    char auxFecha[1500];
    char auxCuit[1500];
    int size;
    int i;

    if(pArrayListFotos != NULL)
    {
        size = ll_len(pArrayListFotos);
        for(i=0; i<size; i++)
        {
            pE = ll_get(pArrayListFotos,i);
            fotos_getId(pE,&auxId);
            fotos_getTipo(pE,auxTipo);
            fotos_getCantidad(pE,&auxCantidad);
            fotos_getPrecio(pE,&auxPrecio);
            fotos_getCuit(pE,auxCuit);
            fotos_getFecha(pE,auxFecha);

            if(pE != NULL)
            {
                printf("%d\t %s\t %s\t %d\t %d\t %s\t\n",auxId,
                                            auxFecha,
                                            auxTipo,
                                            auxCantidad,
                                            auxPrecio,
                                            auxCuit);
            }
        }
    }
    return 0;
}

/** \brief Ordenar fotoss
 *
 * \param path char*
 * \param pArrayListFotos LinkedList*
 * \return int
 *
 */
int controller_sortFotos(LinkedList* pArrayListFotos)
{
    int retorno = -1;

    if(pArrayListFotos != NULL)
    {
        ll_sort(pArrayListFotos,fotos_sortByTipo,1);
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda los datos de los fotoss en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListFotos LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListFotos)
{
    Fotos* pE;
    int auxId;

    int auxCantidad;
    char auxTipo[1500];
    char auxFecha[1500];
    char auxCuit[1500];
    int auxPrecio;
    int size;
    int i;
    int retorno = 1;

    FILE* fp = fopen(path,"w+");
    if(fp != NULL && pArrayListFotos != NULL)
    {
        fprintf(fp,"ID,Fecha,Tipo,Cantidad,Precio,Cuit\n");

        size = ll_len(pArrayListFotos);

        for(i=0;i<size;i++)
        {
            pE = ll_get(pArrayListFotos,i);
            fotos_getId(pE,&auxId);
            fotos_getFecha(pE,auxFecha);
            fotos_getTipo(pE,auxTipo);
            fotos_getCantidad(pE,&auxCantidad);
            fotos_getPrecio(pE,&auxPrecio);
            fotos_getCuit(pE,auxCuit);

            if(pE != NULL)
            {
                fprintf(fp,"%d,%s,%s,%d,%d,%s\n",auxId,
                                            auxFecha,
                                            auxTipo,
                                            auxCantidad,
                                            auxPrecio,
                                            auxCuit);
            }
        }
        fclose(fp);
        retorno = 0;
    }
    return retorno;
}
