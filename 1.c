#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int execCommand(){
    unsigned pid;
    int status;

    if ( (pid = fork()) == 0){
        execl("/bin/ls", "ls", "-al", NULL);
        exit(1);
    }

    while (wait(&status) != pid)
        ;

    return 0;

}

int main(){
    execCommand();
    return 0;
}