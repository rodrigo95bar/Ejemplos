#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "entregas.h"
#include "arraynuevo.h"

int parser_parseFotosText(char* fileName, LinkedList* listaFotos)
{
    char bufferId[1500];
    char bufferFecha[1500];
    char bufferCantidad[1500];
    char bufferTipo[1500];
    char bufferPrecio[1500];
    char bufferCuit[1500];
    int cantidadDatos;
    Fotos* pFotos;
    int retorno = -1;

    FILE* pFile = fopen(fileName,"r");

            if(pFile != NULL)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                                bufferId,
                                bufferFecha,
                                bufferTipo,
                                bufferCantidad,
                                bufferPrecio,
                                bufferCuit);
                do
                {
                    cantidadDatos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                                                                        bufferId,
                                                                        bufferFecha,
                                                                        bufferTipo,
                                                                        bufferCantidad,
                                                                        bufferPrecio,
                                                                        bufferCuit);
                    if(cantidadDatos == 6)
                    {
                        pFotos = fotos_newParametros(bufferId,
                                                        bufferFecha,
                                                        bufferTipo,
                                                        bufferCantidad,
                                                        bufferPrecio,
                                                        bufferCuit);
                        if(pFotos != NULL)
                        {
                            if(ll_add(listaFotos,pFotos) == 0)
                            {
                                retorno = 1;
                            }
                        }
                    }
                }
                while(!feof(pFile));
                fclose(pFile);
            }
    return retorno; // OK
}
