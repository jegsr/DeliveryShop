

#include <stdio.h>
#include <stdbool.h>
#include "estrutura.h"
#include "Menu_login.h"
#include "ficheiros.h"



int main() {
    USERNAME username[MAXIMO_USERNAME];
    CLIENTE cliente[MAXIMO_CLIENTE];
    FUNCIONARIO funcionario[MAXIMO_FUNCIONARIO];
    ENCOMENDA encomenda[MAXIMO_ENCOMENDA];
    PRODUTO produto[MAXIMO_PRODUTO];
    bool BLOQUEIO = false;
    unsigned int contadorUsername = 0, contadorCliente = 0, contadorFuncionario = 0,
            contadorEncomenda = 0, contadorProduto = 0;

    unsigned short tentativaEntrar = 0,op;

    time_t data_bloqueio, data_atual;

    //verificar se o computador está bloqueado a nivel de login's
    abrir_ficheiro_time(&data_bloqueio);
    //saber a data atual em milissegundos
    time(&data_atual);
    
    // comparar a data de bloqueio com a atual para verificar bloqueios no momento
    if (difftime(data_bloqueio, data_atual) > 0) {
        BLOQUEIO = true;
        tentativaEntrar = 3;
    }
    //abrirar e carregar tudo acerca o tipo USERNAME
    contadorUsername = abrir_ficheiro_username(username);
    contadorCliente = abrir_ficheiro_cliente(cliente);
    contadorFuncionario = abrir_ficheiro_funcionario(funcionario);
    contadorProduto = abrir_ficheiro_produto(produto);
    contadorEncomenda = abrir_ficheiro_encomenda(encomenda);

    
    menu_login(cliente,funcionario,encomenda,produto,username,&contadorUsername,
            &contadorCliente,&contadorFuncionario,&contadorProduto,&contadorEncomenda,
            &tentativaEntrar,&BLOQUEIO);

    guardar_ficheiros(cliente,funcionario,username,produto,contadorCliente,contadorFuncionario,contadorUsername,contadorProduto);
    guardar_ficheiro_encomenda(encomenda,contadorEncomenda);
    

    return 0;
}


