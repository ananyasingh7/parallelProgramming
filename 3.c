#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    pid_t n = fork();

    if (n==0){
        printf("Child: [%d]\n", getpid());
    }else{
        printf("Parent: [%d]\n", getpid());
    }

    return 0;
}

