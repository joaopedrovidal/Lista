#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include "Lista.h"

TipoCelula *Frente, *Tras;
int Contador;

void Lista_Construtor() {
    Frente = Tras = NULL;
    Contador = 0;
}

void Lista_Destrutor() {
    TipoCelula *Temp;
    while (Frente != NULL) {
        Temp = Frente;
        Frente = Frente->Prox;
        free(Temp);
    }
    Tras = NULL;
    Contador = 0;
}

bool Lista_Vazia() {
    return Frente == NULL;
}

int Lista_Tamanho() {
    return Contador;
}

bool Lista_Inserir_Ordenada(TipoDado Elemento) {
    // Transformar a string para minúsculas
    std::transform(Elemento.begin(), Elemento.end(), Elemento.begin(), ::tolower);

    // Verificar se o elemento já existe na lista
    TipoCelula *Atual = Frente;
    while (Atual != NULL) {
        if (Atual->Item == Elemento) {
            printf("Elemento '%s' já está na lista!\n", Elemento.c_str());
            return false; // Elemento já existe
        }
        Atual = Atual->Prox;
    }

    // Criar novo nó
    TipoCelula *Novo = (TipoCelula *) malloc(sizeof(TipoCelula));
    if (Novo == NULL) {
        return false;  // Falta de memória
    }
    Novo->Item = Elemento;
    Novo->Prox = NULL;

    // Caso lista esteja vazia
    if (Lista_Vazia()) {
        Frente = Tras = Novo;
    } else {
        // Inserção ordenada
        TipoCelula *Anterior = NULL;
        Atual = Frente;
        while (Atual != NULL && Atual->Item < Elemento) {
            Anterior = Atual;
            Atual = Atual->Prox;
        }

        if (Anterior == NULL) {
            // Inserir no início
            Novo->Prox = Frente;
            Frente = Novo;
        } else if (Atual == NULL) {
            // Inserir no fim
            Tras->Prox = Novo;
            Tras = Novo;
        } else {
            // Inserção no meio
            Anterior->Prox = Novo;
            Novo->Prox = Atual;
        }
    }

    Contador++;
    printf("Elemento '%s' inserido com sucesso.\n", Elemento.c_str());
    return true;
}

bool Lista_Inicio(TipoDado &Elemento) {
    if (!Lista_Vazia()) {
        Elemento = Frente->Item;
        return true;
    } else {
        return false;
    }
}

bool Lista_Fim(TipoDado &Elemento) {
    if (!Lista_Vazia()) {
        Elemento = Tras->Item;
        return true;
    } else {
        return false;
    }
}

bool Lista_BuscarPeloElemento(TipoDado Elemento, int &Posicao) {
    std::transform(Elemento.begin(), Elemento.end(), Elemento.begin(), ::tolower);

    TipoCelula *Temp = Frente;
    int i = 0;

    if (!Lista_Vazia()) {
        while (Temp != NULL && Temp->Item != Elemento) {
            i++;
            Temp = Temp->Prox;
        }

        if (Temp != NULL) {
            Posicao = i;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool Lista_BuscarPelaPosicao(TipoDado &Elemento, int Posicao) {
    TipoCelula *Temp = Frente;
    int i = 0;

    if (!Lista_Vazia()) {
        if (Posicao < 0 || Posicao >= Contador) return false;

        while (i < Posicao) {
            i++;
            Temp = Temp->Prox;
        }

        Elemento = Temp->Item;
        return true;
    } else {
        return false;
    }
}
