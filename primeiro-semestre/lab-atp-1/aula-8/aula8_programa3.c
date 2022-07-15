#include <stdlib.h>
#include <stdio.h>

//Struct que representa um número complexo
typedef struct
{
   float real;
   float im;
} tipo_complexo;

//Programa principal
int main()
{
   float resultado;
   tipo_complexo z, w;
   tipo_complexo soma, produto;

   //Leitura do primeiro número complexo (z)
   printf("Digite parte real e imaginaria: \n");
   scanf("%f", &z.real);
   scanf("%f", &z.im);
   
   //Leitura do primeiro número complexo (z)
   printf("Digite parte real e imaginaria: \n");
   scanf("%f", &w.real);
   scanf("%f", &w.im);
   
   //Calculo da soma de z = real1 + im1*i com w = real2 + im2*i 
   soma.real = z.real + w.real;
   soma.im = z.im + w.im;
   
   //Calculo do produto de z = real1 + im1*i com w = real2 + im2*i
   //Fazendo a distributiva: (real1*real2 + real1*im2*i + im1*i*real2 - im1*im2)
   //Juntar: parte real com parte real, e parte imaginária (com o i) com parte imaginária
   //parte_real = real1*real2 - im1*im2  e parte_img = (real1*im2 + real2*im1) 
   produto.real = z.real * w.real - z.im * w.im;
   produto.im = z.real * w.im + w.real * z.im;
   
   //Impressao dos resultados
   printf("------------------------\n");
   printf("Soma: %.2f + %.2f i \n", soma.real, soma.im);
   printf("Produto: %.2f + %.2f i \n", produto.real, produto.im);
   
   return 0;          
}
