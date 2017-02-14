/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu_listar_admin.h
 * Author: luis_
 *
 * Created on 17 de Fevereiro de 2016, 19:23
 */

#ifndef MENU_LISTAR_ADMIN_H
#define MENU_LISTAR_ADMIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "estrutura.h"
    
    void pesquisar_Encomenda(ENCOMENDA encomenda[], unsigned const int contadorEncomenda);

    void pesquisar_Funcionario(FUNCIONARIO funcionario[], unsigned const int contadorFuncionario);

    void pesquisar_Cliente(CLIENTE cliente[], unsigned const int contadorCliente);

    void menu_listar(PRODUTO produto[], ENCOMENDA encomenda[], FUNCIONARIO funcionario[], CLIENTE cliente[],
            unsigned int contadorCliente, unsigned const int contadorFuncionario, unsigned const int contadorEncomenda,
            unsigned const int contadorProduto);


#ifdef __cplusplus
}
#endif

#endif /* MENU_LISTAR_ADMIN_H */

