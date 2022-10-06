#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
  int qtdTestes, contador = 0, qtdDiamantes = 0;
  char mina[MAX + 1];

  scanf("%d", &qtdTestes);

  for (int i = 0; i < qtdTestes; i++) {
    scanf("%s", mina);

    for (int j = 0; mina[j] != '\0'; j++) {
      if (mina[j] == '<')
        contador += 1;
      else if (contador > 0 && mina[j] == '>') {
        contador -= 1;
        qtdDiamantes += 1;
      }
    }

    printf("%d\n", qtdDiamantes);
    qtdDiamantes = 0;
    contador = 0;
  }

  return 0;
}