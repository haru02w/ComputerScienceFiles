#include <stdio.h>

int main()
{
	
	int  j;
	
	//printf("\nDigite um multiplicando\n");
	//scanf("%d", &mc);
	
	for (int i=0; i<=10;i++)
	{
		printf("\n\n\t - Tabuada do %d", i);
		
		for (j=0; j<=10;j++)
		{
		
			printf("\n\%d x %d = %d", i, j, i*j);
		}
		
	}
	//system("PAUSE");
	return 0;
}
