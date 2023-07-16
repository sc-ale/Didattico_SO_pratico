import os
import sys

if __name__ == "__main__":
    # crea un link simbolico da src a dest
    dest = sys.argv[1]
    #src = sys.argv[2]
    #os.symlink(src, dest)
    os.unlink(dest)

    # stampa il path del file src o di quello a cui punta se è un soft link
    #print(os.path.realpath(src))

