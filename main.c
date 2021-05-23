#include <stdio.h>
#include <stdlib.h>
#include<commons/string.h>
#include <tripulantes.c>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("Hello world");

//CONSIDERE QUE SE ENGRESO POR CONSOLOA ALGUNA ACCIO


	return 0;
}


void realizar_accion(const char* accion){
    char* accion_array = string_split(accion, " "); //Retorna un array con cada palabra y en la última posición un NULL

    if (accion_array[0]=="INICIAR_PATOTA"){
        int cant_tripulantes= atoi(accion_array[1]);
        char* archivo_tareas= accion_array[2];
        char* posiciones= verificar_posiciones(cant_tripulantes,accion_array[3]);

        iniciar_patota(cant_tripulantes, archivo_tareas, posiciones);
    }
    else if (accion_array[0]=="LISTAR_TRIPULANTES"){

    }
    else if (accion_array[0]=="EXPULSAR_TRIPULANTE"){

    }
    else if (accion_array[0]=="INICIAR_PLANIFICACION"){

    }
    else if (accion_array[0]=="PAUSAR_PLANIFICACION"){

    }
    else if (accion_array[0]=="OBTENER_BITACORA"){

    }
    else{
        error_show(temporal_get_string_time("%d/%m/%y %H:%M:%S"), "Error: No se ha encontrado la accion");
    }


}

char* verificar_posiciones(int cantidad, char* posiciones){

    char* posiciones_completas[cantidad+1]; //+1 POR EL NULL
     int i;

     //PASO TODAS LAS POSICIONES SIN IONCLUIR EL NULL
    for (i =0; posiciones[i]!= NULL; i++)
    {
        posiciones_completas[i]=posiciones[i];

    }
    //Verifico si se pasaron todas las pasiciones
    if (i != cantidad){
        //SI no agrego con 0|0 hasta que se complete
        while (i != cantidad){
           posiciones_completas[i] = "0|0"; 
           i++;
        }
    }
    posiciones_completas[i] = NULL;

}


void iniciar_patota(int cantidad, char* archivo, char* posiciones){
    /*se debera iniciar la patota en el módulo Mi-RAM HQ y luego instanciar a cada tripulante.*/
    int i =0;
    while (i < cantidad){
        Tripulante nuevo_tripulante; //HACE FALTA NUEVO_TRIPULANTE(); ????????????
        nuevo_tripulante.id_patota=asignar_id_patota();
        nuevo_tripulante.id_tripulante=asignar_id_tripu();
        nuevo_tripulante.estado=NULL;
        nuevo_tripulante.tareas= asignar_tareas(archivo);
    }

    
}


