#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "LinkedList.h"

int generarArchivoInformes(char* fileName,LinkedList* listaFotos);

int informe_cantidadTotalFotos(LinkedList* pArrayListFotos);
int informe_cantidadFotosPorTipo(LinkedList* pArrayListFotos,int tipo);
//int informe_cantidadMaximaDeFotos(LinkedList* pArrayListFotos);
int informe_cantidadBultosPorEntrega(LinkedList* pArrayListFotos);
int informe_pesoTotalPorEntrega(LinkedList* pArrayListFotos);

#endif // INFORMES_H_INCLUDED
