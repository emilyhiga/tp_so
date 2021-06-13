#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id_patota;
    Tripulante tripulantes[];
} Patota;
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
// De las posiciones tener la matriz


Tripulante  nuevo_tripulante(){
    Tripulante t1;
    return t1;
}
