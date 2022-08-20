#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//Função para o cálculo da derivada de P(x) avaliada 
//em um valor x qualquer, isto é: P'(x=valor)
//--------------------------
float derivada(float v[], int n, float x)
{
	int i;
	float soma = 0;
	
	for (i=1;i<=n;i++)
	  soma = soma + i*v[i]*pow(x,i-1);
	
	return soma;
}
//--------------------------

//--------------------------
//Programa principal
int main()
{
   //Variáveis
   int i, n = 2; //Grau do polinômio P(x)
   float x, valor_derivada, vec_coef[n];
  
   //Entrada de dados
   printf("Digite os coeficientes do poliomio P(x) de grau %d \n",n);
   for (i=0;i<=n;i++) {
   	  printf("Coeficiente %d: ",i);
   	  scanf("%f",&vec_coef[i]);
   }
   
   printf("Digite o valor de x: ");
   scanf("%f",&x);
   
   //Chamada da função para efetuar os cálculos
   valor_derivada = derivada(vec_coef,n,x);
   
   //Impressão da derivada de P(x) avaliada no valor x dado pelo usuário
   printf("Valor de P'(%.2f): %.2f",x,valor_derivada);
   
   return 0;          
}
