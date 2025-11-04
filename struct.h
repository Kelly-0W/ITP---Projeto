// verifica se já não esxiste outro struct_h
#ifndef STRUCTS_H

// define um novo
#define STRUCTS_H

// armazena informações de um jogador
struct Personagem {
    char nome[50];
    int vida;
    int iniciativa;
};

// armazena informações de um inimigo
struct Inimigo {
    char nome[50];
    int vida;
};

#endif