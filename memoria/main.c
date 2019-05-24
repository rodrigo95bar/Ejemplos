#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
#define QTY_ALUMNO 1000

int main()
{
    Persona* arrayPersonas[QTY_ALUMNO];
    Persona* pAux;
    pAux = persona_new();
    if(pAux != NULL)
    {
        persona_setId(pAux,44);
        arrayPersonas[0] = pAux;
    }


    pAux = persona_new();
    if(pAux != NULL)
    {
        persona_setId(pAux,14);
        arrayPersonas[1] = pAux;
    }

    pAux = persona_newParametros(11,11100,0,"Juan");
    if(pAux != NULL)
    {
        arrayPersonas[2] = pAux;
    }
    return 0;
}
