#include<stdio.h>
#include<stdlib.h>
#include<time.h> //biblioteca necess�ria para a fun��o time
#include <locale.h>
#define max 5 
//ap�s validar, substituir por 1000

int main()
{ setlocale(LC_ALL, "Portuguese");
  //Vari�veis para armazenar entrada e valores necess�rios para calcular os resultados
  int v[max], acum=0, npar=0, nimpar=0, soma_par=0, soma_impar=0;
  //Vari�veis para armazenar os resultados
  float media, media_par, media_impar;
  
  srand(time(NULL));
  //La�o para gerar os n�meros aleat�rios
  for(int i=0; i<max; i++)
  { 
    v[i]=rand()%100; //gera valores entre 0 e 100
  }
  
//La�o para apresentar n�meros e acumular os valores necess�rios para calcular os resultados
  for(int i=0; i<max; i++)
  { 
    printf("\nN�mero sorteado (%d): %d", i, v[i]);
    acum+=v[i];
    if (v[i]%2==0)
    { npar++;
      soma_par+=v[i];
    }
    else
    { nimpar++;
      soma_impar+=v[i];
    }
      
  }

  //C�lculos para atender o problema.
  media=(float)acum/max;
  media_par=(float)soma_par/npar;
  media_impar=(float)soma_impar/nimpar;

  printf("\nM�dia dos n�meros: %.5f", media);
  printf("\nM�dia dos n�meros pares: %.5f", media_par);
  printf("\nM�dia dos n�meros �mpares: %.5f", media_impar);
  printf("\nQtd n�meros pares: %d", npar);
  printf("\nQtd n�meros �mpares: %d\n", nimpar);
    
  //system("pause");
  
  return 0;
}





