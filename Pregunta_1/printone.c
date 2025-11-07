#include <stdio.h>
void printone(void);
int main(void) {
    char c = 'A';
    asm volatile(
        "mv t0, %0\n\t"
        "call printone\n\t"
        :
        : "r" (&c)
        : "t0"
    );

    return 0;
}