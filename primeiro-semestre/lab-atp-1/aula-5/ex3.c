#include <stdio.h>
#include <string.h> 
#include <ctype.h>
//fflush(stdin);
//setbuff(stdin,NULL);
int main(int argc, char const *argv[])
{
    char frase1[101], frase2[101],c;
    int count = 0;
    
    printf("Digite a primeira frase: ");
    gets(frase1); //obsoleto
    printf("Digite a segunda frase: ");
    gets(frase2); //obsoleto
    
    printf("O tamanho da primeira frase é: %d\n",strlen(frase1));
    printf("O tamanho da segunda frase é: %d\n",strlen(frase2));

    strcat(frase1,frase2);
    puts(frase1);
    
    for (int i = 0; i < strlen(frase1); i++)
    {
        c = frase1[i];
        c = tolower(c);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;

    }
    printf("A quantidade de vogais é: %d\n",count);
    
    return 0;
}
