/*semplice sincronizzazione tra padre e figlio, il padre aspetta che il figlio termini prima di continuare l'esecuzione*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
	int status;
	switch (fork()) {
		case 0:
			printf("figlio %d %d\n", getpid(), getppid());
			sleep(20);
			int *i = NULL;
			*i = 1000;
			_exit(42);
		default:
			printf("genitore %d\n", getpid());
			wait(&status);			
			printf("%x\n", status);
			if (WIFEXITED(status))	//aspetta che il figlio termini corretamente
				printf("exit %d\n", WEXITSTATUS(status));
			else
				printf("signal %d\n", WTERMSIG(status));
		case -1:
			exit(1);
	}
}
