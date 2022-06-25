#include <stdio.h>
#define m 4
int main()
{
	int A[m][m][m][m];
  
	for (int i=0; i<m; i++)
	{	
  		for (int j=0; j<m; j++)
  		{

    		for (int z=0; z<m; z++)
    		{
      			for (int n=0; n<m; n++)
      			{
        			A[i][j][z][n]=n;
      			}
    		}
  		}
	}
	for (int i=0; i<m; i++)
	{	
  		for (int j=0; j<m; j++)
  		{

		    for (int z=0; z<m; z++)
    		{
      			for (int n=0; n<m; n++)
      			{
        			printf("[%d][%d][%d][%d]: %d ", i,j,z,n, A[i][j][z][n]);
	      		}
        		printf("\n");
    		}
    	}
	}
  
  	return 0;
}
