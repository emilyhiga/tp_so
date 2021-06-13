#include <stdio.h>
#include <stdlib.h>
#include<commons/string.h>
#include <log.h>
#include <config.h>

t_log* iniciar_logger(){
    t_log* logger = log_create("tpso.log", "TPSO", 1, LOG_LEVEL_INFO);
    return logger;
}

t_config* leer_config(){
    t_config* config =config_create("config.config");
    return config;
}

void leer_consola(t_log* log){
    char* leido = readline("");

    while (*leido != '\0'){
        log_info(log, leido);
        free(leido);
        leido = readline("");
    }
}

int crear_conexion(char* ip, char* puerto){
    
}