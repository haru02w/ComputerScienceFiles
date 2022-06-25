/*
9.	Escreva um programa para calcular a conta dos clientes de uma lanchonete que oferece três tipos de lanches
(tipo 1, tipo 2 e tipo 3), três tipos de pizzas (tipo 1, tipo 2 e tipo 3) e três tipos de bebidas (tipo 1, tipo 2 e tipo 3). 
A capacidade da lanchonete é de 10 mesas. As opções iniciais são: 1 - Lanches;  2 - Pizzas;  3 - Bebidas;  4 - Mostrar Consumo Mesa; 
 5 - Fechar Caixa;  6 - Abrir Caixa; 7 - Sair.  Para as opções de 1 a 3, o programa deverá exibir um novo menu com as opções: 
 1 - Tipo 1; 2 - Tipo 2; 3 - Tipo 3; 4 - Retornar para o Menu Principal. Os preços executados pelo programa são: 
 Lanches (tipo 1, tipo 2 ou tipo 3), R$ 15,00; pizzas (tipo 1, tipo 2 ou tipo 3), R$ 87,00; Bebidas (tipo 1, tipo 2 ou tipo 3), 
 R$ 8,00.
O programa inicia com o caixa fechado, status igual a 0. As opções de 1 a 5 do Menu Principal podem ser realizadas somente 
após caixa aberto (status igual a 1). Para cada registro de produto, o programa deve solicitar o número da mesa (de 0 a 9) e a 
quantidade consumida, valores maiores que 0. A opção 4 permite exibir o consumo parcial de uma mesa. A opção 5 permite alterar o 
caixa para fechado, status igual a 0, bloqueando as operações (opções de 1 a 5). A opção 5 também lista o consumo de cada mesa 
(de 0 a 9). A opção 6 é responsável por abrir o caixa e inicializar as variáveis/totalizações com 0's, bem como atualizar o status 
do caixa para 1 (aberto). Se o caixa está fechado, o programa poderá realizar novas operações após execução da opção 6. Nesse caso,
 todos os registros são zerados. Se o caixa já está aberto e a opção 6 é escolhida, o programa deve emitir o alerta
  "Caixa já está aberto.". Nesse caso, nenhuma operação é realizada. A opção 7 permite encerrar o programa, desde que o status do 
  caixa seja 0 (fechado). Após o encerramento, o programa deve exibir as totalizações de produtos consumidos e valores 
  correspondentes, organizadas por categoria.

*/

#include <stdio.h>
#include <locale.h> 
	
#define n 10

int main()
{   setlocale(LC_ALL, "Portuguese");
	
	int resp, op, mesa, qtd, status_caixa=0;//define que o caixa está fechado, nenhuma operação é realizada. Variável mesa indica o cliente
	
	int pizza_t1[n]={0}, pizza_t2[n]={0}, pizza_t3[n]={0};
	int lanche_t1[n]={0}, lanche_t2[n]={0}, lanche_t3[n]={0};
	int bebida_t1[n]={0}, bebida_t2[n]={0}, bebida_t3[n]={0};

	int total_pizza_t1=0, total_lanche_t1=0, total_bebida_t1=0; 
	int total_pizza_t2=0, total_lanche_t2=0, total_bebida_t2=0;
	int total_pizza_t3=0, total_lanche_t3=0, total_bebida_t3=0;
	

	printf("\n\t\t\t - Lanchonete ATPI - Controle para %d mesas (clientes)",n);
	

	do{
		do{
			printf("\t\t\n\n--- MENU ---\n");
			printf("\n1. Lanches");
			printf("\n2. Pizzas");
			printf("\n3. Bebidas");	
			printf("\n4. Mostrar Consumo Mesa");
			printf("\n5. Fechar Caixa");
			printf("\n6. Abrir Caixa");
			printf("\n7. Sair  ");
		  	scanf("%d", &resp);	
		  	if (resp<1 || resp>7)
		  		printf ("\n\t\tEntrada inválida!");
		}while(resp<1 || resp>7);
		
		if (resp==7)
		{
		
			if (status_caixa==0)
				printf("\n\t\t Programa encerrado!");
			else
				printf("\n\t\t Caixa aberto: Programa não pode ser encerrado!");
		}
		else if (((resp>=1) && (resp<=3)) && status_caixa==1)
		{	
			do{
					printf("\t\t\n\n--- Escolha o tipo ---\n");
					printf("\n1. Tipo 1");
					printf("\n2. Tipo 2");
					printf("\n3. Tipo 3");
					printf("\n4. Retornar ");
		  			scanf("%d", &op);	
		  			if (op<1 || op>4)
		  				printf ("\n\t\tEntrada inválida!");
			}while(op<1 || op>4);
			
			if (op!=4)
			{
				do{
					printf("\n\t\t Informe o número da mesa para o consumo (cliente): ");
					scanf("%d",&mesa);
		  			if (mesa<0 || mesa>9)
		  				printf ("\n\t\tEntrada inválida - mesa de 0 a %d!",n);
				}while(mesa<0 || mesa>9);
				
				do{
					printf("\n\t\t Quantidade: ");
					scanf("%d",&qtd);
					if (qtd<=0)
		  				printf ("\n\t\tEntrada inválida!");
				}while(qtd<=0);
		  		
				if (resp==1)
				{
					if (op==1)
						lanche_t1[mesa]+=qtd;
					else if (op==2)
						lanche_t2[mesa]+=qtd;
					else if (op==3)
						lanche_t3[mesa]+=qtd;
				}
				else if (resp==2)
				{
					if (op==1)
						pizza_t1[mesa]+=qtd;
					else if (op==2)
						pizza_t2[mesa]+=qtd;
					else if (op==3)
						pizza_t3[mesa]+=qtd;
				}
				else 
				{
					if (op==1)
						bebida_t1[mesa]+=qtd;
					else if (op==2)
						bebida_t2[mesa]+=qtd;
					else if (op==3)
						bebida_t3[mesa]+=qtd;
				}
			}
		}
		else if (resp==4 && status_caixa==1)
		{
			
			printf("\n\t\t Mostrar consumo da mesa (cliente), informe o número: ");
			scanf("%d",&mesa);
			printf("\n\t\t - Mesa: %d", mesa);			
			if (lanche_t1[mesa]!=0)
				printf("\n\t\tLanche(s) - tipo 1: qtd. %d - R$ %.2f.", lanche_t1[mesa], lanche_t1[mesa]*15.0);
			if (lanche_t2[mesa]!=0)
				printf("\n\t\tLanche(s) - tipo 2: qtd. %d - R$ %.2f.", lanche_t2[mesa], lanche_t2[mesa]*15.0);
			if (lanche_t3[mesa]!=0)
				printf("\n\t\tLanche(s) - tipo 3: qtd. %d - R$ %.2f.", lanche_t3[mesa], lanche_t3[mesa]*15.0);
		
			if (pizza_t1[mesa]!=0)
				printf("\n\t\tPizza(s) - tipo 1: qtd. %d - R$ %.2f.", pizza_t1[mesa], pizza_t1[mesa]*87.0);
			if (pizza_t2[mesa]!=0)
				printf("\n\t\tPizza(s) - tipo 2: qtd. %d - R$ %.2f.", pizza_t2[mesa], pizza_t2[mesa]*87.0);
			if (pizza_t3[mesa]!=0)
				printf("\n\t\tPizza(s) - tipo 3: qtd. %d - R$ %.2f.", pizza_t3[mesa], pizza_t3[mesa]*87.0);
							
			if (bebida_t1[mesa]!=0)
				printf("\n\t\tBebida(s) - tipo 1: qtd. %d - R$ %.2f.", bebida_t1[mesa], bebida_t1[mesa]*8.0);
			if	(bebida_t2[mesa]!=0)
				printf("\n\t\tBebida(s) - tipo 2: qtd. %d - R$ %.2f.", bebida_t2[mesa], bebida_t2[mesa]*8.0);
			if	(bebida_t3[mesa]!=0)	
				printf("\n\t\tBebida(s) - tipo 3: qtd. %d - R$ %.2f.", bebida_t3[mesa], bebida_t3[mesa]*8.0);
							
			printf("\n\t\tTotal da mesa (cliente) %d: %.2f", mesa, lanche_t1[mesa]*15.0+lanche_t2[mesa]*15.0+lanche_t3[mesa]*15.0+ pizza_t1[mesa]*87.0+pizza_t2[mesa]*87.0+pizza_t3[mesa]*87.0+bebida_t1[mesa]*8.0+bebida_t2[mesa]*8.0+bebida_t3[mesa]*8.0);
		}
		else if (resp==5 && status_caixa==1)
		{
			printf("\n\t\t - Caixa fechado! -");
			status_caixa=0;
			printf("\n\t\t - Totalização de produtos -");
			for (int i=0;i<n; i++)
			{
				total_pizza_t1+=pizza_t1[i];
				total_lanche_t1+=lanche_t1[i];
				total_bebida_t1+=bebida_t1[i];
		
				total_pizza_t2+=pizza_t2[i];
				total_lanche_t2+=lanche_t2[i];
				total_bebida_t2+=bebida_t2[i];
		
				total_pizza_t3+=pizza_t3[i];
				total_lanche_t3+=lanche_t3[i];
				total_bebida_t3+=bebida_t3[i];
		
				printf("\n\n\t\t - Mesa: %d", i);			
				printf("\n\n\t\tLanche(s) - tipo 1: qtd. %d - R$ %.2f", lanche_t1[i], lanche_t1[i]*15.0);
				printf("\n\t\tLanche(s) - tipo 2: qtd. %d - R$ %.2f", lanche_t2[i], lanche_t2[i]*15.0);
				printf("\n\t\tLanche(s) - tipo 3: qtd. %d - R$ %.2f", lanche_t3[i], lanche_t3[i]*15.0);
				printf("\n\t\tTotal Lanche(s): %d", lanche_t1[i]+lanche_t2[i]+lanche_t3[i]);
		
				printf("\n\n\t\tPizza(s) - tipo 1: qtd. %d - R$ %.2f", pizza_t1[i], pizza_t1[i]*87.0);
				printf("\n\t\tPizza(s) - tipo 2: qtd. %d - R$ %.2f", pizza_t2[i], pizza_t2[i]*87.0);
				printf("\n\t\tPizza(s) - tipo 3: qtd. %d - R$ %.2f", pizza_t3[i], pizza_t3[i]*87.0);
				printf("\n\t\tTotal Pizza(s): %d", pizza_t1[i]+pizza_t2[i]+pizza_t3[i]);
		
				printf("\n\n\t\tBebida(s) - tipo 1: qtd. %d - R$ %.2f", bebida_t1[i], bebida_t1[i]*8.0);
				printf("\n\t\tBebida(s) - tipo 2: qtd. %d - R$ %.2f", bebida_t2[i], bebida_t2[i]*8.0);
				printf("\n\t\tBebida(s) - tipo 3: qtd. %d - R$ %.2f", bebida_t3[i], bebida_t3[i]*8.0);
				printf("\n\t\tTotal Bebida(s): %d", bebida_t1[i]+bebida_t2[i]+bebida_t3[i]);
			}
		}
		else if (resp==6)
		{
			if (status_caixa==0)
			{
			
				status_caixa=1;
		
				total_pizza_t1=0;
				total_lanche_t1=0;
				total_bebida_t1=0;
				
				total_pizza_t2=0;
				total_lanche_t2=0;
				total_bebida_t2=0;
				
				total_pizza_t3=0;
				total_lanche_t3=0;
				total_bebida_t3=0;
							
				
				for (int i=0;i<n; i++)
				{
					pizza_t1[i]=0;
					lanche_t1[i]=0;
					bebida_t1[i]=0;
					
					pizza_t2[i]=0;
					lanche_t2[i]=0;
					bebida_t2[i]=0;
						
					pizza_t3[i]=0;
					lanche_t3[i]=0;
					bebida_t3[i]=0;
				}
				printf ("\n\t\tCaixa aberto!");
			}
			else
				printf ("\n\t\tO caixa já está aberto!");
		}
		else
			printf ("\n\t\t Caixa está fechado, não é possível realizar operações!");
	}while (resp!=7 || status_caixa==1);

	
	printf("\n\n\t______________________________________________________________________________");
	printf("\n\n\t\t\tTotal geral");
	printf("\n\n\t\tLanche(s) - tipo 1: qtd. %d - R$ %.2f", total_lanche_t1, total_lanche_t1*15.0);
	printf("\n\t\tLanche(s) - tipo 2: qtd. %d - R$ %.2f", total_lanche_t2, total_lanche_t2*15.0);
	printf("\n\t\tLanche(s) - tipo 3: qtd. %d - R$ %.2f", total_lanche_t3, total_lanche_t3*15.0);
	printf("\n\t\tTotal Lanche(s): qtd. %d - R$ %.2f", total_lanche_t1+total_lanche_t2+total_lanche_t3, (total_lanche_t1+total_lanche_t2+total_lanche_t3)*15.0);
	
	printf("\n\n\t\tPizza(s) - tipo 1: qtd. %d - R$ %.2f", total_pizza_t1, total_pizza_t1*87.0);
	printf("\n\t\tPizza(s) - tipo 2: qtd. %d - R$ %.2f", total_pizza_t2, total_pizza_t2*87.0);
	printf("\n\t\tPizza(s) - tipo 3: qtd. %d - R$ %.2f", total_pizza_t3, total_pizza_t3*87.0);
	printf("\n\t\tTotal Pizza(s): qtd. %d - R$ %.2f", total_pizza_t1+total_pizza_t2+total_pizza_t3, (total_pizza_t1+total_pizza_t2+total_pizza_t3)*87.0);
	
	printf("\n\n\t\tBebida(s) - tipo 1: qtd. %d - R$ %.2f", total_bebida_t1, total_bebida_t1*8.0);
	printf("\n\t\tBebida(s) - tipo 2: qtd. %d - R$ %.2f", total_bebida_t2, total_bebida_t2*8.0);
	printf("\n\t\tBebida(s) - tipo 3: qtd. %d - R$ %.2f", total_bebida_t3, total_bebida_t3*8.0);
	printf("\n\t\tTotal Bebida(s): qtd. %d - R$ %.2f", total_bebida_t1+total_bebida_t2+total_bebida_t3, (total_bebida_t1+total_bebida_t2+total_bebida_t3)*8.0);

	return 0;
} 
