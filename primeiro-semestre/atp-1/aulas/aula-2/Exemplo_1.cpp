#include <stdio.h>

int main()
{ float teste;
 
  printf(" --- TIPO ---|--- BYTES ---\n");
  printf(" char .............: %lu bytes\n", sizeof(char));
  printf(" unsigned char.....: %lu bytes\n", sizeof(unsigned char));
  printf(" int...............: %lu bytes\n", sizeof(int));
  printf(" unsigned int......: %lu bytes\n", sizeof( unsigned int));
  printf(" long int..........: %lu bytes\n", sizeof(long int));
  printf(" unsigned long int.: %lu bytes\n", sizeof(unsigned long int));
  
  printf(" long float .......: %lu bytes\n", sizeof( float));
  printf(" double............: %lu bytes\n", sizeof(double));
  printf(" long double.......: %lu bytes\n\n", sizeof(long double));
  printf("\nO tamanho de teste............: %lu \n\n",sizeof teste);
  
  return 0;
}
