#include <stdio.h>


int fatorial (int num)
{
	
    int fat=1, i;
    
    for (i=1; i<=num; i++)
	   fat = fat*i;
    
        
    return fat;
    
}


int main()
{
       int num, fat;
       
       puts("Digite um numero:");
       scanf("%d", &num);
       
       fat = fatorial(num);
       printf("O fatorial e: %d \n", fat);
       
       //system("Pause");
       return 0;
}
