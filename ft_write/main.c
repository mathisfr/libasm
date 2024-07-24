#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

extern size_t ft_write(int fd, const void *buf, size_t count);

int main() {
    const char *str = "Hello World!\n";
    char bufferError[256];
    size_t result = ft_write(50, str, strlen(str));
    printf("ft_write result = %zu\n", result);
    strerror_r( errno, bufferError, 256 );
    printf("Error %s\n", bufferError);
    result = write(50, str, strlen(str));
    printf("write result = %zu\n", result);
    strerror_r( errno, bufferError, 256 );
    printf("Error %s\n", bufferError);
    return 0;

}
