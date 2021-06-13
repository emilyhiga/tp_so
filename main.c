#include <stdio.h>
#include <stdlib.h>
#include<commons/string.h>
#include <log.h>
#include <config.h>
#include <tripulantes.c>

/*DISCORDIADOR
    .Planificar las tareas
    .Atender los sabotajes
*/


int main(int argc, char *argv[]) {
    t_log* logger = iniciar_logger();
    t_config* config = leer_config();

    char* IP_MI_RAM_HQ = config_get_string_value(config, "IP_MI_RAM_HQ");
    char* PUERTO_MI_RAM_HQ = config_get_string_value(config, "PUERTO_MI_RAM_HQ");
    int CONEXION_MI_RAM_HQ = crear_conexion(IP_MI_RAM_HQ, PUERTO_MI_RAM_HQ); //Importar carpeta de utiles.c del TP 0.




//CONSIDERE QUE SE INGRESO POR CONSOLOA ALGUNA ACCIO
realizar_accion("accion_ingresado_por_consola");


    log_destroy(logger);
    config_destroy(config);
    liberar_conexion(CONEXION_MI_RAM_HQ);//Importar carpeta de utiles.c del TP 0.
	return 0;
}


void realizar_accion(const char* accion){
    char* accion_array = string_split(accion, " "); //Retorna un array con cada palabra(separada por el espacio) y en la última posición un NULL

    if (accion_array[0]=="INICIAR_PATOTA"){
        //EJEMPLO: INICIAR_PATOTA 5 /home/utnso/tareas/tareasPatota5.txt 1|1 3|4
        int cant_tripulantes= atoi(accion_array[1]);
        char* archivo_tareas= accion_array[2];
        char* posiciones= verificar_posiciones(cant_tripulantes,accion_array[3]);

        //Notifico al Mi Ram HQ para que cree el PCB y TCB de cada tripulante con su posicion inicial
        Patota patota = notificar_a_miRamHQ(cant_tripulantes, archivo_tareas);
        //enviar_mensaje(mensaje, CONEXION_MI_RAM_HQ);//Importar carpeta de utiles.c del TP 0.

        iniciar_patota(patota, cant_tripulantes, archivo_tareas, posiciones);
    }
    else if (accion_array[0]=="LISTAR_TRIPULANTES"){
        //EJEMPLO: LISTAR_TRIPULANTES

        // EJEMPLO CONSOLA: Estado de la Nave: 09/07/21 10:15:01
        printf("ESTADO DE LA NAVE: %s /n", temporal_get_string_time("%d/%m/%y %H:%M:%S"));

        //Consegir la lista de hilos (Tripulantes) qeu es estan ejecutando --> PCB ??? CONTEXTO DEL PROCESO??
        char* lista_tripulantes; // Puede ser una llista ... que se consiga del PCB , Modulo Mi-Ram HQ???

        while (haya_tripulantes_para_mostrar(lista_tripulantes))
        {
            Tripulante unTripulante= mostrar_tripulante(lista_tripulantes);

            char* monstrar_consola= string_new();
            string_append(&monstrar_consola, string_from_format("Tripulante: %s   ", string_itoa(unTripulante.id_tripulante)));
            string_append(&monstrar_consola, string_from_format("Patota: %s   ", string_itoa(unTripulante.id_patota))); // Ver id_patota
            string_append(&monstrar_consola, string_from_format("Status: %s /n", unTripulante.estado));

            //Muestro el mensaje por consola
            //log_trace(t_log* logger, monstrar_consola);

        }
        
    }
    else if (accion_array[0]=="EXPULSAR_TRIPULANTE"){
        finalizar_tripulante(accion_array[1]);
        eyectar_tripulante_MI_RAM_HQ(accion_array[1]); // debe dejarse de ver en el ,apa y eliminar su segmento de tareas
    }
    else if (accion_array[0]=="INICIAR_PLANIFICACION"){
        inicar_planificacion();
    }
    else if (accion_array[0]=="PAUSAR_PLANIFICACION"){
        pausar_planificacion();
    }
    else if (accion_array[0]=="OBTENER_BITACORA"){
        obtener_bitacora_MI_RAM_HQ();
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


void iniciar_patota(Patota patota, int cantidad, char* archivo, char* posiciones){
    /*se debera iniciar la patota en el módulo Mi-RAM HQ y luego instanciar a cada tripulante.*/
    int i = 1;
    while (i <= cantidad){
        Tripulante nuevo_tripulante; //HACE FALTA NUEVO_TRIPULANTE(); ????????????
        nuevo_tripulante.id_patota=patota.id_patota; // Puede no hace falta
        nuevo_tripulante.id_tripulante=i;
        nuevo_tripulante.estado=NULL;
        nuevo_tripulante.tareas= asignar_tareas(archivo);

     // patota.tripulantes+= nuevo_tripulante;

        i++;
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

Patota notificar_a_miRamHQ(int cant_tripulantes, char* archivo_tareas){
    Patota p;
    return p;
}

void inicar_planificacion(){
    t_config* config = config_create("config.config.txt");
    
    if (config_get_string_value(config, "ALGORITMO") == "FIFO"){

    }
    else if (config_get_string_value(config, "ALGORITMO") == "RR"){

    }
    else{
        error_show(temporal_get_string_time("%d/%m/%y %H:%M:%S"), "Error: Esquema de trabajo erroneo");
    }
}