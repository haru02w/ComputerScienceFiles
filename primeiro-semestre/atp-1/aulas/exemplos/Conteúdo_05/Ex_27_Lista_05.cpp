#include <stdio.h>
#include <locale.h>

#define size 100

int main()
{  
	setlocale(LC_ALL, "Portuguese");

  	char str1[size];
	int tabela_asc[128], qtd_char, j;
  	qtd_char=0; j=0;
  
	printf("\n Digite uma string: ");
	scanf("%[^\n]s",str1);
	
	for (int i=0;i<128;i++)
    	tabela_asc[i]=0;
    	
  	while(str1[j] != '\0')
  	{  
    	qtd_char++;
    	tabela_asc[str1[j]]++;    
    	j++;
	}
	printf("Total de caracteres: %d", qtd_char);

  	printf("\n \t\tTabela de Caracteres ");
  	printf("\n\tCaractere\tCódigo Ascii\tOcorrência\n");
  	for (int i=0; i<128; i++)
  	{	
    	if (tabela_asc[i]>0)
  			printf("\t\t%c\t\t %d\t\t\t\t\t%d\n", i,i,tabela_asc[i]);
	}
    
  	return 0;
}
	
