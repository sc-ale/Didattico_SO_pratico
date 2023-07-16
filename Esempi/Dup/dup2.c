#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
    int fd = open("a.txt", O_RDWR);
    dup2(fd, STDOUT_FILENO);
    /* adesso lo standard output punta al file a.txt, 
    quindi la printf non stampa a schermo ma scrive sul file */
    printf("Hello world");
    return 0;
}

