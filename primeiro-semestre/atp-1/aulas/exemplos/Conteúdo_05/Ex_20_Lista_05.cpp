#include <stdio.h>

#define max 10

int main()
{
  int i, vetor_A[max], vetor_B[max], vetor_C[max], vetor_D[max], soma_A=0, soma_B=0;

  for(i=0; i<max; i++)
  {
    printf("Digite um valor para a posição %d, vetor A: \n", i);
    scanf("%d", &vetor_A[i]);
    
    soma_A=soma_A+vetor_A[i];
    
    printf("Digite um valor para a posição %d, vetor B: \n", i);
    scanf("%d", &vetor_B[i]);
    
    soma_B=soma_B+vetor_B[i];
    
    vetor_C[i]=vetor_A[i]+vetor_B[i];
    vetor_D[i]=vetor_B[i]-vetor_A[i];
  }
  
  printf("Soma dos valores do vetor A: %d\n", soma_A);
  printf("Soma dos valores do vetor B: %d\n", soma_B);
  
  printf("------------Vetor C------------\n");
  
  for(i=0; i<max; i++)
    printf("Vetor C[%d] -> soma dos vetores A e B: %d\n",i,vetor_C[i]);  
  
  printf("------------Vetor D------------\n");
  for(i=0; i<max; i++)
    printf("Vetor D[%d] -> subtracao dos vetores B e A: %d\n",i,vetor_D[i]);
  
  //system("PAUSE");
  return 0;
}

