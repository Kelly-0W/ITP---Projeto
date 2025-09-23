#include <stdio.h>
#include <string.h>

//guardar informações dos personagens
struct Personagem
{
   char nome[50];
   int vida;
   int iniciativa;
};

void cadastrar_jogadores(struct Personagem jogadores[], int nummero) {

   for (int i = 0; i < numero; i++) {
      printf("\nJogador %d: \n", i + 1);

      printf("Nome: ");
      scanf("%s", jogadores[i].nome);

      printf("Vida: ");
      scanf("%d", &jogadores[i].vida);

      printf("Iniciativa: ");
      scanf("%d", &jogadores[i].iniciativa);
   }
   };

void aplicar_buff(struct Personagem jogadores[], int numero) {
   char resposta;

   printf("Tem algum buff para ser aplicado? (s/n)");
   scanf(" %c" &resposta);

   char alvo[50];
   char atributo[20];
   int valor;

   while (resposta == "s") {
   
   printf("Qual jogador vai receber o buff?");
   scanf("%s", alvo);

   printf ("Qual atributo vai receber buff? (velocidade/iniciativa)");
   scanf("%d", &atributo);

   printf("Qual o valor do bônus?");
   scanf("%d", &valor);

   }
}

int main() {
   int numero_jogadores;

   printf("Digite o numero de jogadores: ");
   scanf("%d", &numero_jogadores);

   //ordena jogadores do maior para o menor
   for (int i = 0; i < numero_jogadores; i++) {
      int maior_iniciativa = i;

      //procura alguém com iniciativa maior que a atual
      for (int a = i + 1; a < numero_jogadores; a++) {
         if (jogadores[a].iniciativa > jogadores[maior_iniciativa].iniciativa) {
            maior_iniciativa = a;
         }
      }

      //troca o jogador atual pelo maior encontrado
      if (maior_iniciativa != i) {
         struct Personagem e = jogadores[i];
         jogadores[i] = jogadores[maior_iniciativa];
         jogadores[maior_iniciativa] = e;
      }
   }

      //exibe a ordem final
   printf("\n --- Ordem dos turnos --- \n");
   for (int i = 0; i < numero_jogadores; i++) {
      printf("%s, Iniciativa: %d\n",
         jogadores[i].nome,
         jogadores[i].iniciativa);

      }

   return 0;
};