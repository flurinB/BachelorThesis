#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

int foo(){
    char buffer[16];
    printf("Enter your name:\n");
    scanf("%s", buffer);
    printf("Hello %s!\n", buffer);

    return 0;

}

int loop() {
    for (int i = 0; i < 1000; i++) {
        printf("Hello World!\n");
    }
    return 0;
}

int main(int argc, char **argv){

    int code = loop();
    if (code == 0) {
        code = foo();
    }
    return code;

}