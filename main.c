#include <stdio.h>
#include "struct.h"

// declarações das funções de outros arquivos
void cadastrar_jogadores(struct Personagem[], int);
void mostrar_jogadores(struct Personagem[], int);

void cadastrar_inimigos(struct Inimigo[], int);
void mostrar_inimigos(struct Inimigo[], int);

void combate(struct Personagem*, int, struct Inimigo*, int);

int main() {
    struct Personagem jogadores[10];
    struct Inimigo inimigos[10];

    int quantidade_jogadores = 0;
    int quantidade_inimigos = 0;

    printf("Quantos jogadores deseja cadastrar? ");
    scanf("%d", &quantidade_jogadores);

    cadastrar_jogadores(jogadores, quantidade_jogadores);

    printf("Quantos inimigos estarão no combate? ");
    scanf("%d", &quantidade_inimigos);

    cadastrar_inimigos(inimigos, quantidade_inimigos);

    printf("\n--- Jogadores cadastrados ---\n");
    mostrar_jogadores(jogadores, quantidade_jogadores);

    printf("\n--- Inimigos cadastrados ---\n");
    mostrar_inimigos(inimigos, quantidade_inimigos);

    printf("\nIniciando o combate...\n");
    combate(jogadores, quantidade_jogadores, inimigos, quantidade_inimigos);

    return 0;
}