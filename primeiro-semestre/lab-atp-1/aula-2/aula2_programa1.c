#include <stdio.h> //Biblioteca para uso das fun��es de entrada/sa�da

// Programa para calcular a �rea de um c�rculo, de raio r
int main() 
{ 
  //Declaracao de constantes e vari�veis
  const float pi = 3.141592;
  float raio, area;

  //Rotina principal
  printf("Digite um valor positivo para o raio\n");
  scanf("%f", &raio);
  
  //C�lculo da �rea a partir do raio (preenchido pelo usu�rio)
  area = pi * raio * raio;
  
  //Impress�o do resultado
  printf("Valor da area: %f", area);
  
  //Finaliza o programa
  return 0;
}

