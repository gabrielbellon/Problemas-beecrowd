#include <iostream>

using namespace std;

#include <string.h>

int main() {
  int qtdPEspeciais, qtdCargos, valorCargo = 0;

  scanf("%d %d", &qtdPEspeciais, &qtdCargos);

  char palavrasEspeciais[qtdPEspeciais + 1][17], palavraTexto[17];
  int valorPalavras[qtdPEspeciais];

  for (int i = 0; i < qtdPEspeciais; i++) {
    scanf("%s %d", palavrasEspeciais[i], &valorPalavras[i]);
  }

  for (int i = 0; i < qtdCargos; i++) {
    while (1) {
      scanf("%s", palavraTexto);

      if (strcmp(palavraTexto, ".") == 0)
        break;

      for (int j = 0; j < qtdPEspeciais; j++) {
        if (strcmp(palavraTexto, palavrasEspeciais[j]) == 0) {
          valorCargo += valorPalavras[j];
          break;
        }        
      }
    }

    printf("%d\n", valorCargo);
    valorCargo = 0;
  }
  
  return 0;
}