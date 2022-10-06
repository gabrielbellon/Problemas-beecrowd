#include <stdio.h>
#include <string.h>

int main() {
  char linha[1001], aux;
  int qtdTestes, tam;

  scanf("%d\n", &qtdTestes);

  for (int i = 0; i < qtdTestes; i++) {
    scanf(" %[^\n]", linha);

    tam = strlen(linha);
    
    for (int j = 0; linha[j] != '\0'; j++) {
      if (linha[j] >= 'a' && linha[j] <= 'z' || linha[j] >= 'A' && linha[j] <= 'Z')
        linha[j] += 3;
    }

    for (int j = 0; j < tam / 2; j++) {
      aux = linha[j];
      linha[j] = linha[tam - j - 1];
      linha[tam - j - 1] = aux;
    }

    for (int j = tam / 2; linha[j] != '\0'; j++)
      linha[j] -= 1;

    printf("%s\n", linha);
  }
 
  return 0;
}