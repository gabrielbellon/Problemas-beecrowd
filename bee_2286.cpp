#include <iostream>
#include <string>

using namespace std;

int main() {
  char nome1[11], nome2[11];
  int nPartidas, n1, n2, contador = 1;

  scanf("%d", &nPartidas);
  scanf("%s %s", nome1, nome2);
 
  while (nPartidas != 0) {
    printf("Teste %d\n", contador);
    
    for (int i = 0; i < nPartidas; i++) {
      scanf("%d %d", &n1, &n2);

      if ((n1 + n2) % 2 == 0)
        printf("%s\n", nome1);
      else
        printf("%s\n", nome2);
    }
    
    printf("\n");

    scanf("%d", &nPartidas);
    if (nPartidas == 0)
      break;
      
    scanf("%s %s", nome1, nome2);

    contador += 1;
  }

  return 0;
}