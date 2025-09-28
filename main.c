#include <stdio.h>
#include <string.h>

//guardar informações dos personagens
struct Personagem
{
   char nome[50];
   int vida;
   int iniciativa;
};

//função para cadastrar personagem
void cadastrar_jogadores(struct Personagem jogadores[], int numero) {

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

//função para buff
void aplicar_buff(struct Personagem jogadores[], int numero) {
   char resposta;
   char alvo[50];
   char atributo[20];
   int valor;

   //perguntar se há buff ou não
   printf("Tem algum buff para ser aplicado? (s/n): ");
   scanf(" %c", &resposta);

   while (resposta == 's') {
   
   //saber qual o jogador e o tipo de buff
   printf("Qual jogador vai receber o buff? ");
   scanf(" %49s", alvo);

   printf ("Qual atributo vai receber buff? (vida/iniciativa) ");
   scanf(" %19s", atributo);

   if (strcmp(atributo, "vida") != 0 && strcmp(atributo, "iniciativa") != 0) {
      printf("Atributo inválido! Digite apenas 'vida' ou 'iniciativa'\n");
   }

   printf("Qual o valor do bônus?");

   if (scanf("%d", &valor) != 1) {
      printf("Entrada inválida! Digite apenas um valor númerico\n");

      //limpar buff
      while(getchar() != '\n');
   }
   
   //procurar jogador
   int encontrado = 0;
   for (int i = 0; i < numero; i++) {
      if (strcmp(jogadores[i].nome, alvo) == 0) {
         if (strcmp(atributo, "vida") == 0) {
            jogadores[i].vida += valor;
            printf("%s agora tem %d de vida\n", jogadores[i].nome, jogadores[i].vida);
         }
         else if (strcmp(atributo, "iniciativa") == 0) {
            jogadores[i].iniciativa += valor;
            printf("%s agora tem %d de iniciativa\n", jogadores[i].nome, jogadores[i].iniciativa);
         }
         encontrado = 1;
         break;
      }
   }
   
   //caso não tenha jogador com o nome escrito
   if (!encontrado) {
      printf("Jogador não encontrado!\n");
   }

   //possibilidade de outro buff
   printf("Deseja aplicar outro buff? (s/n): ");
   scanf(" %c", &resposta);
   }
}

//função para ordenar os personagens pela iniciativa
void ordenar_personagens(struct Personagem jogadores[], int numero) {

   for (int i = 0; i < numero; i++) {
      int maior_iniciativa = i;

      //procura alguém com iniciativa maior que a atual
      for (int a = i + 1; a < numero; a++) {
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
}

void mostrar_ordem(struct Personagem jogadores[], int numero) {

      printf("\n --- Ordem dos turnos --- \n");
   for (int i = 0; i < numero; i++) {
      printf("%s, Iniciativa: %d\n",
         jogadores[i].nome,
         jogadores[i].iniciativa);

      }
}
int main() {
   int numero_jogadores;

   printf("Digite o numero de jogadores: ");
   scanf("%d", &numero_jogadores);

   struct Personagem jogadores[numero_jogadores];
   cadastrar_jogadores(jogadores, numero_jogadores);
   aplicar_buff(jogadores, numero_jogadores);
   ordenar_personagens(jogadores, numero_jogadores);
   mostrar_ordem(jogadores, numero_jogadores);
   
   return 0;
};