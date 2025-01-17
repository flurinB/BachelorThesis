#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int foo(){
    for(int i = 0; i < 10; ++i){
        printf("Test: %d", i);
    }
    return 4;
}

int bar(){
    int x = foo();
    char buf[4];
    int i;
    for(i = x;  i < 16; ++i){
        printf("Test2: %d", i);
    }
    fgets(buf, i, stdin);
}

int main(int argc, char **argv){

    foo();
    bar();

    return 0;

}