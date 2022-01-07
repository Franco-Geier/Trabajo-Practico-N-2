#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Persona.h"
#include "funciones.h"



/**
 * \brief Obtiene el primer indice libre del array
 * \param array Array de Personas a ser analizada
 * \param limite Limite del array de Personas
 * \return Retorna el indice de la posicion vacia y -1 (ERROR)
 **/
int per_obtenerEspacioLibre(Persona array[], int limite)
{
    int retorno = -1;
    int i;

    if(array != NULL && limite > 0)
    {
        for(i = 0; i < limite; i++)
        {
            if(array[i].estado == 1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



/**
 * \brief Da de alta a una persona en una posicion del array
 * \param array Array de personas a ser dado de alta
 * \param limite Limite del array de personas
 * \param indice Posicion a ser dada de alta
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 **/
int per_altaArray(Persona array[], int limite, int indice)
{
    int retorno = -1;
    Persona bufferPersona;

    if(array != NULL && limite > 0 && indice < limite && indice >= 0)
    {
        if(!obtenerNombre(bufferPersona.nombre, NOMBRE_LEN, MAGENTA "\nIngrese el nombre de la persona: " RESET, RED "\nNombre incorrecto\n" RESET, 2) &&
           !obtenerNumeroEntero(&bufferPersona.edad, MAGENTA "\nIngrese la edad de la persona: " RESET, RED "\nEdad incorrecta [1 - 100]\n" RESET, 1, 100, 2) && 
           !obtenerNumeroEntero(&bufferPersona.dni, MAGENTA "\nIngrese el DNI de la persona: " RESET, RED "\nDNI incorrecto [20000000 - 50000000]\n" RESET, MIN_DNI, MAX_DNI, 2))
        {
            retorno = 0;
            bufferPersona.estado = 0;
            array[indice] = bufferPersona;
        }
    }
    return retorno;
}



/**
 * \brief Imprime los datos de una persona
 * \param pElemento Puntero a la persona que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 **/
int per_imprimir(Persona* pElemento)
{
    int retorno = 1;

    if(pElemento != NULL && pElemento->estado == 0)
    {
        retorno = 0;
        printf(BLUE "\nNombre: [%s] - Edad: [%d] - DNI: [%d]\n" RESET, pElemento->nombre, pElemento->edad, pElemento->dni);
    }
    return retorno;
}



/**
 * \brief Imprime el array de personas
 * \param array Array de personas a ser impreso
 * \param limite Limite del array de personas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 **/
int per_imprimirArray(Persona array[], int limite)
{
    int retorno = -1;
    int i;

    if(array != NULL && limite > 0)
    {
        retorno = 0;
        for(i = 0; i < limite; i++)
        {
            per_imprimir(&array[i]);
        }
    }
    return retorno;
}



/**
 * \brief Inicializa el array
 * \param array Array de personas a ser inicializado
 * \param limite Limite del array de personas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 **/
int per_inicializarArray(Persona array[], int limite)
{
    int retorno = -1;
    int i;

    if(array != NULL && limite > 0)
    {
        retorno = 0;
        for(i = 0; i < limite; i++)
        {
            array[i].estado = 1;
            array[i].edad = 0;
        }
    }
    return retorno;
}



/**
 * \brief Da de baja a un persona en una posicion del array
 * \param array Array de personas a ser dado de baja
 * \param limite Limite del array de personas
 * \param indice Posicion a ser dada de baja
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 **/
int per_bajaArray(Persona array[], int limite, int indice)
{
    int retorno = -1;

    if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].estado == 0)
    {
        array[indice].estado = 1;
        retorno = 0;
    }
    return retorno;
}



/**
 * \brief Ordenar el array de personas por nombre
 * \param array Array de personas a ser ordenado
 * \param limite Limite del array de personas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 **/
int per_ordenarPorNombre(Persona array[], int limite)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Persona buffer;

    if(array != NULL && limite > 0)
    {
        do
        {
            flagSwap = 0;

            for (i = 0; i < limite - 1; i++)
            {
                if(array[i].estado || array[i + 1].estado)
                {
                    continue;                
                }
                if(strncmp(array[i].nombre, array[i + 1].nombre, QTY_PERSONAS) > 0)
                {
                    flagSwap = 1;
                    buffer = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = buffer;
                }
            }
            limite--;
        }while(flagSwap);
        retorno = 0;
    }
    return retorno;
}



/**
 * \brief Obtiene el indice que coincide con el dni pasado por parametro.
 * \param array el array que se pasa como parametro.
 * \param limite Limite del array de Personas
 * \param dni el dni a ser buscado en el array.
 * \return el indice en donde se encuentra el elemento que coincide con el parametro dni o -1 (ERROR)
 **/
int per_buscarPorDni(Persona array[], int limite, int dni)
{
    int retorno = -1;
    int i;

    if(array != NULL && limite > 0)
    {
        for(i = 0; i < limite; i++)
        {
            if(array[i].dni == dni)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



/**
 * \brief Imprime grafico de barras de 3 grupos de edades, menores de 18, entre 19 a 35 y mayores de 35.
 * \param array El array personas a ordenar.
 * \param limite La longitud del array.
 * \return 0 (EXITO) y -1 (ERROR)
 **/
int per_imprimrGrafico(Persona array[], int limite)
{
    int retorno = -1;
    int i;
    int j;
    int mayor = 0;
    int filas;
    int contadores[3];

    if(array != NULL && limite > 0)
    {
        retorno = 0;
        system("cls");
        printf(BLUE  "\n-----------------------------\
                      \n|*    GRAFICO DE EDADES    *|\
                      \n-----------------------------\n\n" RESET);

        for(i = 0; i < 3; i++)
        {
            contadores[i] = 0;
        }

        for(i = 0; i < limite; i++)
        {
            if(array[i].edad < 18 && array[i].edad > 0 && array[i].estado == 0)
            {
                contadores[0]++;
            }
            else if(array[i].edad >= 18 && array[i].edad <= 35 && array[i].estado == 0)
            {
                contadores[1]++;
            }
            else if(array[i].edad > 35 && array[i].estado == 0)
            {
                contadores[2]++;
            }
        }

        if(contadores[0] >= contadores[1] && contadores[0] >= contadores[2])
        {
            mayor = contadores[0];
        }
        else if(contadores[1] >= contadores[0] && contadores[1] >= contadores[2])
        {
            mayor = contadores[1];
        }
        else
        {
            mayor = contadores[2];
        }
        
        filas = mayor;

        for(i = 0; i < mayor; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if(contadores[j] >= filas)
                {   
                    printf(GREEN " *   " RESET);
                }
                else
                {
                    printf(GREEN "     " RESET);
                }
            }
            filas--;
            printf("\n");
        }
        printf(RED "<18 19-35 >35\n\n" RESET);
    }
    return retorno;
}