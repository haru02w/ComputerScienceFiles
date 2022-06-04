#include <stdio.h>
int main (int argc, char *argv[])
{
  char palavra[40];
  int tamanho = 0,aux = 1,i = 0;

  printf("Digite uma palavra\n");
  scanf("%s",palavra);
  while (palavra[tamanho] != '\0')
    tamanho++;
  tamanho--;
  while(palavra[tamanho] != '\0' && aux) {
    if(palavra[i] != palavra[tamanho])
      aux = 0;
    tamanho--;
    i++;
  }
  if(aux)
    printf("A palavra é um palindromo\n");
  else
    printf("A palavra não é um palindromo\n");
  return 0;
}
