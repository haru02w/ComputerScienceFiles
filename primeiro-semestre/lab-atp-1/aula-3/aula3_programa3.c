#include <stdio.h>
#include <stdlib.h>

int main() 
{	
	//Variáveis
	float A, B, C;
	
	//Programa principal
	printf("Digite os valores (positivos) de A, B e C: \n");
	scanf("%f %f %f", &A, &B, &C);
	
	//Estrutura Condicional Heterogênea
	if ( (A < B+C) && (B < A+C) && (C < A+B) )    //Checa se é triangulo
	{
		if ( (A == B) && (B == C) )               //É equilátero?
	    {
	    	printf("Triangulo equilatero !");
	    }
	    else                                      //É isósceles?
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
	else                                          //Senão ref. ao primeiro Se: aqui checa-se a condição OPOSTA ao primeiro if, ou seja: NÃO é triângulo)
	{
		
		printf("Os valores fornecidos nao formam um triangulo");
	}	
}


