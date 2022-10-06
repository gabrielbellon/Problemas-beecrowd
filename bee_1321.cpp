#include <iostream>

int main() {
  int princesa[3], principe[2], carta;

  while (1) {
    carta = 0;
    
    for (int i = 0; i < 3; i++) {
      scanf("%d", &princesa[i]);
    }

    if (princesa[0] == 0)
      break;

    for (int i = 0; i < 2; i++)
      scanf("%d", &principe[i]);

    if (princesa[0] > principe[0] && princesa[1] > principe[1])
      carta = -1;
    else if (princesa[0] < principe[0] && princesa[1] < principe[1]) {
      if (1 > carta && carta != -1)
        carta = 1;
    }
    else if (princesa[2] + 1 > carta && carta != -1)
      carta = princesa[2] + 1;

    if (princesa[0] > principe[1] && princesa[1] > principe[0])
      carta = -1;
    else if (princesa[0] < principe[1] && princesa[1] < principe[0]) {
      if (1 > carta && carta != -1)
        carta = 1;
    }
    else if (princesa[2] + 1 > carta && carta != -1)
      carta = princesa[2] + 1;  

    if (princesa[2] > principe[0] && princesa[1] > principe[1])
      carta = -1;
    else if (princesa[2] < principe[0] && princesa[1] < principe[1]) {
      if (1 > carta && carta != -1)
        carta = 1;
    }
    else if (princesa[0] + 1 > carta && carta != -1)
      carta = princesa[0] + 1;   

    if (princesa[2] > principe[1] && princesa[1] > principe[0])
      carta = -1;
    else if (princesa[2] < principe[1] && princesa[1] < principe[0]) {
      if (1 > carta && carta != -1)
        carta = 1;
    }
    else if (princesa[0] + 1 > carta && carta != -1)
      carta = princesa[0] + 1;

    if (princesa[2] > principe[0] && princesa[0] > principe[1])
      carta = -1;
    else if (princesa[2] < principe[0] && princesa[0] < principe[1]) {
      if (1 > carta && carta != -1)
        carta = 1;
    }
    else if (princesa[1] + 1 > carta && carta != -1)
      carta = princesa[1] + 1; 

    if (princesa[0] > principe[0] && princesa[2] > principe[1])
      carta = -1;
    else if (princesa[0] < principe[0] && princesa[2] < principe[1]) {
      if (1 > carta && carta != -1)
        carta = 1;
    }
    else if (princesa[1] + 1 > carta && carta != -1)
      carta = princesa[1] + 1;

    while (1) {
      if (carta == princesa[0] || carta == princesa[1] || carta == princesa[2] || carta == principe[0] || carta == principe[1])
        carta += 1;
      else
        break;
    }

    if (carta > 52)
      carta = -1;

    printf("%d\n", carta);
  }
  
}