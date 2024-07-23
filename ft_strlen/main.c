#include <stdio.h>

extern size_t ft_strlen(const char *str);

int main() {
    const char *str = "Hello, World! test";
    size_t length = ft_strlen(str);
    printf("Length of '%s' is %zu\n", str, length);
    size_t length2 = ft_strlen(str);
    printf("Length of '%s' is %zu\n", str, length2);
    return 0;
}
