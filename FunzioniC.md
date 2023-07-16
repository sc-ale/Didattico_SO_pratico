# FUNZIONI UTILI

## STRINGHE
- memset  -> riempe una stringa con una costante (utile per inizializzare il buf che si usa in snprintf)
- sprintf, snprintf  -> formatta una stringa come vuoi tu (es. sprintf(buf, "%s/%s, path, nameFile) )
- strcpy, strdup    -> copia una stringa in un'altra (MA strdup alloca memoria)
- strtok  -> estrae le diverse parole, separate da delim, in una stringa 
- strlen  -> calcola la lunghezza di una stringa, escludendo il null byte ('\0')
- getopt  -> parsing delle opzioni passate da linea di comando (ritona l'opzione inserita nel terminale, ed anche il suo parametro)


## CONVERSIONI STRINGHE-NUMERI
- strtod -> converte un carattere ASCII in un float 
- atoi   -> converte una stringa in un intero
- atof   -> converte una stringa in un float

## MODIFICHE FILE
- rename -> permette di cambiare il nome o la posizione del file
- remove -> elimina un file o una directory
- fputc  -> inserisce un carattere nel file puntato 
- dup, dup2  -> duplica un file descriptor, per dup 2 il file descriptor
       newfd e' aggiustato in modo che ora si riferisca allo stesso file descriptor di oldfd.

## INOTIFY -  API CONTROLLO DI EVENTI SU UN FILE/DIRECTORY
- inotify_init -> inizializza un'istanza inotify che ritorna il file descriptor di quella istanza
- inotify_add_watch-> serve per aggiungere un file da tenere sotto controllo, con eventuali flag per dire quali eventi ci interessano
- read -> eseguita su un file descriptor di un'istanza inotify blocca il programma fino a che non avviene un evento, restituisce una struttura inotify_event
- inotify_event -> struttura dati per ottenere informazioni sull'evento ottenuto, es. nel campo .name c'è il nome del file creato se si stava aspettando la creazione di un file
- close -> chiude l'istanza inotify e vengono liberati anche tutti i file aggiunti con inotify_add_watch 
- #define BUFFL sizeof(struct inotify_event) + NAME_MAX + 1 -> define che come dice il manuale è la dimensione adatta del buffer per contenere almeno un evento

## ESESECUZIONE FILE
- execv -> esegue un file o un comando dato (i comandi come ls,rm,... si trovano in /usr/bin/)
- execvp -> 


## INFORMAZIONI E LETTURA FILE
- open, fopen -> legge (e può) creare un file (open ritorna il file descriptor, fopen ritorna un FILE pointer)
- read  -> legge un file da un file descriptor, inoltre è BLOCCANTE (quindi è anche utile, ad esempio, per aspettare che cambi il file)
- stat  -> ritorna il file status
    - in man 3 stat ci sono i campi di status e in man 7 inode ci sono funzioni utili per controllare il file type e mode
- fseek -> imposta l'indicatore di posizione di un file (la posizione può essere all'inizio, metà o fine del file)
- ftell ->  ritorna il valore corrente dell'indicatore di posizione del file associato a stream (può essere utile per vedere la dimensione di un file)
            (es. FILE* f = fopen(pathfile, "r"); fseek(f, 0, SEEK_END); long size = ftell(f); )
- fgets  -> legge  il file, la lettura si ferma alla fine del file (EOF) o ad una nuova linea ("\n")
- getline  -> legge l'intera dallo stream, salvandola su buffer


## PATH E SOFT LINK
- basename, dirname -> ritornano solo il nome del file o il path precedente
- realpath -> ritorna il path assoluto di un file (se l'input è un symbolic link allora torna il path assoluto del file a cui il soft link si riferisce)
- symlink  -> crea un link simbolico 
- link     -> crea un hard link
- readlink -> restituisce il nome del file puntato dal link simbolico preso in input (non risolve tutta la catena)
- unlink   -> elimina il link dato in input ed eventualmente il file puntato

## DIR E DIR ENTRY
- opendir -> apre una directory (ritorna il puntatore al flusso della directory)
- readdir -> ritorna un puntatore alle entry della directory (es. while( (entry = readdir(dir))!=NULL ) {...}  )
    - la struttura dirent ha diversi attributi molto utili (principalemente d_type)
- getcwd  -> ritorna la directory corrente 
- chdir,fchdir -> servono per cambiare la directory corrente, la seconda prende un file descriptor in input 


## CREARE E INFO SU PROCESSI
- fork -> crea un nuovo processo, che diventa figlio del chiamante (nel figlio la fork ritorna 0 mentre nel padre ritorna il pid del figlio)
- pid, ppid -> ritornano il pid del processo chiamante (o del padre con ppid)


## TEMPO 
- timerfd_create, timerfd_settime -> creano e settano un timer che invia segnali attraverso il file descriptor (a differenza di timer_create, timer_settime)
    - es. si crea un timer e lo si setta, si fa la read sul fd del timer in modo che il processo si sblocchi quando cambia qualcosa nel fd del timer, cambia ogni tot tempo (come l'abbiamo settato)
- clock -> ritorna il CPU time usato dal processo fino a quel momento


## SINCRONIZZAZIONE TRA PROCESSI
- wait  -> aspetta che il primo figlio muoia, lo stato e' memorizzato nel parametro passato alla funzione


## GESTIONE PIPE
- pipe  -> crea una pipe (unidirezionale), il file descriptor passato come parametro e' un array dove l'elemento 0 e' read mentre l'elemento 1 e' WRITE 
- mkfifo  -> crea una named pipe (bidirezionale), il file speciale FIFO e' salvato nel filesystem e ogni processo puo' accedervi


## MACRO E LIBRERIE
stdin, stdout, stderr  -> (input, outour, errore) standard I/O streams, sono del tipo FILE* 
STDOUT_FILENO, STDIN_FILENO
