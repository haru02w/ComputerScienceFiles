#include <stdio.h>
#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif
int main(int argc, char const *argv[])
{
    while(1){
        printf("Eu vou estudar para a prova.\n");
        printf("Aperte Ctrl+c para parar. \n");
        sleep(1);
        printf("\x1b[1A");
    }
    return 0;
}
