#include <stdlib.h>
#include <stdio.h>

//Implementa��o de fun��es
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
	//Vari�veis
	int m, n, resultado;
	
	printf("Digite m e n: \n");
	scanf("%d%d",&m,&n);
	
	//Chama a fun��o combinacao, passando como argumentos (par�metros
	//de entrada), c�pias dos conte�dos salvos nas vari�veis m e n.
	resultado = combinacao(m,n);
	
	printf("Valor da combinacao de %d, tomados %d a %d: %d\n",m,n,n,resultado);
	
    system("pause");
    return 0;          
}
//----------------------------------------
