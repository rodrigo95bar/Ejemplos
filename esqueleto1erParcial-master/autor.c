#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "autor.h" //cambiar por nombre entidad

#define  CANT_DIG_MIN   1
#define  CANT_DIG_MAX   10


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array autor Array of autor
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int autor_Inicializar(Autor array[], int size)                                    //cambiar autor
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array autor Array de autor
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int autor_buscarEmpty(Autor array[], int size, int* posicion)                    //cambiar autor
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array autor Array de autor
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int autor_buscarID(Autor array[], int size, int valorBuscado, int* posicion)                    //cambiar autor
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idAutor==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array autor Array de autor
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
/*int autor_buscarInt(Autor array[], int size, int valorBuscado, int* posicion)                    //cambiar autor
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].varInt==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
*/
//String
/** \brief Busca un string en un array
* \param array autor Array de autor
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int autor_buscarString(Autor array[], int size, char* valorBuscado, int* indice)                    //cambiar autor
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].name,valorBuscado)==0)                                        //cambiar campo name
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array autor Array de autor
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int autor_alta(Autor array[], int size, int* contadorID)                          //cambiar autor
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(autor_buscarEmpty(array,size,&posicion)==-1)                          //cambiar autor
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idAutor=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            //utn_getUnsignedInt("\ngetUnsignedInt: ","\nError",CANT_DIG_MIN,CANT_DIG_MAX,1,10,1,&array[posicion].varInt);           //mensaje + cambiar campo varInt
            //utn_getFloat("\ngetFloat: ","\nError",CANT_DIG_MIN,CANT_DIG_MAX,0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
            utn_getName("\ngetName: ","\nError",1,TEXT_SIZE,1,array[posicion].name);                      //mensaje + cambiar campo name
            utn_getTexto("\ngetTexto: ","\nError",1,TEXT_SIZE,1,array[posicion].surname);                 //mensaje + cambiar campo surname
            printf("\n Posicion: %d\n ID: %d\n  name: %s\n surname: %s",
                   posicion, array[posicion].idAutor,array[posicion].name,array[posicion].surname);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array autor Array de autor
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int autor_baja(Autor array[], int sizeArray)                                      //cambiar autor
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",CANT_DIG_MIN,CANT_DIG_MAX,1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(autor_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idAutor=0;                                                                   //cambiar campo id
            //array[posicion].varInt=0;                                                               //cambiar campo varInt
            //array[posicion].varFloat=0;                                                             //cambiar campo varFloat
            strcpy(array[posicion].name,"");                                                   //cambiar campo name
            strcpy(array[posicion].surname,"");                                               //cambiar campo surname
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array autor Array de autor
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int autor_bajaValorRepetidoInt(Autor array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idAutor==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idAutor=0;                                                                   //cambiar campo id
                //array[i].varInt=0;                                                               //cambiar campo varInt
                //array[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(array[i].name,"");                                                   //cambiar campo name
                strcpy(array[i].surname,"");                                               //cambiar campo surname
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array autor Array de autor
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int autor_modificar(Autor array[], int sizeArray)                                //cambiar autor
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",CANT_DIG_MIN,CANT_DIG_MAX,1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(autor_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n  name: %s\n surname: %s",
                       posicion, array[posicion].idAutor,array[posicion].name,array[posicion].surname);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        //utn_getUnsignedInt("\n: ","\nError",CANT_DIG_MIN,CANT_DIG_MAX,1,1,1,&array[posicion].varInt);           //mensaje + cambiar campo varInt
                        break;
                    case 'B':
                        //utn_getFloat("\n: ","\nError",CANT_DIG_MIN,CANT_DIG_MAX,0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
                        break;
                    case 'C':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].name);                      //mensaje + cambiar campo name
                        break;
                    case 'D':
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].surname);             //mensaje + cambiar campo surname
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array autor Array de autor
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
/*int autor_ordenarPorDobleCriterio(Autor array[],int size, int orderFirst, int orderSecond)                              //cambiar autor
{
    int retorno=-1;
    int i;
    Autor buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].name,array[i+1].name) < 0) && orderFirst) ||
                    ((strcmp(array[i].name,array[i+1].name) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
                else if(strcmp(array[i].name,array[i+1].name) == 0)
                {
                    if( ((array[i].varFloat < array[i+1].varFloat) && orderSecond) ||
                        ((array[i].varFloat > array[i+1].varFloat) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = array[i];
                        array[i] = array[i+1];
                        array[i+1] = buffer;
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}
*/
//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array autor Array de autor
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int autor_listar(Autor array[], int size)                      //cambiar autor
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n name: %s\n surname: %s",
                       array[i].idAutor,array[i].name,array[i].surname);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}



