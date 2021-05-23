#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id_tripulante;
    int id_patota;
    char* estado;
    char* tareas;
    Posicion posicion
}Tripulante;

typedef struct{
    int x;
    int y;
}Posicion;

Tripulante  nuevo_tripulante(){
    Tripulante t1;
    return t1;
}
