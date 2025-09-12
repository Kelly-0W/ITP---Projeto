#include <stdio.h>
#include <string.h>

struct Personagem
{
   char nome[50];
   int vida;
   int iniciativa;
};

int main() {
   int numerojogadores;

   printf("Digite o numero de jogadores: ");
   scanf("%d", &numerojogadores);
};