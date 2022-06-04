#include<stdio.h>

#define n 10


int main()
{
  int pilha[n], op, topo=0;
  
  printf("\n\t - Programa para exemplificar um Tipo abstrato de dados (pilha) estático -");
  do{
    printf("\n\t___________________________________________________________________________");
    printf("\n\t\t\t\t 1. Push");
    printf("\n\t\t\t\t 2. Pop");
    printf("\n\t\t\t\t 3. Print");
    printf("\n\t\t\t\t 4. Sair");
    printf("\n\t___________________________________________________________________________");
    printf("\n\t\t\t\t Escolha uma opção: ");
    scanf("%d",&op);
    if (op<=0 || op>4)
      printf("\n \t\t\t \t Digite uma opção válida!");
    else
    {
      if (op==1)
      {
        if (topo<n)
        {
        
          printf("\n\t\t\t\t Digite um elemento para constar na pilha: ");
          scanf("%d",&pilha[topo]);
          topo++;
        }
        else
          printf("\n\t\t\t\tPilha cheia!");
      }
      else if (op==2)
      {
        if (topo>0)
          topo--;
        else
          printf("\n\t\t\t\tNão existe elemento para realizar POP!");
    
      }
      else if (op==3)
      {
        if (topo>0)
        {
          printf("\n\t\t\t\tElemento na pilha: %d", pilha[topo-1]);
        }
        else
          printf("\n\t\t\t\tPilha vazia!");
      }
    }
  }while(op!=4);
  

//  system("pause");
  return 0;
}



