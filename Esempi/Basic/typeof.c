#include <stdio.h>

#define SWAP(X, Y) do { \
        typeof(Y) tmp = (X); \
        (X) = (Y); \
        (Y) = tmp; \
} while (0)

int main() {
        int a = 2, b = 3;
        char *s = "due", *t = "tre";
        SWAP(a,b);
        SWAP(s,t);
        printf("%d %d\n", a, b);
        printf("%s %s\n", s, t);
}

