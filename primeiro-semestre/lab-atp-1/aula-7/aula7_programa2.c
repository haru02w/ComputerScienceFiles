#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    //Vari�veis
    char sCPF[12], c;
    int CPF[11], i, soma = 0; 
	int resto, flag = 0;
    
    //Programa principal
    printf("Digite os 11 d�gitos do CPF (nao usar pontos ou tra�os): ");
    scanf("%s", sCPF);
    
    for (i=0; i<11; i++)
        CPF[i] = sCPF[i] - '0'; //Convers�o (a partir da tabela ASCII) de string p/ inteiro
    
    //Regra 1: Se os d�gitos s�o iguais, ent�o CPF inv�lido
    for (i=0; i<10; i++) {
    	if (CPF[i] != CPF[i+1]) 
		   flag = 1;
	}
	
	//N�o tem d�gitos iguais, logo pode prosseguir
	if (flag == 1)
	{
		//Regra 2: verificando o d�cimo d�gito (d�gito 1 ap�s o '-')
		for (i=0; i<9; i++)
		   soma = soma + CPF[i] * (10-i);
		  
		resto = (10 * soma) % 11; //Calcula o resto para o d�gito verificador 1

		//Checa se o resto deu 10 (regra espec�fica)
		if (resto == 10)  
		    resto = 0; 
		
		if (resto != CPF[9]){
			printf("CPF inv�lido");
			return 0;
		}
		
		//Regra 3: verificando o �ltimo d�gito (d�gito 2 ap�s o '-')
		soma = 0;
		for (i=0; i<10; i++)
		   soma = soma + CPF[i] * (11-i);
		
		resto = (10 * soma) % 11; //Calcula o resto para o d�gito verificador 2
		
		//Checa se o resto deu 10 (regra espec�fica)
		if (resto == 10)  
		    resto = 0; 

		if (resto != CPF[10]){
			printf("CPF inv�lido");
			return 0;
		}
		
		//Se chegou at� aqui � porque � v�lido
		printf("CPF V�lido!");
	}
	else
	    printf("CPF Inv�lido - d�gitos id�nticos");
	  
 	return 0;
}
