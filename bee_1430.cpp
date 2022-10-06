#include <iostream>

int main() {
  int qtdCertos;
  char musica[201];
  float somaCompasso;

  while (1) {
    scanf("%s", musica);

    if (musica[0] == '*')
      break;

    somaCompasso = 0;
    qtdCertos = 0;
    
    for (int i = 1; musica[i] != '\0'; i++) {
      if (musica[i] == '/' && somaCompasso > 0.9999999 && somaCompasso < 1.0000099) {
        somaCompasso = 0;
        qtdCertos += 1;
        continue;
      }
      else if (musica[i] == '/') {
        somaCompasso = 0;
        continue;
      }
      else {
        if (musica[i] == 'W')
          somaCompasso += 1;
        
        if (musica[i] == 'H')
          somaCompasso += 0.5;

        if (musica[i] == 'Q')
          somaCompasso += 0.25;

        if (musica[i] == 'E')
          somaCompasso += 0.125;

        if (musica[i] == 'S')
          somaCompasso += 0.0625;

        if (musica[i] == 'T')
          somaCompasso += 0.03125;

        if (musica[i] == 'X')
          somaCompasso += 0.015625;
      }
    }

    printf("%d\n", qtdCertos);
  }

  return 0;
}