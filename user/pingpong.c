#include "kernel/types.h"
#include "user/user.h"

int main(){
    int p[2];
    pipe(p);
    int pid = fork();
    // sub process
    if(!pid){
        char recieved;
        read(p[0],&recieved,1);
        printf("%d: received ping\n",getpid());
        write(p[1],&recieved,1);
    }
    // parent process
    else{
        char c='c';
        write(p[1],&c,1);
        char par='b';
        read(p[0],&par,1);
        printf("%d: received pong, recieved char = %c\n",getpid(),par);
    }
    exit(0);
}