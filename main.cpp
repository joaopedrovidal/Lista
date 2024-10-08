#include <cstdio>
#include <cstdlib>
#include <string>
#include "Lista.h"
#include <iostream>

using namespace std;

/*
    Nome: João Pedro Vidal dos Santos
    Objetivo: Implementar uma lista de palavras com inserção ordenada e sem repetições.
    Entrada de Dados: O usuário deve informar palavras uma de cada vez.
    Saída: As palavras serão inseridas na lista, e o programa informará se a inserção foi bem-sucedida ou se a palavra já existe na lista.
*/

int main() {
    TipoDado x;  // Variável para armazenar a string
    int opcao;  // Variável para o menu
    int posicao;  // Variável para posição

    Lista_Construtor();  // Inicializa a lista

    do {
        system("cls");
        printf("Programa para uso da Lista Singularmente Encadeada de Strings\n\n");
        printf("Escolha uma das opcoes abaixo.\n");
        printf("1 - Inserir palavra (ordenada e sem repeticao)\n");
        printf("2 - Buscar palavra\n");
        printf("3 - Buscar por posicao\n");
        printf("4 - Exibir todas as palavras\n");
        printf("5 - Numero de elementos\n");
        printf("6 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {
            case 1:
                printf("Digite a palavra: ");
                cin >> x;
                if (Lista_Inserir_Ordenada(x))
                    printf("Palavra inserida com sucesso.\n");
                else
                    printf("Erro ao inserir a palavra.\n");
                system("pause");
                break;

            case 2:
                printf("Digite a palavra para buscar: ");
                cin >> x;
                if (Lista_BuscarPeloElemento(x, posicao))
                    printf("Palavra encontrada na posicao %d.\n", posicao);
                else
                    printf("Palavra nao encontrada.\n");
                system("pause");
                break;

            case 3:
                printf("Digite a posicao para buscar: ");
                scanf("%d", &posicao);
                if (Lista_BuscarPelaPosicao(x, posicao))
                    printf("Palavra na posicao %d: %s\n", posicao, x.c_str());
                else
                    printf("Posicao invalida ou lista vazia.\n");
                system("pause");
                break;

            case 4:
                printf("Palavras na lista:\n");
                posicao = 0;
                while (Lista_BuscarPelaPosicao(x, posicao)) {
                    printf("Posicao %d: %s\n", posicao, x.c_str());
                    posicao++;
                }
                system("pause");
                break;

            case 5:
                printf("Numero de elementos na lista: %d\n", Lista_Tamanho());
                system("pause");
                break;

            case 6:
                Lista_Destrutor();
                printf("Sistema finalizado. Lista destruída.\n");
                break;

            default:
                printf("Opcao invalida.\n");
                system("pause");
                break;
        }
    } while (opcao != 6);

    return 0;
}
