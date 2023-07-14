#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	printf("%d\n", getpid());
	int rv = execvp(argv[1], argv+1);
	if (rv < 0)
		perror("prefisso errore exec");
}
