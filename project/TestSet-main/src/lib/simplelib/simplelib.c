#include "simplelib.h"

#include <stdio.h>
#include <stdlib.h>

void say_hello(const char *name) {
    printf("Hello I am , %s!\n", name);

    //This is a buffer overflow vulnerability
    char buf[10];
    printf("What is your name? ");
    fgets(buf, 128, stdin);
    printf("Hello, %s\n", buf);
}