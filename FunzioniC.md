# FUNZIONI UTILI

## STRINGHE
- memset  -> riempe una stringa con una costante (utile per inizializzare il buf che si usa in snprintf)
- sprintf, snprintf -> formatta una stringa come vuoi tu (es. sprintf(buf, "%s/%s, path, nameFile) )
- strcpy, strdup    -> copia una stringa in un'altra (MA strdup alloca memoria)
- strtok  -> estrae le diverse parole, separate da delim, in una stringa 


## CONVERSIONI STRINGHE-NUMERI
- strtod -> converte un carattere ASCII in un float 
- atoi   -> converte una stringa in un intero


## MODIFICHE FILE
- rename -> permette di cambiare il nome o la posizione del file
- remove -> elimina un file o una directory
- fputc  -> inserisce un carattere nel file puntato 


## ESERCUZIONE FILE
- execv -> esegue un file o un comando dato (i comandi come ls,rm,... si trovano in /usr/bin/)


## INFORMAZIONI E LETTURA FILE
- open, fopen -> legge (e può) creare un file (open ritorna il file descriptor, fopen ritorna un FILE pointer)
- read  -> legge un file da un file descriptor, inoltre è BLOCCANTE (quindi è anche utile, ad esempio, per aspettare che cambi il file)
- stat  -> ritorna il file status
    - in man 3 stat ci sono i campi di status e in man 7 inode ci sono funzioni utili per controllare il file type e mode
- fseek -> imposta l'indicatore di posizione di un file (la posizione può essere all'inizio, metà o fine del file)
- ftell ->  ritorna il valore corrente dell'indicatore di posizione del file associato a stream (può essere utile per vedere la dimensione di un file)
            (es. FILE* f = fopen(pathfile, "r"); fseek(f, 0, SEEK_END); long size = ftell(f); )


## PATH
- basename, dirname -> ritornano solo il nome del file o il path precedente
- realpath -> ritorna il path assoluto di un file (se l'input è un symbolic link allora torna il path assoluto del file a cui il soft link si riferisce)
- symlink  -> crea un link simbolico 
- link     -> crea un hard link


## DIR E DIR ENTRY
- opendir -> apre una directory (ritorna il puntatore al flusso della directory)
- readdir -> ritorna un puntatore alle entry della directory (es. while( (entry = readdir(dir))!=NULL ) {...}  )
    - la struttura dirent ha diversi attributi molto utili (principalemente d_type)

## CREARE E INFO SU PROCESSI
- fork -> crea un nuovo processo, che diventa figlio del chiamante (nel figlio la fork ritorna 0 mentre nel padre ritorna il pid del figlio)
- pid, ppid -> ritornano il pid del processo chiamante (o del padre con ppid)

## TEMPO 
- timerfd_create, timerfd_settime -> creano e settano un timer che invia segnali attraverso il file descriptor (a differenza di timer_create, timer_settime)
    - es. si crea un timer e lo si setta, si fa la read sul fd del timer in modo che il processo si sblocchi quando cambia qualcosa nel fd del timer, cambia ogni tot tempo (come l'abbiamo settato)
- clock -> ritorna il CPU time usato dal processo fino a quel momento