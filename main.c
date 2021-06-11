#include <stdio.h>
#include <stdlib.h>
#include<commons/string.h>
#include <tripulantes.c>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("Hello world");


//

//CONSIDERE QUE SE INGRESO POR CONSOLOA ALGUNA ACCIO


	return 0;
}


void realizar_accion(const char* accion){
    char* accion_array = string_split(accion, " "); //Retorna un array con cada palabra(separada por el espacio) y en la última posición un NULL

    if (accion_array[0]=="INICIAR_PATOTA"){
        //EJEMPLO: INICIAR_PATOTA 5 /home/utnso/tareas/tareasPatota5.txt 1|1 3|4
        int cant_tripulantes= atoi(accion_array[1]);
        char* archivo_tareas= accion_array[2];
        char* posiciones= verificar_posiciones(cant_tripulantes,accion_array[3]);

        iniciar_patota(cant_tripulantes, archivo_tareas, posiciones);
    }
    else if (accion_array[0]=="LISTAR_TRIPULANTES"){
        //EJEMPLO: LISTAR_TRIPULANTES

        // EJEMPLO CONSOLA: Estado de la Nave: 09/07/21 10:15:01
        printf("ESTADO DE LA NAVE: %s /n", temporal_get_string_time("%d/%m/%y %H:%M:%S"));

        //Consegir la lista de hilos (Tripulantes) qeu es estan ejecutando --> PCB ??? CONTEXTO DEL PROCESO??
        char* lista_tripulantes; // Puede ser una llista ... que se consiga del PCB , Modulo Mi-Ram HQ???

        //EJEMPLO CONSOLA: Tripulante: 1 Patota: 1 Status: EXEC
        while (hay_tripulantes_para_mostrar(lista_tripulantes))
        {
            Tripulante unTripulante= mostrar_tripulante(lista_tripulantes);
/*
Veri si hace falta guardarlo en un char o si esta bien que en la funcion append haga la funcion de string from formar
            char* tripulante =string_from_format("Tripulante: %s   ", string_itoa(unTripulante.id_tripulante));
            char* patota = string_from_format("Patota: %s   ", string_itoa(unTripulante.id_patota));
            char* status = string_from_format("Status: %s /n", unTripulante.estado);
*/
            char* monstrar_consola= string_new();
            string_append(&monstrar_consola, string_from_format("Tripulante: %s   ", string_itoa(unTripulante.id_tripulante)));
            string_append(&monstrar_consola, string_from_format("Patota: %s   ", string_itoa(unTripulante.id_patota)));
            string_append(&monstrar_consola, string_from_format("Status: %s /n", unTripulante.estado));

            //Muestro el mensaje por consola
            //log_trace(t_log* logger, monstrar_consola);

        }
        
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

bool hay_tripulantes_para_mostrar(char* lista_tripulantes){

    return true;
}

Tripulante mostrar_tripulante(char* lista_tripulantes){
    //De la "lista" saco un tripulantes para mostrarlo en la lista
    Tripulante untripulante;
    /*codigo para "sacar" al tripulante*/
    return untripulante;
}
