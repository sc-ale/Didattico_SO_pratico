#include <stdio.h>
struct coso {
	enum {persona, automobile} tipo;
	union {
		struct {
			char *nome;
			char *cognome;
		} upersona;
		struct {
			char *marca;
			char *modello;
		} wautomobile;
	};
};

int main(int argc, char *argv[]) {
	printf("%zd \n",sizeof(struct coso));
}
