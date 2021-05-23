#include <stdio.h>
#include <stdlib.h>
#include<commons/string.h>
#include <tripulantes.c>

typedef struct Tarea {
    int parametro;
    Posicion posicion;
    int tiempo;
}GenerarOxigeno, ConsumirOxigeno, GenerarComida, ConsumirComida, GenerarBasura, DescartarBasura, OtraTarea;


char* asignar_tareas(char* archivo){
    //Leo el archivo linea por linea ----> VER
    char* linea;

    char* lineas_separadas = string_split(linea, ";");

    //VER SI PUEDO APLICAR APLICACION PARCIAL?? POLIMORFISMO}???

    if(string_starts_with(linea, "GENERAR_OXÍGENO")){
        GenerarOxigeno GO;
        GO.parametro= string_split(lineas_separadas[0], " ")[1];
        GO.posicion.x= lineas_separadas[1];
        GO.posicion.y= lineas_separadas[2];
        GO.tiempo= lineas_separadas[3];

    }
    else if(string_starts_with(linea, "CONSUMIR_OXÍGENO")){
        ConsumirOxigeno CO;
        CO.parametro= string_split(lineas_separadas[0], " ")[1];
        CO.posicion.x= lineas_separadas[1];
        CO.posicion.y= lineas_separadas[2];
        CO.tiempo= lineas_separadas[3];
    }
    else if(string_starts_with(linea, "GENERAR_COMIDA")){
        GenerarComida GC;
        GC.parametro= string_split(lineas_separadas[0], " ")[1];
        GC.posicion.x= lineas_separadas[1];
        GC.posicion.y= lineas_separadas[2];
        GC.tiempo= lineas_separadas[3];
    }
    else if(string_starts_with(linea, "CONSUMIR_COMIDA")){
        ConsumirComida CC;
        CC.parametro= string_split(lineas_separadas[0], " ")[1];
        CC.posicion.x= lineas_separadas[1];
        CC.posicion.y= lineas_separadas[2];
        CC.tiempo= lineas_separadas[3];
    }
    else if(string_starts_with(linea, "GENERAR_BASURA")){
        GenerarBasura GB;
        GB.parametro= string_split(lineas_separadas[0], " ")[1];
        GB.posicion.x= lineas_separadas[1];
        GB.posicion.y= lineas_separadas[2];
        GB.tiempo= lineas_separadas[3];
    }
    else if(string_starts_with(linea, "DESCARTAR_BASURA")){
        DescartarBasura DB;
        DB.parametro= string_split(lineas_separadas[0], " ")[1];
        DB.posicion.x= lineas_separadas[1];
        DB.posicion.y= lineas_separadas[2];
        DB.tiempo= lineas_separadas[3];
    }
    else {
        OtraTarea OT;
        OT.posicion.x= lineas_separadas[1];
        OT.posicion.y= lineas_separadas[2];
        OT.tiempo= lineas_separadas[3];
    }

    return linea;
}

