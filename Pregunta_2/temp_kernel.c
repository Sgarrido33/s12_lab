#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

// 0 =alfabeto, 1 =numeros
static int print_mode=0; 
static char c='a';
static int n=0;

void timer_handler(int signal_num) {
    if (signal_num == SIGALRM) {
        if (print_mode == 0) {
            printf("\n -INTERRUPCION (2 seg)\n");
            print_mode = 1;
            n = 0;
            alarm(2); 
        } else {
            printf("\n -FIN INTERRUPCION (5 seg)\n");
            print_mode = 0;
            c = 'a'; 
            alarm(5); 
        }
    }
}

int main() {
    // Manejador para señal de alarma
    signal(SIGALRM,timer_handler);

    // Primera alarma (5 segundos)
    printf("Iniciando modo alfabeto por 5 segundos\n");
    alarm(5);

    // Bucle principal
    while (1){
        if (print_mode == 0) {
            printf("%c ", c++);
            if (c>'z') c ='a';
        } else {
            printf("%d ", n++);
            if (n>9) n =0;
        }
        
        usleep(100000); 
    }
    return 0;
}