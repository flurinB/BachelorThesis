#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **argv){

    for (int i = 0; i < 10; i++) {
        printf("Hello World!\n");
    }
    printf("Enter your name:\n");
    char name[16];
    scanf("%s", name);
    printf("Hello %s!\n", name);
    return 0;
}