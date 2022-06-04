#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n1,n2,n3,n4,n5;
    printf("Digite 5 numeros: ");
    scanf("%d %d %d %d %d",&n1,&n2,&n3,&n4,&n5);
    if(n1 < n2 && n1 < n3 && n1 < n4 && n1 < n5)
        printf("O menor numero é %d\n",n1);
    else if(n2 < n1 && n2 < n3 && n2 < n4 && n2 < n5)
        printf("O menor numero é %d\n",n2);
    else if(n3 < n1 && n3 < n2 && n3 < n4 && n3 < n5)
        printf("O menor numero é %d\n",n3);
    else if(n4 < n2 && n4 < n3 && n4 < n4 && n4 < n5)
        printf("O menor numero é %d\n",n4);
    else if(n5 < n1 && n5 < n2 && n5 < n3 && n5 < n4)
        printf("O menor numero é %d\n",n5);

    if(n1 > n2 && n1 > n3 && n1 > n4 && n1 > n5)
        printf("O maior numero é %d\n",n1);
    else if(n2 > n1 && n2 > n3 && n2 > n4 && n2 > n5)
        printf("O maior numero é %d\n",n2);
    else if(n3 > n1 && n3 > n2 && n3 > n4 && n3 > n5)
        printf("O maior numero é %d\n",n3);
    else if(n4 > n2 && n4 > n3 && n4 > n4 && n4 > n5)
        printf("O maior numero é %d\n",n4);
    else if(n5 > n1 && n5 > n2 && n5 > n3 && n5 > n4)
        printf("O maior numero é %d\n",n5);
    return 0;
}
