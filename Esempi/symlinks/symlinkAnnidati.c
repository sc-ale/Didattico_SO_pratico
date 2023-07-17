#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <libgen.h>

int checkSysAnnidato(char* path) {
	
	char *tmp = strdup(path);
	char buf[PATH_MAX];
	
	if (readlink(tmp, buf, PATH_MAX) < 0) {
		perror("readlink failed");
		exit(EXIT_FAILURE);
	}
	
	struct stat statbuf;
	char path2[PATH_MAX];

	sprintf(path2, "%s/%s", dirname(tmp), buf);	
	printf("path softlink 2: %s\n", path2);	
	
	if (lstat(path2, &statbuf) == -1) {
		perror("lstat failed");
		exit(EXIT_FAILURE);
	}
	/* ritorna zero se è un link simbolico, 1 altrimenti */
	int ans = (S_ISLNK(statbuf.st_mode)) ? 0 : 1; 
	printf("%jo\n%d\n", statbuf.st_mode, ans);
	return ans;
}

int main(int argc, char* argv[]){
	
	if (argc != 2) {
		perror("invalid number of arguments\n");
		exit(EXIT_FAILURE);
	}
	
	char *path = strdup(argv[1]);
	if (path == NULL) {
		perror("strdup failed\n");
		exit(EXIT_FAILURE);
	}
	
	DIR* dr = opendir(path);
	if (dr == NULL) {
		perror("opendir failed\n");
		exit(EXIT_FAILURE);
	}
	
	struct dirent* entry;
	while((entry = readdir(dr)) != NULL) {
		if (entry->d_type == DT_LNK) {
			/* è un link simbolico, bisogna verificare se è annidato */
			char buf[PATH_MAX];
			sprintf(buf, "%s/%s", path, entry->d_name);
			printf("path softlink 1: %s\n", buf);
			if (checkSysAnnidato(buf)==0) {
				if (remove(buf) < 0) {
					perror("remove failed");
				}
			}
		}
	}
	
	return 0;
}
