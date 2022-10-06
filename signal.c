#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

bool terminar = false;

void hola(int signalNumb){
    printf("Recibi la senal %d:", signalNumb);
}

void hola2(int signalNumb){
    printf("Recibi la senal %d:", signalNumb);
    terminar = true;
}


int main(){
    signal(12, hola2);
    signal(2, hola);
    while(!terminar){
        printf("trabajando\n");
        sleep(1);
    }
    printf("terminando\n");
    return 0;
}


