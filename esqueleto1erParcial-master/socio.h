#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idSocio;
    int isEmpty;
    //-----------------
    char socioName[TEXT_SIZE];
    char sexo;
    char telephone[TEXT_SIZE];
    char eMail[TEXT_SIZE];
    char socioSurname[TEXT_SIZE];

}Socio;


#endif // SOCIO_H_INCLUDED

int socio_Inicializar(Socio array[], int size);                                    //cambiar socio
int socio_buscarEmpty(Socio array[], int size, int* posicion);                    //cambiar socio
int socio_buscarID(Socio array[], int size, int valorBuscado, int* posicion);                    //cambiar socio
int socio_buscarInt(Socio array[], int size, int valorBuscado, int* posicion);                    //cambiar socio
int socio_buscarString(Socio array[], int size, char* valorBuscado, int* indice);                    //cambiar socio
int socio_alta(Socio array[], int size, int* contadorID);                          //cambiar socio
int socio_baja(Socio array[], int sizeArray);                                      //cambiar socio
int socio_bajaValorRepetidoInt(Socio array[], int sizeArray, int valorBuscado);
int socio_modificar(Socio array[], int sizeArray);                                //cambiar socio
int socio_ordenarPorDobleCriterio(Socio array[],int size, int orderFirst, int orderSecond);                                  //cambiar socio
int socio_listar(Socio array[], int size);                      //cambiar socio


