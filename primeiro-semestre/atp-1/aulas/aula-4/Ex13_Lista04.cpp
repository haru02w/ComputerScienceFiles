#include <stdio.h>
#include <stdlib.h>

int main()
{
	float an=1.5, fe=1.1;
	int anos=0;
	
	while (an>fe)
	{
		an+=0.02;
		fe+=0.03;
		anos++;
	}
	printf("\nTotal de anos: %d\n",anos);
	
	//system("PAUSE");
	return 0;
}
