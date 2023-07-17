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

