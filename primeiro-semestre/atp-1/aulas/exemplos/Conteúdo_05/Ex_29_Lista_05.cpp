#include <stdio.h>
#include <locale.h>
#include <string.h>
#define max 10
#define size 61
#define N 5

int main()
{   setlocale(LC_ALL, "Portuguese");
    char str1[N][size], str2[N][size], str3[max][size];
	
	for (int i=0;i<N; i++)
	{
		printf("\n Digite o %do. nome para str1: ",i+1);
		scanf(" %[^\n]s",str1[i]);
		printf("\n Digite o %do. nome para str2: ",i+1);
		scanf(" %[^\n]s",str2[i]);
	}
	printf("\n Nomes em str1: ");
	for (int i=0;i<N; i++)
		printf("\n%s ",str1[i]);
		
	printf("\n\n Nomes em str2: ");
	for (int i=0;i<N; i++)
		printf("\n%s ",str2[i]);
  
    for (int i=0;i<N; i++)
    {
       strcpy(str3[i],str1[i]);
       strcpy(str3[i+N],str2[i]);
    }
    printf("\n\n Nomes em str3: ");
	for (int i=0;i<max; i++)
       printf("\n%s",str3[i]);
	
    return 0;
}
