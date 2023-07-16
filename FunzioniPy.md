# FUNZIONI UTILI


## DIRECTORY ENTRY
- os.listdir -> ritorna la lista di file nella dir passata
- os.walk    -> percorrre tutto l'albero di file dalla dir passata


## PATH
- os.path.join   -> concatena la seconda alla prima inserendo "/" se necessario
- os.path.isdir, os.path.isfile     -> controlla che il path passato sia una dir o un file
- os.path.dirname, os.path.basename -> ritornano il path di un pathname o solo il nome finale
- os.path.exists -> testa se un path esiste
- os.path.islink -> testa se il path è un link simbolico
- os.getcwd      -> ritorna il pathname della dir corrente
- os.path.startswith


## LINK SIMBOLICI
- os.symlink  -> crea un link simbolico (da src a dest)
- os.readlink -> ritorna il path del file a cui il link simbolico punta (guarda solo il file successivo, in caso di soft link annidati non risolve la catena)
- os.path.realpath -> ritorna il cammino assoluto del file dato (se viene passato un link simbolico, anche annidato, ritorna il path del file finale)
- os.unlink   -> elimina il link simbolico dato (se viene passato un file allora si comporta come os.remove)


## MODIFICHE FILE E DIR
- os.mkdir -> crea una directory
- os.remove, os.rmdir -> rimuove un file o una directory


## INFORMAZIONI FILE E DIR
- os.stat   -> ritorna lo status del file passato nel path, lo status ha diversi campi come st_mode, st_size, st_uid, st_atime, ...
- os.path.getmtime -> ritorna il tempo dell'ultima modifica al file (si trova in os.stat)
- file.open -> apre un file e si specifica con che flag per
- file.read -> permette di leggere un file (es. per testare se un file e' ELF: f.read(4) == "\x7fELF")
- file.write, file.writelines -> permette di scrivere una stringa su un file (con una lista di stringhe conviene usare writelines per inserire più stringhe in una sola volta)
- os.access -> ritorna vero se il path ha il permesso dato (con os.F_OK testa l'esistenza, X_OK se puo' essere eseguito, os.W_OK se puo' essere letto)


## STRINGHE E FORMATTED PRINT
- stringa.isnumeric -> ritorna vero se la stringa è composta da numeri
- stringa.split     -> ritorna la lista delle sottostringhe di stringa che sono separate da sep
- .format -> print("ciao {name}, la tua età è: {num}".format(name=var1, num=var2)), per indicare quanti numeri dopo la virgola si vogliono, esempio 2, si fa con {num:.2f}


## LISTE
- list.append -> aggiunge un elemento in coda alla lista
- list.sort   -> ordina la lista (e' possibile ordinare la lista secondo una nostra funzione con key=myFunc, inoltre con reverse=False si puo' invertire l'ordine)