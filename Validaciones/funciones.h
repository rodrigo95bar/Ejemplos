#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int utn_getNumber(int* pNumber, char* message, char* msgError);
int utn_addNumber(int numberA, int numberB, char* msgResult);
int utn_subtractNumber(int numberA, int numberB, char* msgResult);
int utn_multiplynumber(int numberA, int numberB, char* msgResult);
int utn_divideNumber(int numberA, int numberB, char* msgResult, char* msjError);
int utn_factorial(int number);
int utn_calculateAllFunctions(int numberA, int numberB);
int getChar(char* pChar, int len, char* msg);
int getArray(int* pArray,int len,char* msg, char* msgE);
int showArray(int* pArray,int len);
#endif // FUNCIONES_H_INCLUDED
