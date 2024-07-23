#include <stdio.h>
#include <unistd.h>
#include <string.h>

extern size_t ft_write(int fd, const void *buf, size_t count);

int main() {
    const char *str = "Hello World!\n";
    size_t result = ft_write(1, str, strlen(str));
    printf("ft_write result = %zu\n", result);
    result = write(1, str, strlen(str));
    printf("write result = %zu\n", result);
    return 0;
}
