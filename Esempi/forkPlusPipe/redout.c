/*
Il programma apre un file in modalità scrittura e lo utilizza come output per la stringa "hola". 

Durante l'esecuzione del programma, si possono osservare le stampe sullo stream di errori, mentre l'output effettivo della stringa "hola" verrà scritto nel file specificato.

*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	printf("getpid %d\n",getpid());
	int fdout = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	sleep(10); 
	fprintf(stderr, "1\n");
	dup2(fdout, STDOUT_FILENO);
	sleep(5); 
	fprintf(stderr, "2\n");
	close(fdout);
	sleep(5); 
	fprintf(stderr, "3\n");
	printf("hola\n");
	sleep(5); 
	fprintf(stderr, "4\n");
}
