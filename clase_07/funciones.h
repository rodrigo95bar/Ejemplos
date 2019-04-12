#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int getString(  char *pResultado,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos);

int getNumber(  int *resultado,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos);

int isValidIntNumber (char* cadena);

int buscarLibre(char pArray[][56],int*pIndex,int len);

int showArray(int* pArray,int len);

int getArray(int* pArray,int len,char* msg, char* msgE);

int buscarNombre(char* pNombre,char pArray[][56],int len,int* pIndex);

#endif // FUNCIONES_H_INCLUDED
