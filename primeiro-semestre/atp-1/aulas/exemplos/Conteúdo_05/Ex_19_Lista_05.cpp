#include <stdio.h>
#define max 5
int main()
{
	int i,a[max],b[max],c[max];

	printf("Digite os valores do vetor A.\n");
	for (i=0; i<max; i++)
	{
	
		printf("\nDigite o %do. valor inteiro:\n",i+1);
		scanf("%d",&a[i]);
	}
	
	
	printf("\nDigite os valores do vetor B.\n");
	for (i=0; i<max; i++){
		printf("\nDigite o %do. valor inteiro:\n",i+1);
		scanf("%d",&b[i]);
	}
	
	
	for (i=0; i<max; i++)
	{
		c[i]=a[i]*b[i];
		printf("\n%d x %d = %d\n",a[i],b[i],c[i]);
	}
	//system("pause");	
	
	return 0;
}
