#include <stdio.h>

int main() {
    const char *brown = "\033[48;5;130m";   // marron chocolat
    const char *beige = "\033[48;5;215m";  // beige très clair
    const char *reset = "\033[0m";

    printf("%s   %s%s   %s\n", brown, reset, beige, reset);
}