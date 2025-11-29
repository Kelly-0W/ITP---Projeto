#include <stdio.h>
#include <string.h>
#include "struct.h"

// cadastrar inimigos
void cadastrar_jogadores(struct Personagem lista_jogadores[], int quantidade_jogadores) {
    for (int i = 0; i < quantidade_jogadores; i++) {

        printf("\nJogador %d:\n", i + 1);

        printf("Nome: ");
        scanf("%s", lista_jogadores[i].nome);

        printf("Vida inicial: ");
        scanf("%d", &lista_jogadores[i].vida);

        printf("Iniciativa: ");
        scanf("%d", &lista_jogadores[i].iniciativa);
    }
}

// cadastrar inimigos
void cadastrar_inimigos(struct Inimigo lista_inimigos[], int quantidade_inimigos) {
    for (int i = 0; i < quantidade_inimigos; i++) {
        printf("\nInimigo %d:\n", i + 1);

        printf("Nome: ");
        scanf("%s", lista_inimigos[i].nome);

        printf("Vida inicial: ");
        scanf("%d", &lista_inimigos[i].vida);

        printf("Iniciativa: ");       
        scanf("%d", &lista_inimigos[i].iniciativa);
    }
}

// mostrar jogadores
void mostrar_jogadores(struct Personagem jogadores[], int quantidade_jogadores) {
    printf("\n--- Lista de Jogadores ---\n");
    for (int i = 0; i < quantidade_jogadores; i++) {
        printf("%s | Vida: %d | Iniciativa: %d\n",
               jogadores[i].nome,
               jogadores[i].vida,
               jogadores[i].iniciativa);
    }
}

// mostrar inimigos cadastrados
void mostrar_inimigos(struct Inimigo inimigos[], int quantidade_inimigos) {
    printf("\n--- Lista de Inimigos ---\n");
    for (int i = 0; i < quantidade_inimigos; i++) {
        printf("%s | Vida: %d\n",
               inimigos[i].nome,
               inimigos[i].vida);
    }
}