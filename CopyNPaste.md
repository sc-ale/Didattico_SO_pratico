## ERROR HANDLER
```C
void error_handler(char* buf) {
    perror("%s", buf);
    exit(EXIT_FAILURE);
}
```

## ITERARE SU DIRECTORY
```C
DIR* dr = opendir(path);
if (dr == NULL) {
    perror("opendir");
    exit(EXIT_FAILURE);
}
struct dirent* entry;
while((entry = readdir(dr)) != NULL) {
    printf("name: %s\n", entry->d_name);
    char path[PATH_MAX];
    sprintf(buf, "%s/%s", dr, entry->d_name);
    if (entry->d_type == TIPO ) {
        ...
    }
}
```
## ITERARE SU UN SOTTOALBERO GENERATO DA UNA DIRECTORY
- https://stackoverflow.com/questions/1271064/how-do-i-loop-through-all-files-in-a-folder-using-c
```C
int read_directories(const char* path) {
    DIR* directory = NULL;
    if ((directory = opendir(path)) == NULL) {
        fprintf(stderr, "Can't open %s\n", path);
        return EXIT_FAILURE;
    }

    struct dirent* entry = NULL;
    while ((entry = readdir(directory)) != NULL) {
        char full_name[256] = { 0 };
        snprintf(full_name, 100, "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            printf("'%s' is a directory\n", full_name);
            // Recurse unless the directory is the current or parent directory.
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                return read_directories(full_name);
            }
        } else {
            printf("'%s' is a file\n", full_name);
        }
    }
```
## INCLUDE UTILI
```C
#include <stdio.h> //printf, sprintf, getline 
#include <string.h> //strdup, memset
#include <stdlib.h> //exit
#include <unistd.h> //readlink, pipe, dup2, getopt
#include <libgen.h> //basename
#include <limits.h>
#include <time.h> //time
#include <sys/types.h> //opendir
#include <sys/stat.h> //stat, lstat
#include <sys/wait.h>
#include <fcntl.h> //open
#include <dirent.h> //readdir
```

## GETOPT
```C
int flags, opt, argPassed;
flags = 0;
/* 
- al posto di nt ci vanno i parametri passati, se questi
  hanno un argomento inserire : subito dopo la lettera
- optarg è una macro che contiene l'argomento passato 
  rispetto al parametro */
while ((opt = getopt(argc, argv, "n:t:")) != -1) {
    switch (opt) {
    case 'n':
        flags = 1;
        break;
    case 't':
        argPassed = atoi(optarg);
        break;
    default: 
        exit(EXIT_FAILURE);
    }
}
```

