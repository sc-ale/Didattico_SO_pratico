#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define READ 0
#define WRITE 1


int main(int argc, char* argv[]) {
    //int fd = open("b.txt", O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
    int pipefd[2];
    char *buf = "ciaone"; 
/*
    if (fd < 0) {
        perror("open error");
        exit(EXIT_FAILURE);
    }
    dup2(fd, STDOUT_FILENO); //in questo modo ogni write scrive sul file
*/
    if (pipe(pipefd) == -1){
        perror("error pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pFiglio;
    pFiglio = fork();
    /* E' buona norma chiudere la pipe rispetto al servizio che non stiamo per usare, 
     ovvero, se devo leggere la pipe prima devo chiuderla in scrittura. Vale il vicerversa.
     Inoltre, dopo aver usato la pipe in scrittura (o lettura) si deve chiudere la pipe 
     per lo stesso servizio */
    if (pFiglio == 0) {    /* Child reads from pipe */
        close(pipefd[WRITE]);          /* Close unused write end */
        int i =0;
        /* Il figlio si blocca finché il padre non scrive qualcosa */
        while (read(pipefd[READ], &buf, 1) > 0) {
            /* scrive un carattere alla volta sullo stdout */
            write(STDOUT_FILENO, &buf, 1);
            printf("\nchar num: %d\n", i);
            i++;
        }
        
        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
        exit(EXIT_SUCCESS);

    } else {            /* Parent writes argv[1] to pipe */
        close(pipefd[READ]);          /* Close unused read end */
        write(pipefd[WRITE], argv[1], strlen(argv[1]));
        close(pipefd[WRITE]);          /* Reader will see EOF */
        wait(NULL);                /* Wait for child */
        exit(EXIT_SUCCESS);
    }

    return 0;
}

