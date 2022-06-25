#include <stdio.h>
int main(int argc, char const *argv[])
{
    float a,b,c,media;
    printf("Digite 3 valores: ");
    scanf("%f %f %f",&a,&b,&c);
    media = (a + b + c) / 3;
    if(media > a || media > b || media > c)
        printf("Algum numero digitado é maior que a media dos numeros\n");
    else
        printf("A media não é maior que os numeros digitados\n");
    return 0;
}
