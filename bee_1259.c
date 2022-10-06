#include <stdio.h>

void junta(int vetor[], int aux[], int imin, int imid, int imax) {
  int iMetade1 = imin, iMetade2 = imid + 1, iVetor = imin;

  for (int i = imin; i <= imax; i++) 
    aux[i] = vetor[i];
  
  while (iVetor <= imax) {
    if (iMetade1 > imid) {
      while (iMetade2 <= imax) {
        vetor[iVetor] = aux[iMetade2];
        iMetade2 += 1;
        iVetor += 1;
      }
      
      break;
    }
    else if (iMetade2 > imax) {
      while (iMetade1 <= imid) {
        vetor[iVetor] = aux[iMetade1];
        iMetade1 += 1;
        iVetor += 1;
      }    

      break;  
    }
    else if (aux[iMetade1] < aux[iMetade2]) {
      vetor[iVetor] = aux[iMetade1];
      iVetor += 1;
      iMetade1 += 1;
    }
    else {
      vetor[iVetor] = aux[iMetade2];
      iVetor += 1;
      iMetade2 += 1;
    }
  }
}

void mergeSort(int vetor[], int aux[], int imin, int imax) {
  if (imax <= imin)
    return;
  else {    
    int imid = imin + ((imax - imin) / 2);

    mergeSort(vetor, aux, imin, imid);
    mergeSort(vetor, aux, imid + 1, imax);

    junta(vetor, aux, imin, imid, imax);
  }
}

int main() {
  int qtdNumeros, pares[100000], impares[100000], aux[100000];
  int iPar = 0, iImpar = 0, num;
  
  scanf("%d", &qtdNumeros);

  for (int i = 0; i < qtdNumeros; i++) {
    scanf("%d", &num);

    if (num % 2 == 0) {
      pares[iPar] = num;
      iPar += 1;
    }
    else {
      impares[iImpar] = num;
      iImpar += 1;
    }
  }

  mergeSort(impares, aux, 0, iImpar - 1);
  mergeSort(pares, aux, 0, iPar - 1);

  for (int i = 0; i < iPar; i++)
    printf("%d\n", pares[i]);
  
  for (int i = iImpar - 1; i >= 0; i--)
    printf("%d\n", impares[i]);
  
  return 0;
}