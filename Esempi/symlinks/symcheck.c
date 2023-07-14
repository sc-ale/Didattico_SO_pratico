#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

/* Funzione che elimina un link simbolico se questo punta ad un altro link simbolico */

int deleteSYMLINKS(char symlink[],int first_call = 1) {
	char buffer[PATH_MAX];
	if(readlink(symlink,buffer,PATH_MAX) == -1) { /* Se readlink ritorna -1 allora il file in input è non è un link simbolico */ 
		printf("- %s è un file \n",symlink);
		return 0;
	}

	if(first_call) { 			      /* Serve per fermarsi solo al primo link di una possibile catena */
		if(deleteSYMLINKS(buffer,0)) { 	      /* Se la chiamata ricorsiva restituisce 1 allora il link simbolico punta ad un altro link simbolico, quindi tocca eliminarlo */
			printf("- %s è un link simbolico allora elimino %s \n",buffer,symlink);
	   		unlink(symlink);
		}
	}
	return 1;
}

