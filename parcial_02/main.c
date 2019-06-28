#include <stdio.h>
#include <stdlib.h>
#include "arraynuevo.h"
#include "informes.h"
#include "controller.h"
#include "entregas.h"
#include "parser.h"
#include "LinkedList.h"


int main()
{
    // Definir lista de empleados
    LinkedList* listaFotos = ll_newLinkedList();

    // Leer empleados de archivo data.csv
    if(parser_parseFotosText("data.csv",listaFotos) == 1)
    {
        // Generar archivo de salida
        if(generarArchivoInformes("informes.txt",listaFotos) == 1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
        {
            printf("Error generando archivo\n");
        }

    }
    else
        printf("Error leyando empleados\n");


    return 0;
}
