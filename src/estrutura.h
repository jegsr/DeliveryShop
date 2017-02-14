

#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>
#include <float.h>
#include <limits.h>

#define MAXIMO_USERNAME 40
#define MAXIMO_CLIENTE 20
#define MAXIMO_FUNCIONARIO 20
#define MAXIMO_ENCOMENDA 20
#define MAXIMO_PRODUTO 20

#define MAXIMO_NOME 21
#define PASSWORD 9
#define MAXIMO_TELEFONES 2
#define MAXIMO_NUMERO_TELEFONE 10
#define MAXIMO_CARTAO_CREDITO 17
#define MAXIMO_CODIDOPOSTAL 9
#define MAXIMO_MORADA 26
#define MAXIMO_ENCOMENDAS 20
#define MAXIMO_QUANTIDADE SHRT_MAX
#define MINIMO_QUANTIDADE 0
#define MAXIMO_PRECO FLT_MAX
#define MINIMO_PRECO 0
#define MAXIMO_CP1 5
#define MAXIMO_CP2 4
#define MINIMO_MES 1
#define MAXIMO_MES 12
#define MINIMO_ANO 2016
#define MAXIMO_ANO 2030
#define MINIMO_ID 0
#define MAXIMO_ID INT_MAX
#define MAXIMO_DIAS31 31
#define MAXIMO_DIAS30 30
#define MAXIMO_DIASBISSEXTO 29
#define MAXIMO_DIASFEVEREIRO 28
#define MINIMO_DIAS 1
#define PRINT_USER_INVALIDO printf("\nUSERNAME INVALIDO\n")
#define PRINT_PASS_INVALIDO printf("\nPASSWORD INVALIDA\n")
#define PRINT_NUMERO_INVALIDO printf("\nNUMERO INVALIDO\n")
#define PRINT_ID_INVALIDO   printf("\nID INVALIDO\n")
#define PRINT_PESQUISA_INVALIDO printf ("\nNENHUM RESULTADO ENCONTRADO\n") 
#define PRINT_MAXIMO_PRODUTOS printf("\nATINGIU O MAXIMO DE PRODUTOS NUMA ENCOMENDA\n");

#define PRINT_MENU printf ("\n********************************************************************************\n");    

#define PRINT_CARTAO_CREDITO printf("\nNº de Cartao de Credito:")
#define PRINT_TELEFONE printf("\nNº de Telefone:")

#define PRINT_BLOQUEIO(a) printf("BLOQUEADO ATE: %s", a)
#define Data(a) printf("Data %s\n",a)
#define PRINT_CP(a) printf("Introduza o Codigo-Postal(Primeiros %d digitos): ",a-1)

#define MAXIMO_TENTATIVA 3

#define Produto "Produto"
#define Encomenda "Encomenda"
#define Cliente "Cliente"
#define Funcionario "Funcionario"
#define PrecoFinal "Final"
#define PrecoUnitario "Unitario"
#define FuncionarAprovar "Funcionario Aprovamento"
#define FuncionarEntrega "Funcionario Entrega"
#define DataEntrega "Entrega"
#define DataPrevista "Prevista"
#define DataProvacao "Aprovacao"  
#define LATITUDE "latitude"
#define LONGITUDE "longitude"

    typedef enum {
        PENDENTE = 1,
        APROVADA,
        ENTREGUE
    } ESTADO;

    typedef enum {
        TRATAMENTO_ENCOMENDAS = 1,
        ENTREGA_ENCOMENDAS,
        GESTOR
    } CARGO;

    typedef struct {
        unsigned short dia;
        unsigned short mes;
        unsigned short ano;
    } DATA;

    typedef struct {
        float latitude;
        float longitude;

    } COORDENADAS;

    typedef struct {
        unsigned int id;
        char nickname[MAXIMO_NOME];
        char password[PASSWORD];
    } USERNAME;

    typedef struct {
        unsigned int id_registo;
        char nome[MAXIMO_NOME];
        char cartao_credito[MAXIMO_CARTAO_CREDITO];
        char telefone[MAXIMO_TELEFONES][MAXIMO_NUMERO_TELEFONE];
        unsigned int contadorTelefone;
    } CLIENTE;

    typedef struct {
        unsigned int id_registo;
        char nome[MAXIMO_NOME];
        CARGO cargo;
    } FUNCIONARIO;

    typedef struct {
        unsigned int id;
        char nome[MAXIMO_NOME];
        float preco;
    } PRODUTO;

    typedef struct {
        char cp1[MAXIMO_CP1];
        char cp2[MAXIMO_CP2];
    } CODIGO_POSTAL;

    typedef struct {
        char rua[MAXIMO_MORADA];
        CODIGO_POSTAL codigo_postal;
        COORDENADAS coordenadas;

    } INFO_MORADA;

    typedef struct {
        unsigned int id_produto;
        unsigned short quantidade;
        float preco_unitario;
    } PRODUTO_ENCOMENDA;

    typedef struct {
        unsigned int id_funcionario_trata;
        unsigned int id_funcionario_entrega;
        DATA data_aprovacao;
        DATA data_prevista;
    } APROVACAO;

    typedef struct {
        unsigned int id;
        unsigned int id_cliente;
        INFO_MORADA morada_entrega;
        PRODUTO_ENCOMENDA produto_encomenda[MAXIMO_PRODUTO];
        unsigned int contador_produto;
        float preco_final;
        ESTADO estado;
        APROVACAO aprovacao;
        DATA data_entrega;
    } ENCOMENDA;

#ifdef __cplusplus
}
#endif

#endif /* ESTRUTURA_H */

