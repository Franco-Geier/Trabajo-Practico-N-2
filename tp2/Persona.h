#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#define QTY_PERSONAS 20
#define NOMBRE_LEN 50
#define MIN_DNI 10000000
#define MAX_DNI 50000000
#define RED          "\x1b[31m"
#define GREEN        "\x1b[32m"
#define YELLOW       "\x1b[33m"
#define BLUE         "\x1b[34m"
#define MAGENTA      "\x1b[35m"
#define CYAN         "\x1b[36m"
#define RESET        "\x1b[0m"
#define LIGHTGREEN   "\x1b[92m"
#define BOLD         "\x1b[1m"

typedef struct{
    char nombre[NOMBRE_LEN];
    int edad;
    int estado;
    int dni;
    int id;
}Persona;

int per_imprimir(Persona* pElemento);
int per_imprimirArray(Persona array[], int limite);
int per_inicializarArray(Persona array[], int limite);
int per_bajaArray(Persona array[], int limite, int indice);
int per_ordenarPorNombre(Persona array[], int limite);
int per_obtenerEspacioLibre(Persona array[], int limite);
int per_altaArray(Persona array[], int limite, int indice);
int per_buscarPorDni(Persona array[], int limite, int dni);
int per_imprimrGrafico(Persona array[], int limite);

#endif // PERSONA_H_INCLUDED