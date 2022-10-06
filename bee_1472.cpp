#include <iostream>

using namespace std;

int buscaBinaria(int vetor[], int tamanho, int elemento) {
  int imax = tamanho - 1, imin = 0, imid = 0;

  while (imin <= imax) {
    imid = imin + ((imax - imin) / 2);

    if (elemento == vetor[imid])
      return vetor[imid];
    else if (elemento > vetor[imid])
      imin = imid + 1;
    else if (elemento < vetor[imid])
      imax = imid - 1;
  }

  return -1;
}

int main() {
  int qtdPontos, pontos[100000], arco, somaPontos = 0, elem;
  int qtdTriangulos = 0;

  /* 
    Precisamos achar 3 pontos que possuem o mesmo arco de distancia entre si
    para formarmos um triangulo equilatero.
  */
  
  while(1) {
    if (scanf("%d", &qtdPontos) == EOF)
      break;

    somaPontos = 0;
    qtdTriangulos = 0;
    
    for (int i = 0; i < qtdPontos; i++) {
      scanf("%d", &elem);
      somaPontos += elem;
      pontos[i] = somaPontos;
    }

    if (somaPontos % 3 != 0) {
      printf("%d\n", 0);
      continue;
    }
    
    arco = somaPontos / 3;

    for (int i = 0; i < qtdPontos / 2; i++) { // So precisamos fazer ate a metade.
      if (buscaBinaria(pontos, qtdPontos, pontos[i] + arco) == - 1)
        continue;
      
      if (buscaBinaria(pontos, qtdPontos, pontos[i] + arco * 2) == - 1)
        continue;

      qtdTriangulos += 1;

      // Se essas duas buscas binarias nao retornarem -1 quer dizer que achamos 3
      // pontos que possuem a distancia de 1 arco entre si.
    }

    printf("%d\n", qtdTriangulos);
  }
  
  return 0;
}