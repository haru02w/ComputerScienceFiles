#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n1,n2;
    printf("Digite dois numeros: ");
    scanf("%d %d",&n1,&n2);
    if(n1 == n2)
        printf("Os numeros são iguais\n");
    else
        printf("Os numeros são diferentes\n");

    return 0;
}
