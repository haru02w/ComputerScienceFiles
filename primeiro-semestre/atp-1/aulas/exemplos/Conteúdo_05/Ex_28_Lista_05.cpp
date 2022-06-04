#include <stdio.h>
#include <locale.h>

#define size 61

int main()
{   setlocale(LC_ALL, "Portuguese");
    char str1[size];
    int i, j=0, resp=1;
	
	printf("\n Digite uma string: ");
	scanf("%[^\n]s",str1);
		
	while(str1[j] != '\0')
	   j++;		
		
   i=0; 
   printf("\nTamanho da palavra digitada: %d",j);
   j--; //string inicia em zero, logo j deve ser decrementado.   
   while(str1[i] != '\0' && resp==1)
   {
       if(str1[i] != str1[j])
          resp=0;
       i++;
       j--;
    }
    if (resp==1)
    	printf("\nA palavra %s é um palíndromo!", str1);
    else
    	printf("\nA palavra %s não é um palíndromo!", str1);
    
    return 0;
}
	
