#include <stdio.h>
#include <string.h>
#include "struct.h"

struct Entidade {
    char nome[50];
    int vida;
    int iniciativa;
    int tipo;
    int indice_original;
};

// função para ordenar personagens e inimigos
void ordenar_entidades(struct Entidade lista[], int quantidade) {
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = i + 1; j < quantidade; j++) {
            if (lista[j].iniciativa > lista[i].iniciativa) {
                struct Entidade temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}

void combate(struct Personagem *jogadores, int quantidade_jogadores,
             struct Inimigo *inimigos, int quantidade_inimigos) {

    // juntar jogadores e inimigos em uma lista única
    int total = quantidade_jogadores + quantidade_inimigos;
    struct Entidade ordem[total];

    int pos = 0;

    // copiar jogadores
    for (int i = 0; i < quantidade_jogadores; i++) {
        strcpy(ordem[pos].nome, jogadores[i].nome);
        ordem[pos].vida = jogadores[i].vida;
        ordem[pos].iniciativa = jogadores[i].iniciativa;
        ordem[pos].tipo = 0;
        ordem[pos].indice_original = i;
        pos++;
    }

    // copiar inimigos
    for (int i = 0; i < quantidade_inimigos; i++) {
        strcpy(ordem[pos].nome, inimigos[i].nome);
        ordem[pos].vida = inimigos[i].vida;
        ordem[pos].iniciativa = inimigos[i].iniciativa;
        ordem[pos].tipo = 1;
        ordem[pos].indice_original = i;
        pos++;
    }

    // ordenar pela iniciativa
    ordenar_entidades(ordem, total);

    // matriz de estatísticas para jogadores
    int estatisticas[quantidade_jogadores][3];
    memset(estatisticas, 0, sizeof(estatisticas));

    printf("\n=== INÍCIO DO COMBATE ===\n");

    // loop do combate
    while (1) {
        int inimigos_vivos = 0;
        for (int i = 0; i < quantidade_inimigos; i++) {
            if (inimigos[i].vida > 0)
                inimigos_vivos++;
        }
        if (inimigos_vivos == 0)
            break;

        for (int t = 0; t < total; t++) {

            // verifica se o jogador está vivo
            if (ordem[t].tipo == 0 && jogadores[ordem[t].indice_original].vida <= 0)
                continue;

            // verifica se o inimigo está morto
            if (ordem[t].tipo == 1 && inimigos[ordem[t].indice_original].vida <= 0)
                continue;

            printf("\n---- Turno de %s ----\n", ordem[t].nome);

            if (ordem[t].tipo == 0) {
                int jogador_i = ordem[t].indice_original;

                for (int i = 0; i < quantidade_inimigos; i++) {
                    if (inimigos[i].vida <= 0) continue;

                    printf("Atacar %s? (s/n): ", inimigos[i].nome);
                    char r;
                    scanf(" %c", &r);

                    if (r == 's') {
                        int dano;
                        printf("Dano causado: ");
                        scanf("%d", &dano);

                        inimigos[i].vida -= dano;
                        estatisticas[jogador_i][0] += dano;

                        if (inimigos[i].vida <= 0) {
                            inimigos[i].vida = 0;
                            estatisticas[jogador_i][2]++;
                            printf("%s foi derrotado!\n", inimigos[i].nome);
                        }
                    }
                }

            } else {
                int inimigo_i = ordem[t].indice_original;

                for (int j = 0; j < quantidade_jogadores; j++) {
                    if (jogadores[j].vida <= 0) continue;

                    printf("%s atacou %s? (s/n): ",
                           inimigos[inimigo_i].nome,
                           jogadores[j].nome);

                    char r;
                    scanf(" %c", &r);

                    if (r == 's') {
                        int dano;
                        printf("Dano recebido por %s: ", jogadores[j].nome);
                        scanf("%d", &dano);

                        jogadores[j].vida -= dano;
                        estatisticas[j][1] += dano;

                        if (jogadores[j].vida < 0)
                            jogadores[j].vida = 0;
                    }
                }
            }
        }
    }

    printf("\n=== FIM DO COMBATE ===\n");
    for (int i = 0; i < quantidade_jogadores; i++) {
        printf("%s → Dano causado: %d | Dano recebido: %d | Abates: %d\n",
               jogadores[i].nome,
               estatisticas[i][0],
               estatisticas[i][1],
               estatisticas[i][2]);
    }
}