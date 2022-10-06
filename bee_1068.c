#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main() {
  char expressao[MAX + 1], caractere;
  int parenteses = 0, ultimo;

  /*
   parenteses pra esquerda ')' soma negativo, pra direita '(' soma positivo. Se em algum momento for menor que 0,ou se no final for maior que 0, não é correto. 
  */

  while (1) { 
    if (scanf(" %s", expressao) == EOF)
      break;

    for (int i = 0; i < strlen(expressao); i++) {
      if (expressao[i] == '(')
        parenteses += 1;
      if (expressao[i] == ')')
        parenteses -= 1;

      if (parenteses < 0)
        break;
    }

    if (parenteses != 0)
      printf("incorrect\n");
    else
      printf("correct\n");

    parenteses = 0;
  } 

  return 0;
}