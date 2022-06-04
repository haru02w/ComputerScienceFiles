#include <stdio.h>  

#define n 10
int main()
{   
  	int cont=0, ultimo=0, primeiro=0, op, fifo[n];

  	do{
      
       printf ("\n\t\t\t ----- Programa FIFO -----");
       
	   do{
       		printf ("\n\t 1. Consultar primeiro da fila");
       		printf ("\n\t 2. Incluir elemento na fila");
       		printf ("\n\t 3. Atender primeiro da fila");
       		printf ("\n\t 4. Sair\n");
       		scanf  ("\t%d",&op);
        }while ( op < 1 || op>4);
     	  
  	   	if (op == 1)
      	{
        	if ( cont == 0)
            	printf ("\n\t\t\t -- Fila Vazia! --");
       		else 
            	printf ("\n Primeiro elemento: %d",fifo[primeiro]);
       	}
       	else if( op == 2)
       	{
           if (cont == n)
              printf ("\n\t\t\t -- Fila Cheia! --");
           else
           {
              printf ("\n Codigo:");
              scanf("%d",&fifo[ultimo]);
              ultimo++;
              cont++;
           }
  
       }
       else if (op ==3)
       {
           if(cont==0)
              printf ("\n\t\t\t -- Fila Vazia! --");
           else
           {
              primeiro++;
              cont--;
           }
       }
       printf("\n");
      // system ("pause"); 
       
   }while (op !=4);
   //system ("pause");
   return 0;
}

