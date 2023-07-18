#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>

/* Questo programma monitora una directory aspettando la creazione di un file, 
   viene preso il nome (che è un comando con argomenti) e vengono separati in maniera appropriata */

#define BUFFL sizeof(struct inotify_event) + NAME_MAX + 1

int main(int argc, char* argv[]) {

	if(argc != 2) {
		printf("CmdLine error");
		return 0;
	}

	int fd = inotify_init();
	int watchd = inotify_add_watch(fd,argv[1],IN_CREATE);

	struct inotify_event buff[BUFFL];
	read(fd,buff,BUFFL); /* read bloccante */

	/* Separare il comando dagli argomenti  */
	/* Può essere fatta sicuramente meglio */
	char cmd[PATH_MAX];
	char * args[PATH_MAX];
	char filename[PATH_MAX];
	strcpy(filename,buff[0].name);
	char * token = strtok(filename," ");
	strcpy(cmd,token);
	args[0] = token;
	int i = 1;
	while(token != NULL) {
		token = strtok(NULL," ");
		if(token != NULL) {
		   args[i] = token;
		   printf("%s\n",args[i]);
		   i++;
		}
	}
	
	/* Esecuzione e eliminazione file  */
	char filepath[PATH_MAX] = "./exec/";
	strcat(filepath,buff[0].name);
	/* Lo rimuovo prima di eseguire ma se non va bene basta fare la fork con l'esecuzione e poi eliminare dopo */
	remove(filepath);
	execvp(cmd,args);
	close(fd);
}
