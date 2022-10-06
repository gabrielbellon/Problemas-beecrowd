#include <iostream>
#include <stack>

using namespace std;

int main() {
  int qtdVagoes, vagoes[1000], iVagoes;

  while(1) {
    scanf("%d", &qtdVagoes);

    if (qtdVagoes == 0)
      break;

    while(1) {
      for (int i = 0; i < qtdVagoes; i++) {
        scanf("%d", &vagoes[i]);

        if (vagoes[i] == 0)
          break;
      }

      if (vagoes[0] == 0)
        break;

      stack<int> estacao;
      iVagoes = 0;

      /*
      A ideia eh fazer com que os vagoes cheguem na estacao um de
      cada vez e sejam adicionados na pilha. Assim que possivel, ou
      seja, quando o vagao do topo da pilha for igual ao primeiro
      vagao da saida, ele sai para a direcao B.
      */

      for (int i = 0; i < qtdVagoes; i++) {
        estacao.push(i + 1);

        while (estacao.size() > 0 && vagoes[iVagoes] == estacao.top()) {
          estacao.pop();
          iVagoes += 1;
        }
      }

      if (iVagoes == qtdVagoes)
        printf("Yes\n");
      else
        printf("No\n");
    }

    printf("\n");
  }

  return 0;
}