#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
void access_rights(struct stat file){
    printf("User:\n");
    if(file.st_mode & S_IRUSR){
        printf("Read:Yes\n");
    }
    else{
        printf("Read:No\n");
    }
    if(file.st_mode & S_IWUSR){
        printf("Write:Yes\n");
    }
    else{
        printf("Write:No\n");
    }
    if(file.st_mode & S_IXUSR){
        printf("Execution:Yes\n");
    }
    else{
        printf("Execution:No\n");
    }
    printf("Group:\n");
    if(file.st_mode & S_IRGRP){
        printf("Read:Yes\n");
    }
    else{
        printf("Read:No\n");
    }
    if(file.st_mode & S_IWGRP){
        printf("Write:Yes\n");
    }
    else{
        printf("Write:No\n");
    }
    if(file.st_mode & S_IXGRP){
        printf("Execution:Yes\n");
    }
    else{
        printf("Execution:No\n");
    }
    printf("OTHERS:\n");
        if(file.st_mode & S_IROTH){
            printf("Read:Yes\n");
        }
        else{
            printf("Read:No\n");
        }
        if(file.st_mode &S_IWOTH){
            printf("Write:Yes\n");
        }
        else{
            printf("Write:No\n");
        }
        if(file.st_mode & S_IXOTH){
            printf("Execution:Yes\n");
        }
        else{
            printf("Execution:No\n");
        }
}
void link_file_name(char* file){
    char arr[1024];
    readlink(file,arr,sizeof(arr)-1);
    printf("The symbolic link name of file %s is %s\n", file,arr);
}
void link_file_size(char* file){
    char arr[1024];
    readlink(file,arr,sizeof(arr)-1);
    struct stat x;
    lstat(arr,&x);
    printf("The symbolic link size of file %s is %ld\n",file,x.st_size);
}
int main(int argc, char *argv[]){
    struct stat a;
    char c;
    for(int i=0;i<argc-1;i++){
        if(stat(argv[i],&a)==-1){
            perror(argv[i]);
            continue;
        }
        if(S_ISREG(a.st_mode)){
            struct stat file;
            char link_name[32];
            lstat(argv[i+1],&file);
            struct tm* timer=localtime(&file.st_mtime);
            printf("%s is a regular file\n", argv[i+1]);
            printf("Regular file:\n name(-n)\n size(-d)\n hard link count(-h)\n time of last modification(-m)\n access rights(-a)\n create symbolic link(-l)\n");
            scanf("%c", &c);
            if(c=='-'){
                scanf("%c", &c);
            }
            switch(c){
                case 'n': printf("The name of the file is %s",argv[i+1]); break;
                case 'd': printf("The size of the file is %ld",file.st_size); break;
                case 'h': printf("The hard link count is %ld",file.st_nlink); break;
                case 'm': printf("The time of the last modification is %ld",file.st_mtime);break;
                case 'a': printf("The access rights are:\n");
                          access_rights(file);
                          break;
                case 'l': printf("Input the file name for the symbolic link\n");
                          scanf("%s",link_name);
                          symlink(argv[i],link_name);
                          printf("The symbolic link %s is created",link_name);
                          break;
            }
        }
        else if(S_ISLNK(a.st_mode)){
            printf("%s is a symbolic link file\n",argv[i+1]);
            printf("Symbolic link:\n name(-n)\n delete symbolic link(-l)\n size of symbolic link(-d)\n size of target file(-t)\n access rights(-a)\n");
        }
        else if(S_ISDIR(a.st_mode)){
            printf("%s is a directory\n",argv[i+1]);
            printf("Directory:\n name(-n)\n size(-d)\n access rights(-a)\n total number of file with the .c extension(-c)");
        }
        else{
            printf("File given as argument is not a good input\n");
        }
    }
   return 0;
}