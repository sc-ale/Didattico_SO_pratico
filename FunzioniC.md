# FUNZIONI UTILI

## STRINGHE
- __memset__  -> riempe una stringa con una costante (utile per inizializzare il buf che si usa in snprintf)
- __sprintf, snprintf__  -> formatta una stringa come vuoi tu (es. sprintf(buf, "%s/%s, path, nameFile) )
- __strcpy, strdup__    -> copia una stringa in un'altra (MA strdup alloca memoria)
- __strtok__  -> estrae le diverse parole, separate da delim, in una stringa 
- __strlen__  -> calcola la lunghezza di una stringa, escludendo il null byte ('\0')
- __strspn, strcspn__  -> ritornano la lunghezza di una stringa prefissa 
- __getopt__  -> parsing delle opzioni passate da linea di comando (ritona l'opzione inserita nel terminale, ed anche il suo parametro)


## CONVERSIONI STRINGHE-NUMERI
- __strtod__ -> converte un carattere ASCII in un float 
- __atoi__   -> converte una stringa in un intero
- __atof__   -> converte una stringa in un float

## MODIFICHE FILE
- __rename__ -> permette di cambiare il nome o la posizione del file
- __remove__ -> elimina un file o una directory
- __fputc__  -> inserisce un carattere nel file puntato 
- __dup, dup2__  -> duplica un file descriptor, per dup 2 il file descriptor
       newfd e' aggiustato in modo che ora si riferisca allo stesso file descriptor di oldfd.

## INOTIFY -  API CONTROLLO DI EVENTI SU UN FILE/DIRECTORY
- __inotify_init__ -> inizializza un'istanza inotify che ritorna il file descriptor di quella istanza
- __inotify_add_watch__  -> serve per aggiungere un file da tenere sotto controllo, con eventuali flag per dire quali eventi ci interessano
- __read__ -> eseguita su un file descriptor di un'istanza inotify blocca il programma fino a che non avviene un evento, restituisce una struttura inotify_event
- __inotify_event__ -> struttura dati per ottenere informazioni sull'evento ottenuto, es. nel campo .name c'è il nome del file creato se si stava aspettando la creazione di un file
- __close__ -> chiude l'istanza inotify e vengono liberati anche tutti i file aggiunti con inotify_add_watch 
- #define BUFFL sizeof(struct inotify_event) + NAME_MAX + 1 -> define che come dice il manuale è la dimensione adatta del buffer per contenere almeno un evento

## ESESECUZIONE FILE
- __exec__
    - __execv__ -> esegue un file o un comando dato (i comandi come ls,rm,... si trovano in /usr/bin/)
    - __execvp__ -> esegue un file o un comando dato, simulando il comportamento di una shell 


## INFORMAZIONI E LETTURA FILE
- __open, fopen__ -> legge (e può) creare un file (open ritorna il file descriptor, fopen ritorna un FILE pointer)
- __read__  -> legge un file da un file descriptor, inoltre è BLOCCANTE (quindi è anche utile, ad esempio, per aspettare che cambi il file)
- __stat__  -> ritorna il file status
    - in man 3 stat ci sono i campi di status e in man 7 inode ci sono funzioni utili per controllare il file type e mode
- __fseek__ -> imposta l'indicatore di posizione di un file (la posizione può essere all'inizio, metà o fine del file)
- __ftell__ ->  ritorna il valore corrente dell'indicatore di posizione del file associato a stream (può essere utile per vedere la dimensione di un file)
            (es. FILE* f = fopen(pathfile, "r"); fseek(f, 0, SEEK_END); long size = ftell(f); )
- __fgets__  -> legge  il file, la lettura si ferma alla fine del file (EOF) o ad una nuova linea ("\n")
- __getline__  -> legge l'intera dallo stream, salvandola su buffer


## PATH E SOFT LINK
- __basename, dirname__ -> ritornano solo il nome del file o il path precedente
- __realpath__ -> ritorna il path assoluto di un file (se l'input è un symbolic link allora torna il path assoluto del file a cui il soft link si riferisce)
- __symlink__  -> crea un link simbolico 
- __link__     -> crea un hard link
- __readlink__ -> restituisce il nome del file puntato dal link simbolico preso in input (non risolve tutta la catena)
- __unlink__   -> elimina il link dato in input ed eventualmente il file puntato

## DIR E DIR ENTRY
- __opendir__ -> apre una directory (ritorna il puntatore al flusso della directory)
- __closedir__ -> chiude una directory
- __readdir__ -> ritorna un puntatore alle entry della directory (es. while( (entry = readdir(dir))!=NULL ) {...}  )
    - la struttura dirent ha diversi attributi molto utili (principalemente d_type)
- __getcwd__  -> ritorna la directory corrente 
- __chdir,fchdir__ -> servono per cambiare la directory corrente, la seconda prende un file descriptor in input 


## CREARE E INFO SU PROCESSI
- __fork__ -> crea un nuovo processo, che diventa figlio del chiamante (nel figlio la fork ritorna 0 mentre nel padre ritorna il pid del figlio)
- __pid, ppid__ -> ritornano il pid del processo chiamante (o del padre con ppid)


## TEMPO 
- __timerfd_create, timerfd_settime__ -> creano e settano un timer che invia segnali attraverso il file descriptor (a differenza di timer_create, timer_settime)
    - es. si crea un timer e lo si setta, si fa la read sul fd del timer in modo che il processo si sblocchi quando cambia qualcosa nel fd del timer, cambia ogni tot tempo (come l'abbiamo settato)
- __clock__ -> ritorna il CPU time usato dal processo fino a quel momento


## SINCRONIZZAZIONE TRA PROCESSI
- __wait__  -> aspetta che il primo figlio muoia, lo stato e' memorizzato nel parametro passato alla funzione
- __sleep__ -> mette in pausa un processo per un numero specificato di secondi


## GESTIONE PIPE
- __pipe__  -> crea una pipe (unidirezionale), il file descriptor passato come parametro e' un array dove l'elemento 0 e' read mentre l'elemento 1 e' WRITE 
- __mkfifo__  -> crea una named pipe (bidirezionale), il file speciale FIFO e' salvato nel filesystem e ogni processo puo' accedervi


## MACRO E LIBRERIE
- __stdin, stdout, stderr__  -> (input, outour, errore) standard I/O streams, sono del tipo FILE* 
- __STDOUT_FILENO, STDIN_FILENO__  -> stadard I/O file descriptor, sono int
