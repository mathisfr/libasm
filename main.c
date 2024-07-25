// https://adonis0147.github.io/post/hello_x86_64_assembly/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern size_t ft_strlen(const char *str);
extern int ft_strcmp(const char *s1, const char *s2);
extern char* ft_strcpy(char *dest, const char *src);
extern char *ft_strdup(const char *src);

int main(int argc, char *argv[]){
    if (argc != 3){
        printf("Usage: \n");
        printf("\t./libasmtest [fd] [str] \n");
        printf("\t replace [fd] by fd used for ft_write and ft_read.\n");
        printf("\t replace [str] by string you want to test.\n");
        return 1;
    }

    int fd = atoi(argv[1]);
    if (fd < 0 || fd > 10000){
        printf("[fd] need to be between 0 and 10000.\n");
        return 1;
    }

    char *strArgv = argv[2];

    printf("== LIBASM ==\n");

    printf("\n[[ ft_write ]]\n");
    {
        const char *str = strArgv;
        char bufferError[256];
        int result = ft_write(fd, str, strlen(str));
        if (result == -1){
            strerror_r( errno, bufferError, 256 );
            printf("Error %s\n", bufferError);
        }else{
            printf("\nft_write result = %u\n", result);
        }
    
        result = write(fd, str, strlen(str));
        if (result == -1){
            strerror_r( errno, bufferError, 256 );
            printf("Error %s\n", bufferError);
        }else{
            printf("\nwrite result = %u\n", result);
        }
    }

    printf("\n[[ ft_read ]]\n");
    {
        const int max_buffer_read = 100;
        const int max_buffer_error = 256;
        char buffer_fd_read[max_buffer_read];
        char buffer_read[max_buffer_read];
        char buffer_error[max_buffer_error];
        int bytes_fd_read, bytes_read;

        bytes_fd_read = ft_read(fd, buffer_fd_read, sizeof(buffer_fd_read) - 1);
        if (bytes_fd_read == -1){
            strerror_r(errno, buffer_error, max_buffer_error);
            printf("Error %s\n", buffer_error);
        }else{
            buffer_fd_read[bytes_fd_read] = '\0';
            printf("fd_read result: %s[bytes read: %d]\n", buffer_fd_read, bytes_fd_read);
        }

        bytes_read = read(fd, buffer_read, sizeof(buffer_read) - 1);
        if (bytes_read == -1){
            strerror_r(errno, buffer_error, max_buffer_error);
            printf("Error %s\n", buffer_error);
        }else{
            buffer_read[bytes_read] = '\0';
            printf("read result: %s[bytes read: %d]\n", buffer_read, bytes_read);
        }
    }

    printf("\n[[ ft_strlen ]]\n");
    {
        const char *str = strArgv;
        size_t length = ft_strlen(str);
        printf("ft_strlen length of '%s' is %zu\n", str, length);
        length = ft_strlen(str);
        printf("strlen length of '%s' is %zu\n", str, length);
    }

    printf("\n[[ ft_strcmp ]]\n");
    {
        char *str1 = "Mulhouse";
        char *str2 = "Mulhouse42";
        char *str3 = "Mulhous";
        int isEqual;

        isEqual = strcmp(str1, str1);
        printf("strcmp %s == %s : %d\n", str1, str1, isEqual);
        isEqual = ft_strcmp(str1, str1);
        printf("ft_strcmp %s == %s : %d\n", str1, str1, isEqual);

        isEqual = strcmp(str1, str2);
        printf("strcmp %s == %s : %d\n", str1, str2, isEqual);
        isEqual = ft_strcmp(str1, str2);
        printf("ft_strcmp %s == %s : %d\n", str1, str2, isEqual);

        isEqual = strcmp(str1, str3);
        printf("strcmp %s == %s : %d\n", str1, str3, isEqual);
        isEqual = ft_strcmp(str1, str3);
        printf("ft_strcmp %s == %s : %d\n", str1, str3, isEqual);
    }

    printf("\n[[ ft_strcpy ]]\n");
    {
        char *source = strArgv;
        char dest1[50];
        char dest2[50];

        ft_strcpy(dest1, source);
        printf("ft_strcpy source: %s\n", source);
        printf("ft_strcpy destination: %s\n", dest1);

        strcpy(dest2, source);
        printf("strcpy source: %s\n", source);
        printf("strcpy destination: %s\n", dest2);
    }

    printf("\n[[ ft_strdup ]]\n");
    {
        const char *original = strArgv;

        char *duplicate = ft_strdup(original);
        if (duplicate) {
            printf("ft_strdup original: %s\n", original);
            printf("ft_strdup duplicate: %s\n", duplicate);
            free(duplicate);
            duplicate = 0;
        } else {
            printf("ft_strdup memory allocation failed.\n");
        }

        duplicate = strdup(original);
        if (duplicate) {
            printf("strdup original: %s\n", original);
            printf("strdup duplicate: %s\n", duplicate);
            free(duplicate);
            duplicate = 0;
        } else {
            printf("strdup memory allocation failed.\n");
        }
    }
    return 0;
}