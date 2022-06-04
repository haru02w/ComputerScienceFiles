#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n1,n2,n3;
    printf("Digite 3 numeros: ");
    scanf("%d %d %d",&n1,&n2,&n3);
    printf("Os numeros digitados em ordem crescente é: \n");
    if(n1 < n2 && n1 < n3){
        if(n2 < n3)
            printf("%d %d %d",n1,n2,n3);
        else
            printf("%d %d %d", n1,n3,n2);
    }
    if(n2 < n1 && n2 < n3){
        if(n1 < n3)
            printf("%d %d %d",n2,n1,n3);
        else
            printf("%d %d %d",n2,n3,n1);
    }
    if(n3 < n1 && n3 < n2){
        if(n2 < n3)
            printf("%d %d %d",n3,n1,n2);
        else
            printf("%d %d %d",n3,n2,n1);
    }
    printf("\n");
    return 0;
}
