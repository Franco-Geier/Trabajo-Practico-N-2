#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "Persona.h"

int main()
{
    char seguir = 's';
    int idPersonas = 0;
    int opcion = 0;
    int auxiliarIndice;
    int auxiliarDni;

    Persona arrayPersonas[QTY_PERSONAS];

    if(!per_inicializarArray(arrayPersonas, QTY_PERSONAS))
    {   system("cls");
        printf(GREEN "Array inicializado correctamente\n" RESET);
        system("pause");
    }

    while(seguir == 's')
    {
        system("cls");

        if(!obtenerNumeroEntero(   &opcion,
                            YELLOW "------------------------------------------\n" RESET
                   LIGHTGREEN BOLD "*            MENU DE OPCIONES            *\n" RESET
                            YELLOW "------------------------------------------\n" RESET
                              CYAN "* 1- Agregar persona                     *\n"
                                   "* 2- Borrar persona                      *\n"
                                   "* 3- Imprimir lista ordenada por nombre  *\n"
                                   "* 4- Imprimir grafico de edades          *\n"
                                   "* 5- Salir                               *\n" RESET
                            YELLOW "------------------------------------------\n\n" RESET
                           MAGENTA "Ingrese una opcion: " RESET,
                               RED "\nERROR, OPCION INVALIDA\n", 1, 5, 2)) RESET;

        switch(opcion)
        {
            case 1:
                system("cls");
                auxiliarIndice = per_obtenerEspacioLibre(arrayPersonas, QTY_PERSONAS);
                if(auxiliarIndice >= 0)
                {
                    if(!per_altaArray(arrayPersonas, QTY_PERSONAS, auxiliarIndice))
                    {
                        system("cls");    
                        printf(GREEN "\nCarga realizada con exito\n" RESET);
                        system("pause");
                    }
                }
                else
                {   system("cls");  
                    printf(RED "\nNO QUEDAN MAS LUGARES\n" RESET);
                    system("pause");
                }
                break;

            case 2:
                system("cls");
                per_imprimirArray(arrayPersonas, QTY_PERSONAS);
                if(!obtenerNumeroEntero(&auxiliarDni, MAGENTA "\nIndique el DNI de la persona a eliminar: " RESET, RED "\nDNI invalido" RESET, MIN_DNI, MAX_DNI, 2))
                {
                    auxiliarIndice = per_buscarPorDni(arrayPersonas, QTY_PERSONAS, auxiliarDni);
                    
                    if(auxiliarIndice >= 0 &&
                      per_bajaArray(arrayPersonas, QTY_PERSONAS, auxiliarIndice) == 0)  
                    {
                        system("cls");    
                        printf(GREEN "\nBaja realizada con exito\n" RESET);
                        system("pause");
                    }
                }
                else
                {
                    system("cls");    
                    printf(RED "\nEL NUMERO DE DNI NO EXISTE EN LA LISTA\n" RESET);
                    system("pause");
                }
                break;

            case 3:
                system("cls");
                per_ordenarPorNombre(arrayPersonas, QTY_PERSONAS);
                per_imprimirArray(arrayPersonas, QTY_PERSONAS);
                system("pause");
                break;

            case 4:
                system("cls");
                per_imprimrGrafico(arrayPersonas, QTY_PERSONAS);
                system("pause");
                break;

            case 5:
                system("cls");
                printf(BLUE "Programa finalizado" RESET);
                seguir = 'n';
                break;
        }
    }
    return EXIT_SUCCESS;
}