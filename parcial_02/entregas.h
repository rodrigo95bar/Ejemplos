#ifndef ENTREGAS_H_INCLUDED
#define ENTREGAS_H_INCLUDED

typedef struct
{
    int id; /// se va autoincrementando
    char tipo[50];
    char fecha[50];
    int precio;
    int cantidad;
    char cuit[50];

}Fotos;

Fotos* fotos_new();
Fotos* fotos_newParametros(char* idStr,char* fechaStr,char* tipoStr,char* cantidadStr,char* precioStr,char* cuitStr);
//Fotos* fotos_newParametrosConInt(int id,char* nombreStr,char* apellidoStr,char* dniStr);
int fotos_delete(Fotos* this);

int fotos_setIdStr(Fotos* this, char* value);
int fotos_setId(Fotos* this,int value);
int fotos_getId(Fotos* this,int* value);

int fotos_setTipo(Fotos* this,char* value);
int fotos_getTipo(Fotos* this,char* value);

int fotos_setCantidad(Fotos* this,char* value);
int fotos_getCantidad(Fotos* this,int* value);

int fotos_setPrecio(Fotos* this,char* value);
int fotos_getPrecio(Fotos* this,int* value);

int fotos_setFecha(Fotos* this,char* value);
int fotos_getFecha(Fotos* this,char* value);

int fotos_setCuit(Fotos* this,char* value);
int fotos_getCuit(Fotos* this,char* value);

int fotos_sortByTipo(void* pFirstFotos,void* pSecondFotos);
int fotos_contarByTipo1(void* pFotos);
int fotos_contarByTipo2(void* pFirstFoto);
int fotos_contarByTipo3(void* pFirstFoto);
int fotos_contarByTipo4(void* pFirstFoto);
int fotos_contarByTipo5(void* pFirstFoto);
int fotos_contarByTipo6(void* pFirstFoto);

int fotos_contarCantidad(void* pFirstFoto);
int fotos_contarPeso(void* pFirstFoto);

#endif // ENTREGAS_H_INCLUDED
