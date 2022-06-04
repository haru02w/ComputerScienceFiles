#include <stdio.h>
#include <stdlib.h>
#define n 5

int main()
{ //declaração de variáveis
  int diferenca=0, v[n], ind_primeiro, ind_segundo;
  //entrada de dados
  for(int i=0; i<n; i++)
  {
    printf("Digite um valor para a posição %d do vetor:", i);
    scanf("%d", &v[i]);
  }
  //Processamento. Verificação da maior diferença entre dois elementos consecutivos
  for(int i=0; i<n; i++)
  {   
    printf("\n Vetor[%d]:%d", i,v[i]);
    if (i>0) //calcula maior diferença para valores consecutivos, portanto a partir da segunda entrada
    {
      //verifica se o módulo da diferença (valor sem sinal) é maior
	  //módulo da diferença. Função abs está disponível em stdlib.h

      if(abs(v[i]-v[i-1])>diferenca)
      { 
        diferenca=abs(v[i]-v[i-1]); //armazena a diferença
        ind_primeiro=i-1;
        ind_segundo=i;
      }
    }  
  }
  printf("\nMaior diferença: %d", diferenca);
  printf("\nPosicao %d : elemento %d", ind_primeiro, v[ind_primeiro]);
  printf("\nPosicao %d : elemento %d", ind_segundo, v[ind_segundo]);
  //system("PAUSE");
  return 0;
}

