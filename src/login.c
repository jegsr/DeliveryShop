#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "estrutura.h"
#include "LP_Leitura.h"
#include "Cliente.h"
#include "ficheiros.h"
#include "login.h"
#include "FuncoesGerais.h"

void adicionar_Username(char user[], USERNAME *utilizador) {
    strncpy(utilizador->nickname, user,MAXIMO_NOME);
}

void adicionar_Password(char password[], USERNAME *utilizador) {
    strncpy(utilizador->password, password, PASSWORD);
}

bool verificar_Utilizador(char utilizador[], USERNAME user[], unsigned int contador) {
    unsigned int i = 0;
    while (i < contador && strcmp(utilizador, user[i].nickname) != 0) {
        i++;
    }

    return !(i == contador);
}

int verificar_PosicaoUtilizador(char utilizador[], USERNAME user[], unsigned int contador) {
    unsigned int i = 0;
    while (i < contador && strcmp(utilizador, user[i].nickname) != 0) {
        i++;
    }
    if (i == contador) {
        return -1;
    } else {
        return i;
    }
}

bool verificar_Password(USERNAME user, char password[]) {
    return (strcmp(user.password, password) == 0);
}

void alterar_Password(char password_original[]) {
    char password[PASSWORD], password2[PASSWORD];
    int tempPass;
    do {


        readString(password, PASSWORD, "Password: "); //fazer codigo de *
        readString(password2, PASSWORD, "Confirmar Password: ");


        tempPass = strcmp(password, password2);

        if (tempPass != 0) {
            PRINT_PASS_INVALIDO;
        }
    } while (tempPass != 0);

    strncpy(password_original, password, PASSWORD);
}

void registar(USERNAME user[], unsigned int contador) {
    char password[PASSWORD], utilizador[MAXIMO_NOME];
    bool tempUser;

    user[contador].id = contador;

    do {


        readString(utilizador, MAXIMO_NOME, "Username: ");


        tempUser = verificar_Utilizador(utilizador, user, contador);

        if (tempUser == true) {
            PRINT_USER_INVALIDO;
        }
    } while (tempUser);

    alterar_Password(password);

    adicionar_Username(utilizador, &user[contador]);
    adicionar_Password(password, &user[contador]);

}

CLIENTE registar_Cliente(USERNAME user[], unsigned int *contadorUsername) {
    CLIENTE cliente;

    registar(user, *contadorUsername);
    adicionar_ID(&cliente.id_registo, *contadorUsername);
    adicionar_Cliente(&cliente);
    (*contadorUsername)++;

    return cliente;
}

FUNCIONARIO registar_Funcionario(USERNAME user[], unsigned int *contador) {
    FUNCIONARIO funcionario;

    registar(user, *contador);
    adicionar_ID(&funcionario.id_registo, *contador);
    adicionar_Funcionario(&funcionario);
    (*contador)++;
    return funcionario;

}

int login(unsigned int *contador, USERNAME user[]) {
    char utilizador[MAXIMO_NOME], password[PASSWORD];


    readString(utilizador, MAXIMO_NOME, "User: ");
    readString(password, PASSWORD, "Password: "); //fazer o codigo dos *


    unsigned int i;
    i = verificar_PosicaoUtilizador(utilizador, user, *contador);

    if (i != -1) {
        if (verificar_Password(user[i], password) == true) {
            return i;
        } else {
            PRINT_PASS_INVALIDO;
        }
    } else {
        PRINT_USER_INVALIDO;
    }
    return -1;
}

void excesso_tentativas(bool *BLOQUEIO, time_t data_atual, unsigned short *tentativaEntrar) {
    time_t data_bloqueio;
    struct tm *informacao_data_bloqueio;
    abrir_ficheiro_time(&data_bloqueio);

    if (*BLOQUEIO == true && difftime(data_bloqueio, data_atual) <= 0) { //verificar se a data de bloqueio ja passou
        *BLOQUEIO = false;
        tentativaEntrar = 0;
    }
    if (*BLOQUEIO == false) {
        if (*tentativaEntrar == MAXIMO_TENTATIVA) {

            PRINT_MENU
            printf("\nDEMASIADAS TENTATIVAS\n");
            PRINT_MENU

            data_bloqueio = data_atual + 900; //data atual + 900segundos = +15min;
            informacao_data_bloqueio = localtime(&data_bloqueio);
            PRINT_BLOQUEIO(asctime(informacao_data_bloqueio));
            *BLOQUEIO = true;
            guardar_ficheiro_time(data_bloqueio);
        }
    } else {

        informacao_data_bloqueio = localtime(&data_bloqueio);

        PRINT_BLOQUEIO(asctime(informacao_data_bloqueio));
    }


}
