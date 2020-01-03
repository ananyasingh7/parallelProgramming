#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int a,z;
    switch(fork()){
        case -1: exit(1);
        case 0: a = 'a'; z='z'; break;
        default: a='A'; z='Z'; break;
    }

    srand(getpid());
    for(int c = a; c <= z; c++){
        fprintf(stderr, "%c", c);
        sleep(1  + (rand() % 3));
    }

    return 0;
}