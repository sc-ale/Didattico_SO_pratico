
/* piccola shell fai da te, il programma esegue la stringa passata come input */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
	char *buf = NULL;
	size_t len = 0;
	for (;;) {
		getline(&buf, &len, stdin); // esegue comandi in un file passati come ./a.out < file
		size_t cmdlen = strlen(buf) - 1;
		buf[cmdlen]=0; // la stringa termina con il carattere nullo /0
		char *myargv[] = {buf, 0}; //the vector end with null
		int status;
		switch (fork()) {
			case 0:
				//execve(buf, myargv,NULL);
				execvp(buf, myargv);
				exit(0);
			default:
				wait(&status);
				break;
			case -1:
				exit(1);
		}
	}
}
