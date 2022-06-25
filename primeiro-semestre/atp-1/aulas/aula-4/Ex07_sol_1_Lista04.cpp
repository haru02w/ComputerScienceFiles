
#include <stdio.h>


int main()
{
	
	int mc, i;
	
	
	printf("\nDigite um multiplicando\n");
	scanf("%d", &mc);
	
	for (i=0; i<=10;i++)
	{
		
		printf("\n\%d x %d = %d", mc, i, mc*i);
			
	}
	//system("PAUSE");
	return 0;
}
