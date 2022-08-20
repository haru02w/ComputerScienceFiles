#include <stdlib.h>
#include <stdio.h>

//Implementação de funções
//----------------------------------------
int fatorial(int n)
{
	int i, fat = 1;
	
	for (i=1;i<=n;i++)
	  fat = fat * i;
	
	return fat;
}

int combinacao(int m, int n)
{
	int resultado; 
	
	resultado = fatorial(m) / (fatorial(m-n)*fatorial(n));
	
	return resultado;	
}
//----------------------------------------


//----------------------------------------
//Programa principal
int main()
{          
	//Variáveis
	int m, n, resultado;
	
	printf("Digite m e n: \n");
	scanf("%d%d",&m,&n);
	
	//Chama a função combinacao, passando como argumentos (parâmetros
	//de entrada), cópias dos conteúdos salvos nas variáveis m e n.
	resultado = combinacao(m,n);
	
	printf("Valor da combinacao de %d, tomados %d a %d: %d\n",m,n,n,resultado);
	
    system("pause");
    return 0;          
}
//----------------------------------------
