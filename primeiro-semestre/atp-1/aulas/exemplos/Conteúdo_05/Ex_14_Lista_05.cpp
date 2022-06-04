#include <stdio.h>

//Definir previamente a dimensão do vetor
#define max 5 
int main()
{
  
  int n[max],mn=0;
  for(int =0; i<max; i++)
  {
    printf("\nDigite o %do. valor inteiro:\n",i+1);
    scanf("%f",&n[i]);
  
    if(i==0) //inicializar a variável para o maior valor do vetor
      mn=n[i];
    else
    {  
      if(n[i]>mn)
        mn=n[i];
    } 
  }
  
  printf("\n");
  printf("\nMaior número %.2f:", mn);

  for(int i=0; i<max; i++){
    printf("\n%d / %d = %.2f\n",n[i],mn,(float)n[i]/mn);
  }
  //system("pause");
  return 0;
}


