#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
#include <string.h>

Persona* persona_new()
{
    return (Persona*) malloc(sizeof(Persona));
}

Persona* persona_newParametros(int id,int edad,char* nombre, char* apellido)
{
    return NULL;
}

int persona_delete(Persona* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int persona_setId(Persona* this, int value)
{
    int retorno = -1;
    if(this != NULL && value >= 0)
    {
        this->id = value;
        retorno = 0;
    }
    return retorno;
}

int persona_setEdad(Persona* this, int* pEdad)
{
int retorno = -1;
if(this != NULL && pEdad!=NULL)
    {
        *pEdad=this->edad;
        retorno = 0;
    }
    return retorno;


}

int persona_setApellido(Persona* this, char* pApellido)
{
int retorno = -1;
if(this != NULL && pApellido!=NULL)
    {
        strncpy(this->apellido,pApellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}



int persona_setNombre(Persona* this, char* pNombre)
{
int retorno = -1;
if(this != NULL && pNombre!=NULL)
    {
        strncpy(this->nombre,pNombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}






int persona_getId(Persona* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->id;
        retorno = 0;
    }
    return retorno;
}












//











