
/* salva l'output della funzione echo su un file passato come parametro */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
int main(int argc, char *argv[]) {
	int fdout;
	int status;
	switch (fork()) { //il padre fa morire i figli per eseguire funzioni 
		case 0:
			fdout = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
			dup2(fdout, STDOUT_FILENO); // l'output e' direzionato anche sul file passato come parametro
			close(fdout);
			execlp("echo", "echo", "ciao", NULL); //se la funzione termina correttamente il figlio muore
			exit(0);
		default:
			wait(&status); //il padre aspetta che il figlio termini
			break;
		case -1:
			exit(1);
	}
	sleep(10);
}
