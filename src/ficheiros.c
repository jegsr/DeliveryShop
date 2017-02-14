#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"
#include <string.h>

// abrir data de bloqueio do login

void abrir_ficheiro_time(time_t *data) {
    FILE *ficheiro;
    ficheiro = fopen("bloqueio.txt", "r+");

    if (ficheiro != NULL) {

        fread(data, sizeof (time_t), 1, ficheiro);
        fclose(ficheiro);

    } else {
        time(data);
        printf("\nSEM DADOS GUARDADOS: FICHEIRO BLOQUEIO RESET\n");
    }

}
// guardar data de bloqueio do login

void guardar_ficheiro_time(time_t data) {
    unsigned int i;
    FILE *ficheiro;
    ficheiro = fopen("bloqueio.txt", "w+");

    i = fwrite(&data, sizeof (time_t), 1, ficheiro);
    if (i == 0) {
        printf("\nERRO NA GRAVACAO DO FICHEIRO BLOQUEIO\n");
    }

    fclose(ficheiro);
}

//abrir o ficheiro que contem o numero de usernames existentes

void abrir_ficheiro_contadorUsername(unsigned int *contador) {
    FILE *ficheiro;

    ficheiro = fopen("contadorUsername.txt", "r+");

    if (ficheiro != NULL) {
        fread(contador, sizeof (unsigned int), 1, ficheiro);
        fclose(ficheiro);
    } else {
        printf("\nSEM DADOS GUARDADOS: FICHEIRO CONTADOR USERNAME RESET\n");
        *contador = 0;
    }
}

//guardar em ficheiro o numero de usernames existentes

void guardar_ficheiro_contadorUsername(unsigned int contador) {
    FILE *ficheiro;
    int i;
    ficheiro = fopen("contadorUsername.txt", "w+");

    i = fwrite(&contador, sizeof (unsigned int), 1, ficheiro);

    if (i == 0)
        printf("\nERRO NA GRAVACAO DO FICHEIRO CONTADOR USERNAME\n");
    fclose(ficheiro);
}

//abrir o ficheiro que contem o conteudo os usernames

unsigned int abrir_ficheiro_username(USERNAME user[]) {
    FILE *ficheiro;
    unsigned int contador = 0;
    ficheiro = fopen("username.txt", "r+");


    if (ficheiro != NULL) {
        abrir_ficheiro_contadorUsername(&contador);
        fread(user, sizeof (USERNAME), contador, ficheiro);
        fclose(ficheiro);
    } else {
        printf("\nSEM DADOS GUARDADOS: FICHEIRO USERNAME RESET\n");

        user[contador].id = contador;
        char admin[] = "admin";
        strcpy(user[contador].nickname, admin);
        strcpy(user[contador].password, admin);
        contador++;
    }

    return contador;
}

//guardar em ficheiro o conteudo dos usernames

void guardar_ficheiro_username(USERNAME user[], unsigned int contador) {
    unsigned int i;
    FILE *ficheiro;
    ficheiro = fopen("username.txt", "w+");

    guardar_ficheiro_contadorUsername(contador);

    i = fwrite(user, sizeof (USERNAME), contador, ficheiro);

    if (i == 0) {
        printf("\nERRO NA GRAVACAO DO FICHEIRO USERNAME\n");
    }

    fclose(ficheiro);
}

//abrir o ficheiro que contem o numero de clientes

void abrir_ficheiro_contadorCliente(unsigned int *contador) {
    FILE *ficheiro;

    ficheiro = fopen("contadorCliente.txt", "r+");

    if (ficheiro != NULL) {
        fread(contador, sizeof (unsigned int), 1, ficheiro);
        fclose(ficheiro);
    } else {
        printf("\nSEM DADOS GUARDADOS: FICHEIRO CONTADOR CLIENTE RESET\n");
    }
}

//guardar em ficheiro o numero de clientes

void guardar_ficheiro_contadorCliente(unsigned int contador) {
    FILE *ficheiro;
    int i;
    ficheiro = fopen("contadorCliente.txt", "w+");

    i = fwrite(&contador, sizeof (unsigned int), 1, ficheiro);

    if (i == 0)
        printf("\nERRO NA GRAVACAO DO FICHEIRO CONTADOR CLIENTE\n");
    fclose(ficheiro);
}

//abrir o ficheiro que contem o conteudo do array de clientes

unsigned int abrir_ficheiro_cliente(CLIENTE cliente[]) {
    FILE *ficheiro;
    unsigned int contador = 0;
    ficheiro = fopen("cliente.txt", "r+");


    if (ficheiro != NULL) {
        abrir_ficheiro_contadorCliente(&contador);
        fread(cliente, sizeof (CLIENTE), contador, ficheiro);
        fclose(ficheiro);
    } else {
        printf("\nSEM DADOS GUARDADOS: FICHEIRO CLIENTE RESET\n");
    }

    return contador;
}

//guardar em ficheiro o conteudo do array do cliente

void guardar_ficheiro_cliente(CLIENTE cliente[], unsigned int contador) {
    unsigned int i;
    FILE *ficheiro;
    ficheiro = fopen("cliente.txt", "w+");

    guardar_ficheiro_contadorCliente(contador);

    i = fwrite(cliente, sizeof (CLIENTE), contador, ficheiro);

    if (i == 0) {
        printf("\nERRO NA GRAVACAO DO FICHEIRO CLIENTE\n");
    }

    fclose(ficheiro);
}

//abrir o ficheiro que contem o numero de funcionarios

void abrir_ficheiro_contadorFuncionario(unsigned int *contador) {
    FILE *ficheiro;

    ficheiro = fopen("contadorFuncionario.txt", "r+");

    if (ficheiro != NULL) {
        fread(contador, sizeof (unsigned int), 1, ficheiro);
        fclose(ficheiro);
    } else {
        printf("\nSEM DADOS GUARDADOS: FICHEIRO CONTADOR FUNCIONARIO RESET\n");
    }
}

//guardar em ficheiro o numero de funcionarios existentes

void guardar_ficheiro_contadorFuncionario(unsigned int contador) {
    FILE *ficheiro;
    int i;
    ficheiro = fopen("contadorFuncionario.txt", "w+");

    i = fwrite(&contador, sizeof (unsigned int), 1, ficheiro);

    if (i == 0)
        printf("\nERRO NA GRAVACAO DO FICHEIRO CONTADOR FUNCIONARIO\n");
    fclose(ficheiro);
}

//abrir o ficheiro que contem o conteudo do array funcionario

unsigned int abrir_ficheiro_funcionario(FUNCIONARIO funcionario[]) {
    FILE *ficheiro;
    unsigned int contador = 0;
    ficheiro = fopen("funcionario.txt", "r+");


    if (ficheiro != NULL) {
        abrir_ficheiro_contadorFuncionario(&contador);
        fread(funcionario, sizeof (FUNCIONARIO), contador, ficheiro);
        fclose(ficheiro);
    } else {
        printf("\nSEM DADOS GUARDADOS: FICHEIRO FUNCIONARIO RESET\n");
    }

    return contador;
}

//guardar em ficheiro o conteudo do array funcionario

void guardar_ficheiro_funcionario(FUNCIONARIO funcionario[], unsigned int contador) {
    unsigned int i;
    FILE *ficheiro;
    ficheiro = fopen("funcionario.txt", "w+");

    guardar_ficheiro_contadorFuncionario(contador);

    i = fwrite(funcionario, sizeof (FUNCIONARIO), contador, ficheiro);

    if (i == 0) {
        printf("\nERRO NA GRAVACAO DO FICHEIRO FUNCIONARIO\n");
    }

    fclose(ficheiro);
}

//abrir o ficheiro que contem o numero de encomenda

void abrir_ficheiro_contadorEncomenda(unsigned int *contador) {
    FILE *ficheiro;

    ficheiro = fopen("contadorEncomenda.txt", "r+");

    if (ficheiro != NULL) {
        fread(contador, sizeof (unsigned int), 1, ficheiro);
        fclose(ficheiro);
    } else {
        printf("\nSEM DADOS GUARDADOS: FICHEIRO CONTADOR ENCOMENDA RESET\n");
    }
}

//guardar em ficheiro o numero de encomendas existentes

void guardar_ficheiro_contadorEncomenda(unsigned int contador) {
    FILE *ficheiro;
    int i;
    ficheiro = fopen("contadorEncomenda.txt", "w+");

    i = fwrite(&contador, sizeof (unsigned int), 1, ficheiro);

    if (i == 0)
        printf("\nERRO NA GRAVACAO DO FICHEIRO ENCOMENDA\n");
    fclose(ficheiro);
}

//abrir o ficheiro que contem o conteudo do array encomenda

unsigned int abrir_ficheiro_encomenda(ENCOMENDA encomenda[]) {
    FILE *ficheiro;
    unsigned int contador = 0;
    ficheiro = fopen("encomenda.txt", "r+");


    if (ficheiro != NULL) {
        abrir_ficheiro_contadorEncomenda(&contador);
        fread(encomenda, sizeof (ENCOMENDA), contador, ficheiro);
        fclose(ficheiro);
    } else {
        printf("\nSEM DADOS GUARDADOS: FICHEIRO ENCOMENDA RESET\n");
    }

    return contador;
}

//guardar em ficheiro o conteudo do array encomenda

void guardar_ficheiro_encomenda(ENCOMENDA encomenda[], unsigned int contador) {
    unsigned int i;
    FILE *ficheiro;
    ficheiro = fopen("encomenda.txt", "w+");

    guardar_ficheiro_contadorEncomenda(contador);

    i = fwrite(encomenda, sizeof (ENCOMENDA), contador, ficheiro);

    if (i == 0) {
        printf("\nERRO NA GRAVACAO DO FICHEIRO ENCOMENDA\n");
    }

    fclose(ficheiro);
}

//abrir o ficheiro que contem o numero de produto

void abrir_ficheiro_contadorProduto(unsigned int *contador) {
    FILE *ficheiro;

    ficheiro = fopen("contadorProduto.txt", "r+");

    if (ficheiro != NULL) {
        fread(contador, sizeof (unsigned int), 1, ficheiro);
        fclose(ficheiro);
    } else {
        printf("\nSEM DADOS GUARDADOS: FICHEIRO CONTADOR PRODUTO RESET\n");
    }
}

//guardar em ficheiro o numero de produto existentes

void guardar_ficheiro_contadorProduto(unsigned int contador) {
    FILE *ficheiro;
    int i;
    ficheiro = fopen("contadorProduto.txt", "w+");

    i = fwrite(&contador, sizeof (unsigned int), 1, ficheiro);

    if (i == 0)
        printf("\nERRO NA GRAVACAO DO FICHEIRO CONTADOR PRODUTO\n");
    fclose(ficheiro);
}

//abrir o ficheiro que contem o conteudo do array produto

unsigned int abrir_ficheiro_produto(PRODUTO produto[]) {
    FILE *ficheiro;
    unsigned int contador = 0;
    ficheiro = fopen("produto.txt", "r+");


    if (ficheiro != NULL) {
        abrir_ficheiro_contadorProduto(&contador);
        fread(produto, sizeof (PRODUTO), contador, ficheiro);
        fclose(ficheiro);
    } else {
        printf("\nSEM DADOS GUARDADOS: FICHEIRO PRODUTO RESET\n");
    }

    return contador;
}

//guardar em ficheiro o conteudo do array produto

void guardar_ficheiro_produto(PRODUTO produto[], unsigned int contador) {
    unsigned int i;
    FILE *ficheiro;
    ficheiro = fopen("produto.txt", "w+");

    guardar_ficheiro_contadorProduto(contador);

    i = fwrite(produto, sizeof (PRODUTO), contador, ficheiro);

    if (i == 0) {
        printf("\nERRO NA GRAVACAO DO FICHEIRO PRODUTO\n");
    }

    fclose(ficheiro);
}

void guardar_ficheiros(CLIENTE cliente[], FUNCIONARIO funcionario[], USERNAME username[],
        PRODUTO produto[], unsigned const int contadorCliente, unsigned const int contadorFuncionario,
        unsigned const int contadorUsername, unsigned const int contadorProduto) {

    guardar_ficheiro_cliente(cliente, contadorCliente);
    guardar_ficheiro_funcionario(funcionario, contadorFuncionario);
    guardar_ficheiro_username(username, contadorUsername);
    guardar_ficheiro_produto(produto, contadorProduto);
}


