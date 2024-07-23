#include <stdio.h>

extern char* ft_strcpy(char *dest, const char *src);

int main() {
    char source[] = "Hello, World!";
    char dest[50];

    ft_strcpy(dest, source);

    printf("Source: %s\n", source);
    printf("Destination: %s\n", dest);

    return 0;
}
