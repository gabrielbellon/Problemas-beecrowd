#include <iostream>

using namespace std;

int main() {
  int nPartidas, golsTime, golsContra, saldoGols = - 1, melhorP[2], melhorTemp[2], saldoGolsMelhorP = 0;

  for (int j = 1;; j++) {
    scanf("%d", &nPartidas);

    if (nPartidas == 0)
      break;

    for (int i  = 0; i < nPartidas; i++) {
      scanf("%d %d", &golsTime, &golsContra);
  
      if (saldoGols < 0) { 
        saldoGols = golsTime - golsContra;

        if (saldoGols >= saldoGolsMelhorP) {  
          saldoGolsMelhorP = saldoGols; 

          melhorTemp[0] = i + 1;
          melhorTemp[1] = i + 1;
        }

        melhorP[0] = i + 1;
        melhorP[1] = i + 1;
      }
      else {
        saldoGols += golsTime - golsContra;

        if (saldoGols >= saldoGolsMelhorP) {
          saldoGolsMelhorP = saldoGols;
          melhorP[1] = i + 1;
          melhorTemp[0] = melhorP[0];
          melhorTemp[1] = i + 1;
        }
      }
    }

    printf("Teste %d\n", j);

    if (saldoGolsMelhorP <= 0)
      printf("nenhum\n\n");
    else if (melhorP[1] == melhorP[0])
      printf("%d %d\n\n", melhorTemp[0], melhorTemp[1]);
    else
      printf("%d %d\n\n", melhorP[0], melhorP[1]);


    saldoGols = - 1;
    saldoGolsMelhorP = 0;
  }

  return 0;
}