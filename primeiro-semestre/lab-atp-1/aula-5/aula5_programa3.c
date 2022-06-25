#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() 
{	
	//Variáveis
	char string1[100], string2[100], string3[200];
	int i, contadora;
	char auxiliar;
	
	//Programa principal
	printf("Digite a string 1: ");
	gets(string1);
	fflush(stdin);
	
    printf("Digite a string 2: ");
	gets(string2);
	fflush(stdin); 
	
	//Item a
	printf("Quantidade de letras da string 1: %d\n", strlen(string1));
	printf("Quantidade de letras da string 2: %d\n", strlen(string2));
	
	//Item b
	strcat(string1,string2);
	strcpy(string3,string1);
	puts(string3);
	
	//Item c
	contadora = 0;
	for (i=0; i < strlen(string3); i++)
	{
		auxiliar = string3[i];		
		auxiliar = tolower(auxiliar);
		
		//if ( strcmp(auxiliar,'a')==0 || strcmp(auxiliar,'e')==0 || strcmp(auxiliar,'i')==0 || strcmp(auxiliar,'o')==0 || strcmp(auxiliar,'u')==0 )
		if ( auxiliar == 'a' || auxiliar == 'e' || auxiliar == 'i' || auxiliar == 'o' || auxiliar == 'u' )
		   contadora = contadora + 1;
		
	}
	
	printf("contagem: %d", contadora);
	return 0;
}
