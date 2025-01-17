#include <stdlib.h>
#include <stdio.h>


int read_len() {

    int i; 
    scanf("%d", &i);
    if (i == 0) {
       return 16;
    }
    else if (i == 1) {
       return 64;
    }
    else if (i == 2){
        return 128;
    }
    else {
        exit(1);
    }

}

int read_data() {

    char buf[17];
    char buf2[16];

    printf("Enter a number (0-2): ");
    int len = read_len();
    printf("len: %d\n", len);
    sprintf(buf2, "%c%ds", '%',  len);
    printf("Enter a string: ");
    scanf(buf2, buf);
    return 0; 

}

int main2(){
    int i = read_data();
    return i;
}

int main(int argc, char ** argv){

    int r = read_data();
    return r;
}
