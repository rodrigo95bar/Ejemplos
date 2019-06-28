#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "entregas.h"


Fotos* fotos_new()
{
    return (Fotos*) malloc(sizeof(Fotos));
}

Fotos* fotos_newParametros(char* idStr,char* fechaStr,char* tipoStr,char* cantidadStr,char* precioStr,char* cuitStr)
{

    Fotos* client = fotos_new();
    if(client!=NULL)
    {
        fotos_setIdStr(client,idStr);
        fotos_setFecha(client,fechaStr);
        fotos_setTipo(client,tipoStr);
        fotos_setCantidad(client,cantidadStr);
        fotos_setPrecio(client,precioStr);
        fotos_setCuit(client,cuitStr);
    }
    return client;
}

/*Fotos* fotos_newParametrosConInt(int id,char* nombreStr,char* apellidoStr,char* dniStr)
{

    Fotos* client = fotos_new();
    if(client!=NULL)
    {
        fotos_setId(client,id);
        fotos_setTipo(client,nombreStr);
        fotos_setCantidad(client,apellidoStr);
        fotos_setPeso(client,dniStr);
    }
    return client;
}*/

int fotos_delete(Fotos* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int fotos_setIdStr(Fotos* this, char* value)
{
    int auxId;
    int retorno = -1;

    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxId = atoi(value);
        if(auxId > 0)
        {
            this->id = auxId;
            retorno = 0;
        }
    }
    return retorno;
}

/*int fotos_setId(Fotos* this,int value)
{
    int retorno  =-1;
    if (this!=NULL && value > 0)
    {
        this->idFotos = value;
        retorno = 0;
    }
    return retorno;
}*/


int fotos_setTipo(Fotos* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL && isLetter(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->tipo,value,sizeof(this->tipo));
            retorno = 0;
        }
    }
    return retorno;
}

int fotos_setPrecio(Fotos* this, char* value)
{
    int auxPrecio;
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        auxPrecio = atoi(value);
        if(auxPrecio > 0)
        {
            this->precio = auxPrecio;
            retorno = 0;
        }
    }
    return retorno;
}


int fotos_setCantidad(Fotos* this,char* value)
{
    int retorno = -1;
    int auxCantidad;
    if(this != NULL && value != NULL && isNumberInt(value))
    {
        auxCantidad = atoi(value);
        if(auxCantidad > 0)
        {
            this->cantidad = auxCantidad;
            retorno = 0;
        }
    }
    return retorno;
}



int fotos_setFecha(Fotos* this,char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        if(strlen(value) > 0)
        {
            strncpy(this->fecha,value,sizeof(this->fecha));
            retorno = 0;
        }
    }
    return retorno;
}


int fotos_setCuit(Fotos* this,char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        if(strlen(value) > 0)
        {
            strncpy(this->cuit,value,sizeof(this->cuit));
            retorno = 0;
        }
    }
    return retorno;
}



int fotos_getTipo(Fotos* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}


int fotos_getCuit(Fotos* this,char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->cuit,sizeof(this->cuit));
        retorno = 0;
    }
    return retorno;
}



int fotos_getFecha(Fotos* this,char* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        strncpy(value,this->fecha,sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}


int fotos_getCantidad(Fotos* this,int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->cantidad;
        retorno = 0;
    }
    return retorno;
}

int fotos_getId(Fotos* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->id;
        retorno = 0;
    }
    return retorno;
}



int fotos_getPrecio(Fotos* this,int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->precio;
        retorno = 0;
    }
    return retorno;
}








int fotos_initArray(Fotos* arrayFotos[],int lenFotos)
{
    int i;
    int retorno = -1;
    if(arrayFotos != NULL && lenFotos > 0)
    {
        for(i=0; i<lenFotos; i++)
        {
            arrayFotos[i] = NULL;
        }
        retorno = 0;

    }
    return retorno;
}

int fotos_findFree(Fotos* arrayFotos[], int lenFotos)
{
    int i;
    int ret = -1;
    if(arrayFotos != NULL && lenFotos > 0)
    {
        for(i=0; i<lenFotos; i++)
        {
            if(arrayFotos[i] == NULL)
            {
                ret = i;
                printf("\n----Se encontro lugar libre----\n");
                break;
            }
        }
    }
    return ret;
}

int fotos_sortByTipo(void* pFirstFotos,void* pSecondFotos)
{
    int retorno;
    Fotos* pFotosA;
    Fotos* pFotosB;

    pFotosA = (Fotos*) pFirstFotos;
    pFotosB = (Fotos*) pSecondFotos;

    if(strcmp(pFotosA->tipo,pFotosB->tipo) > 0)
    {
        retorno = 1;///mayor el primero
    }
    else if(strcmp(pFotosA->tipo,pFotosB->tipo) < 0)
    {
        retorno = -1;///menor el primero
    }
    else
    {
        retorno = 0;///ambos iguales
    }
    return retorno;
}

int fotos_contarByTipo1(void* pFirstFoto)
{
    int retorno = 0;
    Fotos* pFotos;

    pFotos = (Fotos*) pFirstFoto;

    if(strcmp(pFotos->tipo,"4R_10X15") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int fotos_contarByTipo2(void* pFirstFoto)
{
    int retorno = 0;
    Fotos* pFotos;

    pFotos = (Fotos*) pFirstFoto;

    if(strcmp(pFotos->tipo,"5R_13X18") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int fotos_contarByTipo3(void* pFirstFoto)
{
    int retorno = 0;
    Fotos* pFotos;

    pFotos = (Fotos*) pFirstFoto;

    if(strcmp(pFotos->tipo,"6R_15X20") == 0)
    {
        retorno = 1;///mayor el primero
    }

    return retorno;
}



int fotos_contarByTipo4(void* pFirstFoto)
{
    int retorno = 0;
    Fotos* pFotos;

    pFotos = (Fotos*) pFirstFoto;

    if(strcmp(pFotos->tipo,"8R_20X25") == 0)
    {
        retorno = 1;///mayor el primero
    }

    return retorno;
}

int fotos_contarByTipo5(void* pFirstFoto)
{
    int retorno = 0;
    Fotos* pFotos;

    pFotos = (Fotos*) pFirstFoto;

    if(strcmp(pFotos->tipo,"POLAROID_11X9") == 0)
    {
        retorno = 1;///mayor el primero
    }

    return retorno;
}

int fotos_contarByTipo6(void* pFirstFoto)
{
    int retorno = 0;
    Fotos* pFotos;

    pFotos = (Fotos*) pFirstFoto;

    if(strcmp(pFotos->tipo,"POLAROID_10X10") == 0)
    {
        retorno = 1;///mayor el primero
    }

    return retorno;
}

int fotos_contarCantidad(void* pFirstFoto)
{
    int retorno = -1;
    int cantidadReal;
    Fotos* pFotos;
    pFotos = (Fotos*) pFirstFoto;

    cantidadReal= atoi(pFotos->cantidad);
    if(pFotos != NULL && pFotos->cantidad >= 0 && isNumberInt(cantidadReal))
    {
        retorno = cantidadReal;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

/*
int fotos_contarPeso(void* pFirstFoto)
{
    int retorno = -1;
    Fotos* pFotos;
    pFotos = (Fotos*) pFirstFoto;

    if(pFotos != NULL && pFotos->peso >= 0)
    {
        retorno = pFotos->peso;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}
*/
