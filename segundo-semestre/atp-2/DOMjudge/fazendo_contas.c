#include <stdio.h>
int main (int argc, char *argv[])
{
    char c;
    int precedencia[3] = {0};
    char pilha[10000] = {0};
    int i=0,j = 0,tracker=0;
    do {
        j++;
        scanf("%c",&c);
        switch (c) {
            case '(':
                precedencia[0] += 1;
                pilha[tracker++] = 1;
                break;
            case '[':
                precedencia[1] += 1;
                pilha[tracker++] = 2;
                break;
            case '{':
                precedencia[2] += 1;
                pilha[tracker++] = 3;
                break;


            case ')':
                precedencia[0] -= 1;
                if(pilha[tracker-1]== 1) pilha[--tracker]= 0;
                break;
            case ']':
                precedencia[1] -= 1;
                if(pilha[tracker-1]== 2) pilha[--tracker]= 0;
                break;
            case '}':
                precedencia[2] -= 1;
                if(pilha[tracker-1]== 3) pilha[--tracker]= 0;
                break;
                
        }
    } while (c != '\n');
    
    if (precedencia[0] == 0 && precedencia[1] == 0 && precedencia[2] == 0){
        while(pilha[i] == 0 && i < j) i++;
        if (i==j){
            printf("S");
            return 0;
        }
    } 
    printf("N");
    return 0;
}
