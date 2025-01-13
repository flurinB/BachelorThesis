#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/ptrace.h>


#define BUFFERSIZE1 68
#define BUFFERSIZE2 64

struct data{ 
    char buffer[BUFFERSIZE1];
};

struct data_manipulatior{ 
    char buffer[BUFFERSIZE2];
    void (*foo_ptr)(); 
};

void foo(){
    printf("YAY! you called foo!\n");
}

void bar(){
    printf("You called bar, but you were supposed to call foo!\n");
}

int main(int argc, char **argv){

    struct data_manipulatior *d1 = (struct data_manipulatior *) malloc(sizeof(struct data_manipulatior));
    d1->foo_ptr = &bar;

    printf("Text Service\n_______________\n");

    printf("Enter your Name: ");
    fgets(d1->buffer, BUFFERSIZE2, stdin);
    printf("Hello: %s", d1->buffer);
    free(d1);

    printf("Enter your Text: ");
    struct data *d2 = (struct data *) malloc(sizeof(struct data));

    printf("\nd1:....%p\n", d1);
    printf("d2:....%p\n", d2);

    fgets(d2->buffer, BUFFERSIZE1+1, stdin);
    d1->foo_ptr();

    free(d2);

    return 0;
}