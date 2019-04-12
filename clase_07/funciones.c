

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getString(  char *pResultado,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos)

{
    char bufferStr[4096];

    printf("%s",msg);
    fgets(bufferStr,sizeof(bufferStr),stdin);
    bufferStr[strlen(bufferStr)-1] = '\0'; //LE quita el primer caracter de terminal
    strncpy(pResultado,bufferStr,4096); //Destino,origen,maximo.

    return 0;

}

int isValidIntNumber (char* cadena)
{
    int retorno = 1;
    int i=0;
    if(cadena[i] == '-') //Con esta estructura puedo recorrer cualquier String.
    {
        i++;
    }
        for(;cadena [i] != '\0';i++)
        {
        if (cadena [i] < '0' && cadena [i] > '9')
        {
            retorno = 0;
            break;
        }

    }

    return retorno;

}

int getNumber(  int *resultado,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos)
{
    int retorno = -1;
    char bufferStr[4096];
    int bufferInt;

    if( resultado != NULL &&
        reintentos >= 0) //FALTAN
    {
        if(!getString(bufferStr,msg,msgError,1,6,1) &&
            isValidIntNumber(bufferStr))
        {
            bufferInt = atoi(bufferStr);
        }
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                retorno = 0;
                *resultado = bufferInt;
            }
        }
        return retorno;
 }


 int getArray(int* pArray,int len,char* msg, char* msgE)
{
    int i;
    int buffer;
    int ret;

    for(i=0;i<len;i++)
    {
        ret=getNumber(&buffer,msg, msgE,1,10,1);

        if(ret)
        {
            break;
        }
        *(pArray+i)=buffer;
    }
    return 0;
}

int showArray(int* pArray,int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        printf("%d\n",pArray[i]);
    }
    return 0;
}

int buscarLibre(char pArray[][56],int*pIndex,int len)
{
int i;
int ret=-1;
for(i=0;i<len;i++)
{
if (pArray[i][0] == '\0')
{
    *pIndex=i;
    ret=0;
    break;
}
}
 return ret;
}

int buscarNombre(char* pNombre,char pArray[][56],int len,int* pIndex)
{
int i;
int ret=-1;
    for(i=0;i<len;i++)
    {
        if(strcmp(pNombre,pArray[i])==0)
        {

        *pIndex = i;
        ret=0;
        break;
        }
    }
        return ret;
}
