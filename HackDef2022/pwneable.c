/*

autor: Hack Def

fecha: 14-Octubre-2022

desc : Configuracion del ATM Switch

flag : hackdef{brute_force_and_frequency_is_with_you:to_win} 
ATM Switch 35.87.20.82  4002

*/

#include <stdio.h>

#include <stdlib.h>

#include <stdint.h>

#include <unistd.h>

#include <time.h>

#define MAX_POLITICAS 0X30
#define TAM_CREDS 0X100

struct Politica{

    uint8_t  fecha_mes;

    uint16_t fecha_dia;

    char     autor[13];

    uint16_t lim_inferior;

    uint16_t lim_superior;

    int      tam_host;

    char     host[0X100];

}__attribute__((packed));

void Imprimir_Host(struct Politica *p){

    write(STDOUT_FILENO, p->host, p->tam_host);
}

struct Politica* politicas;
uint8_t cantidad_politicas;
uint8_t politica_aplicada = -1;
char* creds;

void init_buffers(){

    setvbuf(stdin, NULL, _IONBF, 0);

    setvbuf(stdout, NULL, _IONBF, 0);

    setvbuf(stderr, NULL, _IONBF, 0);

    politicas = (struct Politica*) malloc(MAX_POLITICAS * sizeof(struct Politica));

    creds = (char*) malloc(TAM_CREDS * sizeof(char));




    FILE* fp = fopen("flag.txt", "r");

    if(fp == NULL){

        puts("Error al leer credenciales. Contacta a los organizadores");

        exit(0);

    }

    fgets(creds, TAM_CREDS, fp);

    fclose(fp);
}

int leer_input(char* buf, int tam){

    int b = read(STDIN_FILENO, buf, tam);

    if(b < 0){

        puts("Error al leer input");

        exit(0);

    }

    buf[b] = '\0';

    return b;
}

int leer_int(){

    int tam = 0x28;

    char buf[0x28];

    leer_input(buf, tam);

    int ret = atoi(buf);

    if(ret < 0){

        printf("No se permiten negativos\n");

        exit(0);
    }

    return ret;
}

void Imprimir_Banner(){

    puts("");

    puts("   #    ####### #     #     #####                                   #####                                ");

    puts("  # #      #    ##   ##    #     # #    # # #####  ####  #    #    #     #  ####  #    # ###### #  ####  ");

    puts(" #   #     #    # # # #    #       #    # #   #   #    # #    #    #       #    # ##   # #      # #    # ");

    puts("#     #    #    #  #  #     #####  #    # #   #   #      ######    #       #    # # #  # #####  # #      ");

    puts("#######    #    #     #          # # ## # #   #   #      #    #    #       #    # #  # # #      # #  ### ");

    puts("#     #    #    #     #    #     # ##  ## #   #   #    # #    #    #     # #    # #   ## #      # #    # ");

    puts("#     #    #    #     #     #####  #    # #   #    ####  #    #     #####   ####  #    # #      #  ####  ");

    puts("");

    puts("");

}




void Imprimir_Menu(){

    puts("16 : Ver politicas");

    puts("36 : Modificar politica");

    puts("40 : Agregar politica");

    puts("48 : Aplicar politica");

    puts("127 : Probar ruteo");

    puts("255 : Salir");
}

uint16_t Obtener_Opcion(){

    printf("> ");

    int ret = leer_int();

    return ret;
}

void Ver_Politicas(){

    if(!cantidad_politicas){

        printf("No hay politicas registradas.\n");

    }

    for(uint8_t i = 0; i < cantidad_politicas; i++){

        printf("0x%02X :\n", i);

        printf("\tCreada el %02d-%02d\n", politicas[i].fecha_dia, politicas[i].fecha_mes);

        printf("\tLimite inferior para redirigir transaccion: $ %06d\n", politicas[i].lim_inferior);

        printf("\tLimite superior para redirigir transaccion: $ %06d\n", politicas[i].lim_superior);

        printf("\n");

    }

}

void Leer_NumPolitica(uint8_t* num){

    if(num == NULL){

        printf("num es NULL\n");

        exit(0);
    }

    *num = leer_int();

    if(*num < 0 || *num >= cantidad_politicas){

        *num = -1;

        printf("Esa politica no existe\n");

        return;
    }
}

void Leer_FechaMes(int* fecha_mes){

    time_t t = time(NULL);

    struct tm tm = *localtime(&t);

    *fecha_mes = tm.tm_mon;
}

void Leer_FechaDia(int* fecha_dia){

    time_t t = time(NULL);

    struct tm tm = *localtime(&t);

    *fecha_dia = tm.tm_mday;
}

void Leer_Autor(char* buf, int tam){

    printf("Autor : ");

    leer_input(buf, tam-1);
}

void Leer_Limite(const char* msW, int* limite){

    printf("Ingresa el limite %s : ", msW);

    *limite = leer_int();
}

void Leer_Host(char *buf, int* tam){

    printf("Host : ");

    *tam = leer_input(buf, 0Xff);

}

void Agregar_Politica(){

    if(cantidad_politicas >= MAX_POLITICAS){

        printf("Imposible agregar mas politicas\n");

        return;
    }

    Leer_FechaMes((uint8_t*)&politicas[cantidad_politicas].fecha_mes);

    Leer_FechaDia((uint8_t*)&politicas[cantidad_politicas].fecha_dia);

    Leer_Autor(politicas[cantidad_politicas].autor, sizeof(politicas[cantidad_politicas].autor));

    Leer_Limite("inferior", (uint16_t*)&politicas[cantidad_politicas].lim_inferior);

    Leer_Limite("superior", (uint16_t*)&politicas[cantidad_politicas].lim_superior);

    Leer_Host(politicas[cantidad_politicas].host, (uint16_t*)&politicas[cantidad_politicas].tam_host);

    cantidad_politicas++;

    printf("Listo\n");
}

void Modificar_Politica(){

    uint8_t idx = -1;

    printf("IDX : ");

    Leer_NumPolitica((uint8_t*)&idx);

    Leer_FechaMes((uint8_t*)&politicas[idx].fecha_mes);

    Leer_FechaDia((uint8_t*)&politicas[idx].fecha_mes);

    Leer_Limite("inferior", (uint16_t*)&politicas[idx].lim_inferior);

    Leer_Limite("superior", (uint16_t*)&politicas[idx].lim_superior);

    printf("Listo\n\n");
}

void Aplicar_Politica(){

    printf("IDX: ");

    Leer_NumPolitica((uint8_t*)&politica_aplicada);

    printf("Listo\n\n");
}

void Probar_Ruteo(){

    if(politica_aplicada >= cantidad_politicas){

        printf("Primero selecciona una politica valida\n");

        return;
    }

    if(politicas[politica_aplicada].lim_inferior > politicas[politica_aplicada].lim_superior){

        printf("Esta politica nunca surtira efecto\n");

        printf("Contactar al host para que la modifique\n");

        printf("Host: ");

        Imprimir_Host(&politicas[politica_aplicada]);

        printf("\n");

        return;
    }

    uint16_t cantidad = 0;

    printf("Cantidad: $");

    cantidad = leer_int();

    if(cantidad < politicas[politica_aplicada].lim_inferior){

        printf("Cantidad muy chica. El switch procesa transaccion...\n");

        return;
    }

    if(cantidad > politicas[politica_aplicada].lim_superior){

        printf("Cantidad muy grande. El switch procesa esta transaccion...\n");

        return;
    }

    printf("Esta transaccion la debe procesar el host\n");
}

int main(){

    init_buffers();

    Imprimir_Banner();

    while(1){

        Imprimir_Menu();

        uint8_t op = Obtener_Opcion();

        switch(op){

            case 0x10:

                Ver_Politicas();

                break;

            case 0x24:

                Modificar_Politica();

                break;

            case 0x28:

                Agregar_Politica();

                break;

            case 0x30:

                Aplicar_Politica();

                break;

            case 0x7f:

                Probar_Ruteo();

                break;

            case 0xff:

                puts("Adios!");

                return 0;

            default:

                printf("Opcion desconocida : %x\n", op);

                break;
        }
    }

    return 0;
}