#include <stdio.h>
#include <stdlib.h>

extern char *ft_strdup(const char *src);

int main() {
    const char *original = "Hello, world!";
    char *duplicate = ft_strdup(original);

    if (duplicate) {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        free(duplicate); // Libérer la mémoire allouée
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}