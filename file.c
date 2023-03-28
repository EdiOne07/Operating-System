#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc, char* argv[]){
    if(argc<2){
        printf("Invalid input\n");
        exit(1);
    }
    struct stat data;
    long info=lstat(argv[1], &data);
    printf("%ld",data.st_size);
    
    return 0;
}