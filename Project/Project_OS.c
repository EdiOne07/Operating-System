#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    struct stat a;
    for(int i=0;i<argc;i++){
        if(stat(argv[i],&a)==-1){
            perror(argv[i]);
            continue;
        }
        if(S_ISREG(a.st_mode)){
            printf("%s is a regular file\n", argv[i]);
        }
        else if(S_ISLNK(a.st_mode)){
            printf("%s is a symbolic link file\n",argv[i]);
        }
        else if(S_ISDIR(a.st_mode)){
            printf("%s is a directory\n",argv[i]);
        }
        else{
            printf("File given as argument is not a good input\n");
        }
    }
   return 0;
}