#include <stdio.h>
#include <locale.h>

#define size 41

int main()
{   setlocale(LC_ALL, "Portuguese");
    char str1[size], str2[size], str3[81];
    int i, j;
	
	puts("\n\t\t\tManipulação de string <strlen, strcpy e strcat> - ");
	printf("\n Digite uma string para str1: ");
	scanf(" %[^\n]s",str1);
	printf("\n Digite uma string para str2: ");
	scanf(" %[^\n]s",str2);
    
	//==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    //strlen
    j=0; 
    while(str1[j] != '\0')
    	j++;
    printf("\n\n Função strlen, string %s, size: %d",str1,j);
    //strlen
    j=0;
    while(str2[j] != '\0')
    	j++;
    printf("\n Função strlen(%s), size: %d",str2,j);
    
	//==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-	
	//strcpy str3, str1
	printf("\n\n str3: %s",str3);
	j=0;
    while(str1[j] != '\0')
    {
		str3[j]=str1[j];
		j++;
	}
	str3[j]='\0';
    
    printf("\n Função strcpy(str3, str1 - %s): %s",str1,str3);
    
    //==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    //strcpy str3, str2
    printf("\n\n str3: %s",str3);
	j=0;
    while(str1[j] != '\0')
    {
		str3[j]=str2[j];
		j++;
	}
	
    str3[j]='\0';
    printf("\n Função strcpy(str3, str2 - %s): %s",str2,str3);
    
    //==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
   	//strcat str3, str1
	printf("\n\n str3: %s",str3);
	i=0;
	while(str3[i] != '\0')
		i++;
		
	j=0;
    while(str1[j] != '\0')
    {
		str3[i]=str1[j];
		j++; i++;
	}
	str3[i]='\0';
    
    printf("\n Função strcat(str3, str1 - %s): %s",str1,str3);
   
    return 0;
}
