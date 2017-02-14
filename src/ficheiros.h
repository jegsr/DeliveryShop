

#ifndef FICHEIROS_H
#define FICHEIROS_H

#include "estrutura.h"
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif
//ficheiros relativos ao bloqueio do login
void abrir_ficheiro_time(time_t* data);

void guardar_ficheiro_time(time_t data);

//ficheiros relativo ao conteudo do usernames
unsigned int abrir_ficheiro_username(USERNAME user[]);

void guardar_ficheiro_username(USERNAME user[], unsigned  int contador);

//ficheiro relativo ao numero de usernames do sistema
void abrir_ficheiro_contadorUsername(unsigned int* contador);

void guardar_ficheiro_contadorUsername(unsigned int contador);

//ficheiro relativo ao numero de clientes do sistema
void abrir_ficheiro_contadorCliente(unsigned int* contador);

void guardar_ficheiro_contadorCliente(unsigned int contador);

//ficheiro relativo ao conteudo dos clientes
unsigned int abrir_ficheiro_cliente(CLIENTE cliente[]);

void guardar_ficheiro_cliente(CLIENTE cliente[], unsigned int contador);

//ficheiro relativo ao numero de funcionarios 
void abrir_ficheiro_contadorFuncionario(unsigned int* contador);

void guardar_ficheiro_contadorFuncionario(unsigned int contador);

//ficheiro relativo ao conteudo dos funcionarios
unsigned int abrir_ficheiro_funcionario(FUNCIONARIO funcionario[]);

void guardar_ficheiro_funcionario(FUNCIONARIO funcionario[], unsigned int contador);

//ficheiro relativo ao numero de produtos
void abrir_ficheiro_contadorProduto(unsigned int* contador);

void guardar_ficheiro_contadorProduto(unsigned int contador);

//ficheiro relativo ao conteudo dos produtos
unsigned int abrir_ficheiro_produto(PRODUTO produto[]);

void guardar_ficheiro_produto(PRODUTO produto[], unsigned int contador);

//ficheiro relativo ao numero de encomendas
void abrir_ficheiro_contadorEncomenda(unsigned int* contador);

void guardar_ficheiro_contadorEncomenda(unsigned int contador);

//ficheiro relativo ao conteudo das encomendas
unsigned int abrir_ficheiro_encomenda(ENCOMENDA encomenda[]);

void guardar_ficheiro_encomenda(ENCOMENDA encomenda[], unsigned int contador);

void guardar_ficheiros(CLIENTE cliente[], FUNCIONARIO funcionario[], USERNAME username[],
        PRODUTO produto[],unsigned const int contadorCliente, unsigned const int contadorFuncionario,
        unsigned const int contadorUsername, unsigned const int contadorProduto);

#ifdef __cplusplus
}
#endif

#endif /* FICHEIROS_H */

