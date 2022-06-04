#include<stdio.h>
#include<stdlib.h>
#include<time.h> //biblioteca necessária para a função time
#include <locale.h>
#define max 5 
//após validar, substituir por 1000

int main()
{ setlocale(LC_ALL, "Portuguese");
  //Variáveis para armazenar entrada e valores necessários para calcular os resultados
  int v[max], acum=0, npar=0, nimpar=0, soma_par=0, soma_impar=0;
  //Variáveis para armazenar os resultados
  float media, media_par, media_impar;
  
  srand(time(NULL));
  //Laço para gerar os números aleatórios
  for(int i=0; i<max; i++)
  { 
    v[i]=rand()%100; //gera valores entre 0 e 100
  }
  
//Laço para apresentar números e acumular os valores necessários para calcular os resultados
  for(int i=0; i<max; i++)
  { 
    printf("\nNúmero sorteado (%d): %d", i, v[i]);
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

  //Cálculos para atender o problema.
  media=(float)acum/max;
  media_par=(float)soma_par/npar;
  media_impar=(float)soma_impar/nimpar;

  printf("\nMédia dos números: %.5f", media);
  printf("\nMédia dos números pares: %.5f", media_par);
  printf("\nMédia dos números ímpares: %.5f", media_impar);
  printf("\nQtd números pares: %d", npar);
  printf("\nQtd números ímpares: %d\n", nimpar);
    
  //system("pause");
  
  return 0;
}





