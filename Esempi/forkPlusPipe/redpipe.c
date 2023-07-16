/* questo programma esegue due funzioni, l'output della prima funzione sara' l'input della prima */


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
int main(int argc, char *argv[]) {
	int fd[2];
	int status;
	pipe(fd);
	if (fork() == 0) { //crea figlio 
		dup2(fd[1], STDOUT_FILENO); //il file descriptor di STDOUT_FILENO si riferisce a quello della pipe in scrittura,
			/*l'output del primo processo figlio sarà inviato alla pipe invece che all'output standard*/
		close(fd[0]);
		execlp("ls", "ls", NULL); //figlio termina
		exit(0);
	}
	if (fork() == 0) { //crea secondo figlio
		dup2(fd[0], STDIN_FILENO); //il file descriptor di STDIN_FILENO si rifersice a quello della pipe in lettura
			/*l'input del secondo processo figlio verrà prelevato dalla pipe invece che dall'input standard.*/
		close(fd[1]);
		execlp("sort", "sort", "-r", NULL);
		exit(0);
	}
	close(fd[0]);
	close(fd[1]);
	wait(&status); //aspetta i figli
	wait(&status);
}
