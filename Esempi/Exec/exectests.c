#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
// execl
//	int rv = execl("/bin/ls", "ls", "-l", "/", NULL);
// execv
//	char *myargv[] = {"ls", "-l", "/", NULL};
//	int rv = execv("/bin/ls", myargv);
	int rv = execl("ls", "ls", "-l", "/", NULL);
	if (rv < 0)
		perror("prefisso errore exec");
}
