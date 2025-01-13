#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    char buf[10];
    printf("What is your name? ");
    fgets(buf, 128, stdin);
    printf("Hello, %s\n", buf);
    return EXIT_SUCCESS;
}