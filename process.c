#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
int main(int args, char *argv[]){
    if(args<1){
        exit(0);
    }
    int k=1;
    if(strchr(argv[k],'.c')==0){
            printf("DO something");
            k++;
    }
    for(int i=0;i<args;i++){
        int pid=fork();
        if(pid==0){
            printf("DA ");
            exit(1);
        }
        else{
            printf("NU ");
        }
    }
    return 0;
}