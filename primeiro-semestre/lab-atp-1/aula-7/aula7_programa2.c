#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    //Variáveis
    char sCPF[12], c;
    int CPF[11], i, soma = 0; 
	int resto, flag = 0;
    
    //Programa principal
    printf("Digite os 11 dígitos do CPF (nao usar pontos ou traços): ");
    scanf("%s", sCPF);
    
    for (i=0; i<11; i++)
        CPF[i] = sCPF[i] - '0'; //Conversão (a partir da tabela ASCII) de string p/ inteiro
    
    //Regra 1: Se os dígitos são iguais, então CPF inválido
    for (i=0; i<10; i++) {
    	if (CPF[i] != CPF[i+1]) 
		   flag = 1;
	}
	
	//Não tem dígitos iguais, logo pode prosseguir
	if (flag == 1)
	{
		//Regra 2: verificando o décimo dígito (dígito 1 após o '-')
		for (i=0; i<9; i++)
		   soma = soma + CPF[i] * (10-i);
		  
		resto = (10 * soma) % 11; //Calcula o resto para o dígito verificador 1

		//Checa se o resto deu 10 (regra específica)
		if (resto == 10)  
		    resto = 0; 
		
		if (resto != CPF[9]){
			printf("CPF inválido");
			return 0;
		}
		
		//Regra 3: verificando o último dígito (dígito 2 após o '-')
		soma = 0;
		for (i=0; i<10; i++)
		   soma = soma + CPF[i] * (11-i);
		
		resto = (10 * soma) % 11; //Calcula o resto para o dígito verificador 2
		
		//Checa se o resto deu 10 (regra específica)
		if (resto == 10)  
		    resto = 0; 

		if (resto != CPF[10]){
			printf("CPF inválido");
			return 0;
		}
		
		//Se chegou até aqui é porque é válido
		printf("CPF Válido!");
	}
	else
	    printf("CPF Inválido - dígitos idênticos");
	  
 	return 0;
}
