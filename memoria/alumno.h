
#ifndef ALUMNO_H
#define ALUMNO_H
#define QTY_NAME 32
struct S_Persona
{
    int id;
    char nombre[QTY_NAME];
    char apellido[QTY_NAME];
    int edad;


};
typedef struct S_Persona Persona;
#endif

Persona* persona_new();
Persona* persona_newParametros(int id,int edad,char* nombre, char* apellido);
int persona_delete(Persona* this);

int persona_setId(Persona* this, int value);
int persona_setEdad(Persona* this, int* pEdad);
int persona_setApellido(Persona* this, char* pApellido);
int persona_setNombre(Persona* this, char* pNombre);

int persona_getId(Persona* this, int* value);
int persona_getLegajo(Persona* this, int* value);
int persona_getStatus(Persona* this, int* value);
int persona_getNombre(Persona* this, char* value);











