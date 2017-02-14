#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "estrutura.h"
#include "LP_Leitura.h"
#include "Produto.h"
#include "LP_Utils.h"
#include "Encomenda.h"
#include "Funcionario.h"
#include "Cliente.h"

void adicionar_ID(unsigned int *id, unsigned int contador) {
    *id = contador;
}

void listar_ID(unsigned int id, char texto[]) {

    printf("\nID %s: %u\n", texto, id);

}

void adicionar_Nome(char nome[]) {

    readString(nome, MAXIMO_NOME, "Nome: ");

}

void listar_Nome(char nome[]) {

    printf("Nome: %s\n", nome);

}

void adicionar_Preco(float *preco) {

    readFloat(preco, MINIMO_PRECO, MAXIMO_PRECO, "Preco: ");

}

void listar_Preco(char texto[], float preco) {

    printf("Preco %s: %.2f\n", texto, preco);

}

bool verificarQuantidadeNumero(char numero[], unsigned const int quantidade) {
    unsigned int i = 0;
    unsigned int tamanho = strlen(numero);

    if (tamanho == quantidade) {
        while (i < quantidade) {
            switch (numero[i]) {
                case '0':break;
                case '1':break;
                case '2':break;
                case '3':break;
                case '4':break;
                case '5':break;
                case '6':break;
                case '7':break;
                case '8':break;
                case '9':break;
                default: i = 14;
                    break;
            }
            i++;
        }
        if (i == quantidade) {
            return true;
        }
    }
    return false;
}

void adicionarNumerosChar(char numero[], unsigned const int quantidade) {
    bool found = true;
    do {

        readString(numero, quantidade, " ");

        found = verificarQuantidadeNumero(numero, quantidade - 1);

        if (found == false) {

            PRINT_NUMERO_INVALIDO;

        }

    } while (found == false);
}

/**
 * pesquisa binário sendo que os funcionarios nunca são ordenados e estao 
 * ordenados pelos id's devido a forma que adiciona funcionarios
 * */
int encontrarID_Funcionario(unsigned const int id_procurado, FUNCIONARIO funcionario[], unsigned const int contador) {
    int inicio = 0, fim = contador - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (funcionario[meio].id_registo == id_procurado)
            return meio;
        else {
            if (funcionario[meio].id_registo > id_procurado) {
                fim = meio - 1;
            } else {
                inicio = meio + 1;
            }
        }
    }

    return -1;
}

/**
 * pesquisa binário sendo que os cliente nunca são ordenados e estao 
 * ordenados pelos id's devido a forma que adiciona cliente
 * */
int encontrarID_Cliente(unsigned const int id_procurado, CLIENTE cliente[], unsigned const int contador) {
    int inicio = 0, fim = contador - 1, meio = 0;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (cliente[meio].id_registo == id_procurado)
            return meio;
        else {
            if (cliente[meio].id_registo > id_procurado) {
                fim = meio - 1;
            } else {
                inicio = meio + 1;
            }
        }
    }

    return -1;
}

/**
 * pesquisa linear de produto
 * 
 */
int encontrarID_Produto(unsigned const int id_procurado, PRODUTO produto[], unsigned const int contador) {
    int i = 0;
    while (i < contador && produto[i].id != id_procurado) {
        i++;
    }

    if (i == contador)
        return -1;
    return i;
}

/**
 * pesquisa linear de produto
 * @param encomenda
 * @param id_procurado
 * @param contador
 * @return o indice do indice procurado ou -1 em caso de nao existir
 */
int encontrarID_Encomenda(ENCOMENDA encomenda[], unsigned const int id_procurado, unsigned const int contador) {
    int i = 0;
    while (i < contador && encomenda[i].id != id_procurado) {
        i++;
    }

    if (i == contador)
        return -1;

    return i;
}

int encontrarID_EncomendaEstado(unsigned const int id_procurado, ENCOMENDA encomenda[], unsigned const int contador, ESTADO estado) {
    int i = encontrarID_Encomenda(encomenda, id_procurado, contador);

    if (i != -1 && encomenda[i].estado == estado)
        return i;

    return -1;
}

int verificarID_EncomendaPorEstado(ENCOMENDA encomenda[], unsigned const int contador, ESTADO estado) {
    unsigned int temp_id = -1;
    int found;

    if (contador > 0) {
        do {

            readInt(&temp_id, MINIMO_ID, MAXIMO_ID, "Escolha o id da encomenda: ");



            found = encontrarID_EncomendaEstado(temp_id, encomenda, contador, estado);

            if (found == -1) {

                PRINT_ID_INVALIDO;

                puts("AJUDA: ENCOMENDAS EXISTENTES\n");

                listar_Encomendas_Estado(encomenda, contador, estado);

            }

        } while (found == -1);
    } else {
        PRINT_MENU
        PRINT_PESQUISA_INVALIDO;
        PRINT_MENU
    }

    return temp_id;
}

int encontrarID_EncomendaEstado_E_FuncionarioEntrega(unsigned const int id_procurado, ENCOMENDA encomenda[],
        unsigned const int contador, unsigned const int id_funcionario) {


    int i = encontrarID_Encomenda(encomenda, id_procurado, contador);

    if (i != -1 && encomenda[i].estado == APROVADA && encomenda[i].aprovacao.id_funcionario_entrega == id_funcionario)
        return i;

    return -1;
}

int verificarID_EncomendaParaFuncionarioEntrega(ENCOMENDA encomenda[], unsigned const int contador, unsigned const int id_funcionario) {
    unsigned int temp_id = -1;
    int found;
    if (contador > 0) {
        do {

            readInt(&temp_id, -1, MAXIMO_ID, "Escolha o id da encomenda ( -1=Sair ): ");

            if (temp_id != -1) {
                found = encontrarID_EncomendaEstado_E_FuncionarioEntrega(temp_id, encomenda, contador, id_funcionario);

                if (found == -1) {

                    PRINT_ID_INVALIDO;

                    puts("AJUDA: ENCOMENDAS EXISTENTES\n");

                    listar_EncomendasAprovadas_FuncionarioEntrega(encomenda, id_funcionario, contador);
                }
            }
        } while (temp_id != -1 && found == -1);
    } else {
        PRINT_MENU
        PRINT_PESQUISA_INVALIDO;
        PRINT_MENU
    }
    return temp_id;
}

int encontrarID_FuncionarioCargo(unsigned int id_procurado, FUNCIONARIO funcionario[], unsigned int contador, CARGO cargo) {
    int i;

    i = encontrarID_Funcionario(id_procurado, funcionario, contador);

    if (i != -1 && funcionario[i].cargo == cargo)
        return i;

    return -1;
}

int verificarID_FuncionarioPorCargo(FUNCIONARIO funcionario[], unsigned int contador, CARGO cargo) {
    unsigned int temp_id = -1;
    int found;
    if (contador > 0) {
        do {

            readInt(&temp_id, -1, MAXIMO_ID, "Escolha o id do funcionario ( -1=Sair ): ");


            if (temp_id != -1) {
                found = encontrarID_FuncionarioCargo(temp_id, funcionario, contador, cargo);

                if (found == -1) {

                    PRINT_ID_INVALIDO;

                    puts("AJUDA: FUNCIONARIOS EXISTENTES");

                    listar_FuncionarioPorCargo(funcionario, contador, cargo);
                }
            }
        } while (temp_id != -1 && found == -1);
    } else {

        PRINT_PESQUISA_INVALIDO;

    }
    return temp_id;
}

int encontrarID_EncomendaEstado_E_FuncionarioAprova(unsigned const int id_procurado, ENCOMENDA encomenda[],
        unsigned const int contador, unsigned const int id_funcionario) {


    int i = encontrarID_Encomenda(encomenda, id_procurado, contador);

    if (i != -1 && encomenda[i].estado == ENTREGUE && encomenda[i].aprovacao.id_funcionario_trata == id_funcionario)
        return i;

    return -1;
}

int verificarID_EncomendaParaFuncionarioAprova(ENCOMENDA encomenda[], unsigned int contador, unsigned int id_funcionario) {
    int temp_id = -1;
    int found;
    if (contador > 0) {
        do {

            readInt(&temp_id, -1, MAXIMO_ID, "Escolha o id da encomenda ( -1=sair ): ");


            if (temp_id != -1) {
                found = encontrarID_EncomendaEstado_E_FuncionarioAprova(temp_id, encomenda, contador, id_funcionario);

                if (found == -1) {

                    PRINT_ID_INVALIDO;

                    puts("AJUDA: ENCOMENDAS EXISTENTES\n");

                    listar_EncomendasEntregue_FuncionarioAprovar(encomenda, id_funcionario, contador);
                }
            }
        } while (temp_id != -1 && found == -1);
    } else {

        PRINT_PESQUISA_INVALIDO;

    }
    return temp_id;
}

int verificarID_Produto(PRODUTO produto[], unsigned const int contador) {
    int temp_id = -1;
    int found;
    if (contador > 0) {
        do {

            readInt(&temp_id, -1, MAXIMO_ID, "Escolha o id de produto: ");



            found = encontrarID_Produto(temp_id, produto, contador);

            if (found == -1) {

                PRINT_ID_INVALIDO;

                puts("AJUDA: PRODUTOS EXISTENTES\n");

                listarTodos_Produto(produto, contador);
            }

        } while (found == -1);
    } else {

        PRINT_PESQUISA_INVALIDO;

    }
    return temp_id;
}

int verificarID_Encomenda(ENCOMENDA encomenda[], unsigned const int contador) {
    unsigned int temp_id = -1;
    int found;
    if (contador > 0) {
        do {

            readInt(&temp_id, MINIMO_ID, MAXIMO_ID, "Escolha o id da encomenda: ");



            found = encontrarID_Encomenda(encomenda, temp_id, contador);

            if (found == -1) {

                PRINT_ID_INVALIDO;

                puts("AJUDA: ENCOMENDAS EXISTENTES\n");

                listarTodas_Encomenda(encomenda, contador);
            }

        } while (found == -1);
    } else {

        PRINT_PESQUISA_INVALIDO;

    }
    return temp_id;
}

int verificarID_Funcionario(FUNCIONARIO funcionario[], unsigned int contador) {
    unsigned int temp_id = -1;
    int found;
    if (contador > 0) {
        do {

            readInt(&temp_id, MINIMO_ID, MAXIMO_ID, "Escolha o id do funcionario: ");


            if (temp_id != -1) {
                found = encontrarID_Funcionario(temp_id, funcionario, contador);

                if (found == -1) {

                    PRINT_ID_INVALIDO;


                    puts("AJUDA: FUNCIONARIOS EXISTENTES");

                    listarTodos_Funcionario(funcionario, contador);
                }
            }
        } while (found == -1);
    } else {

        PRINT_PESQUISA_INVALIDO;
    }
    return temp_id;
}

int verificarID_Cliente(CLIENTE cliente[], unsigned int contador) {
    unsigned int temp_id = -1;
    int found;
    if (contador > 0) {
        do {

            readInt(&temp_id, MINIMO_ID, MAXIMO_ID, "Escolha o id do cliente: ");


            if (temp_id != -1) {
                found = encontrarID_Cliente(temp_id, cliente, contador);

                if (found == -1) {

                    PRINT_ID_INVALIDO;

                    puts("AJUDA: CLIENTES EXISTENTES");

                    listarTodos_Cliente(cliente, contador);
                }
            }
        } while (found == -1);
    } else {
        PRINT_MENU
        PRINT_PESQUISA_INVALIDO;
        PRINT_MENU
    }
    return temp_id;
}