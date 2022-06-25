#include <stdio.h>
#include <locale.h>
#include <stdio.h>
#define m 3

int main()
{
	int A[m][m][m];
  
	for (int i=0; i<m; i++)
	{
  		for (int j=0; j<m; j++)
  		{

    		for (int z=0; z<m; z++)
    		{		
        		A[i][j][z]=i;
    		}
  		}
	}
	for (int i=0; i<m; i++)
	{
  		for (int j=0; j<m; j++)
  		{	

    		for (int z=0; z<m; z++)
   	 		{
      	  		printf("[%d][%d][%d]:%d ", i,j,z,A[i][j][z]);
    		}
      		printf("\n");
  		}

	}
   	return 0;
}
