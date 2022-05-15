#include <stdio.h> //Biblioteca para uso das funções de entrada/saída

// Programa para calcular a área de um círculo, de raio r
int main() 
{ 
  //Declaracao de constantes e variáveis
  const float pi = 3.141592;
  float raio, area;

  //Rotina principal
  printf("Digite um valor positivo para o raio\n");
  scanf("%f", &raio);
  
  //Cálculo da área a partir do raio (preenchido pelo usuário)
  area = pi * raio * raio;
  
  //Impressão do resultado
  printf("Valor da area: %f", area);
  
  //Finaliza o programa
  return 0;
}

