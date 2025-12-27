#include <stdio.h>
#include <locale.h>  // Ajouter cette ligne

int main() {
    setlocale(LC_ALL, "");  // Activer UTF-8
    
    const char* reset = "\033[0m";
    const char* fond;
    const char* texte;
    
    fond = "\033[48;5;130m";
    texte = "\u2655";  // ♕ Reine blanche
    printf("%s%s%s\n", fond, texte, reset);

    fond = "\033[48;5;215m";
    texte = "\u2655";
    printf("%s%s%s\n", fond, texte, reset);

    fond = "\033[48;5;130m";
    texte = "\u265B";  // ♛ Reine noire
    printf("%s%s%s\n", fond, texte, reset);

    fond = "\033[48;5;215m";
    texte = "\u265B";
    printf("%s%s%s\n", fond, texte, reset);

    return 0;
}