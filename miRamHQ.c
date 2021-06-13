#include <stdio.h>
#include <stdlib.h>
#include<commons/string.h>
#include <log.h>
#include <config.h>
#include <tripulantes.c>
/*
MI RAM HQ
 Almacena:  
    .toda la informacion de las instrucciones
    .PCB
    .TCB
Y tambien mantiene actualizada el mapa con la posicion de cada tripulantes durante su ejecucio

*/

int main(int argc, char *argv[]) {

    t_config* config = leer_config();




    config_destroy(config);
	return 0;
}

void inicializacion(t_config* config , Tripulante patota[]){
    reservar_espacio(config, patota);
    dibujar_mapa(); //Ver repo con las funciones para el mapa
    iniciar_servidor();
}

void reservar_espacio(t_config * config, Tripulante patota[]){
    malloc(config_get_int_value(config, "TAMANIO_MEMORIA"));
    
    if(config_get_string_value(config, "ESQUEMA_MEMORIA") == "SEGMENTACION"){

    }
    else if (config_get_string_value(config, "ESQUEMA_MEMORIA") == "PAGINACION"){

    }
    else{
       error_show(temporal_get_string_time("%d/%m/%y %H:%M:%S"), "Error: Se ha encontrado un esquema erroneo"); 
    }
}