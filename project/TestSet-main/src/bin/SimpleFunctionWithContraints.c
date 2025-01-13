#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int func(int a){
    if (a == 5){
        return 6;
    }
    if (a == 8){
        return 9;
    }
    return 0;

}

int main(int argc, char **argv){

    int x;
    scanf("%d", &x);
    if (x != 5 && x != 8){
        exit(1);
    }
    int y = func(x);
    printf("%d", y);

    return 0;

}