#include <stdio.h>
#include <stdlib.h>

int main() 
{	
	//Vari�veis
	float A, B, C;
	
	//Programa principal
	printf("Digite os valores (positivos) de A, B e C: \n");
	scanf("%f %f %f", &A, &B, &C);
	
	//Estrutura Condicional Heterog�nea
	if ( (A < B+C) && (B < A+C) && (C < A+B) )    //Checa se � triangulo
	{
		if ( (A == B) && (B == C) )               //� equil�tero?
	    {
	    	printf("Triangulo equilatero !");
	    }
	    else                                      //� is�sceles?
		{    
			 if ( (A == B) || (A == C) || (B == C) ) 
	         {
	       	    printf("Triangulo isosceles !");
	         }
	    	 else
	    	 {
	    	 	printf("Triangulo escaleno !");
	    	 }
	    }
	}
	else                                          //Sen�o ref. ao primeiro Se: aqui checa-se a condi��o OPOSTA ao primeiro if, ou seja: N�O � tri�ngulo)
	{
		
		printf("Os valores fornecidos nao formam um triangulo");
	}	
}


