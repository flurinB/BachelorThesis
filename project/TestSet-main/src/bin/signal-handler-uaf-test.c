#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int* global_ptr = NULL;

void signal_handler(int signum) {
    if (global_ptr) {
        printf("Signal handler: %d\n", *global_ptr);
    }
}

int main() {
    signal(SIGALRM, signal_handler);

    global_ptr = (int*)malloc(sizeof(int));
    *global_ptr = 42;

    alarm(1);
    sleep(2);

    free(global_ptr);

    // Potential use after free
    alarm(1);
    sleep(2);

    return 0;
}
