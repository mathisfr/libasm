#include <stdio.h>
#include <unistd.h>  // Pour ssize_t
#include <string.h>
#include <errno.h>

extern size_t ft_read(int fd, void *buf, size_t count);

int main() {
    char buffer_fd_read[100];
    char buffer_read[100];
    char bufferError[256];
    int fd = 10000;
    size_t bytes_fd_read, bytes_read_read;

    bytes_fd_read = ft_read(fd, buffer_fd_read, sizeof(buffer_fd_read) - 1);
    if (bytes_fd_read < 0) {
        perror("fd_read");
        return 1;
    }
    buffer_fd_read[bytes_fd_read] = '\0';

    strerror_r( errno, bufferError, 256 );
    printf("Error %s\n", bufferError);

    bytes_read_read = read(fd, buffer_read, sizeof(buffer_read) - 1);
    if (bytes_read_read < 0) {
        perror("read");
        return 1;
    }
    buffer_read[bytes_read_read] = '\0';

    strerror_r( errno, bufferError, 256 );
    printf("Error %s\n", bufferError);

    printf("fd_read result: %s[bytes read: %zd]\n", buffer_fd_read, bytes_fd_read);
    printf("read result: %s[bytes read: %zd]\n", buffer_read, bytes_read_read);
    return 0;
}