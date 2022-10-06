#include <iostream>
#include <string.h>

typedef struct {
  char tam;
  char nome[60];
  char cor[20];
} pessoa;

void ordenaTamanho(pessoa pessoas[], int tamanho) {
  pessoa aux;
  
  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < tamanho - 1; j++) {
      if ((pessoas[j].tam == 'M' && pessoas[j + 1].tam == 'P') || (pessoas[j].tam == 'G' && (pessoas[j + 1].tam == 'M' || pessoas[j + 1].tam == 'P'))) {
        aux = pessoas[j];
        pessoas[j] = pessoas[j + 1];
        pessoas[j + 1] = aux;
      }
    }
  }
}

void ordenaCor(pessoa pessoas[], int tamanho) {
  pessoa aux;
  
  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < tamanho - 1; j++) {
      if (strcmp(pessoas[j].cor, pessoas[j + 1].cor) > 0) {
        aux = pessoas[j];
        pessoas[j] = pessoas[j + 1];
        pessoas[j + 1] = aux;        
      }
    }
  }  
}

void ordenaNome(pessoa pessoas[], int tamanho) {
  pessoa aux;
  
  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < tamanho - 1; j++) {
      if (strcmp(pessoas[j].nome, pessoas[j + 1].nome) > 0) {
        aux = pessoas[j];
        pessoas[j] = pessoas[j + 1];
        pessoas[j + 1] = aux;        
      }
    }
  }    
}

int main() {
  int qtdCamisetas;
  pessoa pessoas[65];

  for (int i = 0;; i++) {
    scanf("%d", &qtdCamisetas);

    if (qtdCamisetas == 0)
      break;

    if (i != 0)
      printf("\n");

    for (int i = 0; i < qtdCamisetas; i++) {
      scanf("\n%[^\n]", pessoas[i].nome);
      scanf("%s\n", pessoas[i].cor);
      scanf("%c", &pessoas[i].tam);
    }
    
    ordenaNome(pessoas, qtdCamisetas);
    ordenaTamanho(pessoas, qtdCamisetas);
    ordenaCor(pessoas, qtdCamisetas);

    for (int i = 0; i < qtdCamisetas; i++) {
      printf("%s ", pessoas[i].cor);
      printf("%c ", pessoas[i].tam);
      printf("%s\n", pessoas[i].nome);
    }   
  }
}