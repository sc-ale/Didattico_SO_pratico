# FUNZIONI UTILI


## DIRECTORY ENTRY
- __os.listdir__ -> ritorna la lista di file nella dir passata
- __os.walk__    -> percorrre tutto l'albero di file dalla dir passata


## PATH
- __os.path.join__   -> concatena la seconda alla prima inserendo "/" se necessario
- __os.path.isdir, os.path.isfile__     -> controlla che il path passato sia una dir o un file
- __os.path.dirname, os.path.basename__ -> ritornano il path di un pathname o solo il nome finale
- __os.path.exists__ -> testa se un path esiste
- __os.path.islink__ -> testa se il path è un link simbolico
- __os.getcwd__      -> ritorna il pathname della dir corrente
- __s.path.startswith__


## LINK SIMBOLICI
- __os.symlink__  -> crea un link simbolico (da src a dest)
- __os.readlink__ -> ritorna il path del file a cui il link simbolico punta (guarda solo il file successivo, in caso di soft link annidati non risolve la catena)
- __os.path.realpath__ -> ritorna il cammino assoluto del file dato (se viene passato un link simbolico, anche annidato, ritorna il path del file finale)
- __os.unlink__   -> elimina il link simbolico dato (se viene passato un file allora si comporta come os.remove)


## MODIFICHE FILE E DIR
- __os.mkdir__ -> crea una directory
- __os.remove, os.rmdir__ -> rimuove un file o una directory


## INFORMAZIONI FILE E DIR
- __os.stat__   -> ritorna lo status del file passato nel path, lo status ha diversi campi come st_mode, st_size, st_uid, st_atime, ...
- __os.path.getmtime__ -> ritorna il tempo dell'ultima modifica al file (si trova in os.stat)
- __file.open__ -> apre un file e si specifica con che flag per
- __file.read__ -> permette di leggere un file (es. per testare se un file e' ELF: f.read(4) == "\x7fELF")
- __file.write, file.writelines__ -> permette di scrivere una stringa su un file (con una lista di stringhe conviene usare writelines per inserire più stringhe in una sola volta)
- __os.access__ -> ritorna vero se il path ha il permesso dato (con os.F_OK testa l'esistenza, X_OK se puo' essere eseguito, os.W_OK se puo' essere letto)


## STRINGHE E FORMATTED PRINT
- __stringa.isnumeric__ -> ritorna vero se la stringa è composta da numeri
- __stringa.split__    -> ritorna la lista delle sottostringhe di stringa che sono separate da sep
- __.format__ -> print("ciao {name}, la tua età è: {num}".format(name=var1, num=var2)), per indicare quanti numeri dopo la virgola si vogliono, esempio 2, si fa con {num:.2f}


## LISTE
- __list.append__ -> aggiunge un elemento in coda alla lista
- __list.sort__   -> ordina la lista (e' possibile ordinare la lista secondo una nostra funzione con key=myFunc, inoltre con reverse=False si puo' invertire l'ordine)
