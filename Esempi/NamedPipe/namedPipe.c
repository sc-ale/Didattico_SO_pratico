#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUF 1024

int main(int argc, char* argv[]) {
    if(argc!=2) {
        perror("invalid number of arguments");
        return 1;
    }

    if(mkfifo(argv[1], 0666)== -1) {
        perror("error mkfifo");
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        perror("error open");
        return 1;
    }
    
    char buf[MAX_BUF];
    
    while(1) {
        memset(buf, 0, sizeof(buf));
        int rd = read(fd, buf, sizeof(buf));
        
        if(rd==-1){
            perror("error read");
            return 1;
        } else if(rd == 0){
            fd = open(argv[1], O_RDONLY);
            if(fd == -1) {
                perror("error open 2");
                return 1;
            }
        } else {   
            if(strcmp(buf, "FINE\n")==0) {
                remove(argv[1]);
                break;
            }
            printf("%s", buf);
        }
    }
    close(fd);
    return 0;
}