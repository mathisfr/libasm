#include <stdio.h>
#include <string.h>

extern int ft_strcmp(const char *s1, const char *s2);

int main() {
    char *str1 = "Mulhouse";
    char *str2 = "Mulhouse42";
    char *str3 = "Mulhous";
    int isEqual;

    isEqual = strcmp(str1, str1);
    printf("strcmp %s == %s : %d\n", str1, str2, isEqual);
    isEqual = ft_strcmp(str1, str1);
    printf("ft_strcmp %s == %s : %d\n", str1, str2, isEqual);

    isEqual = strcmp(str1, str2);
    printf("strcmp %s == %s : %d\n", str1, str3, isEqual);
    isEqual = ft_strcmp(str1, str2);
    printf("ft_strcmp %s == %s : %d\n", str1, str3, isEqual);

    isEqual = strcmp(str1, str3);
    printf("strcmp %s == %s : %d\n", str1, str3, isEqual);
    isEqual = ft_strcmp(str1, str3);
    printf("ft_strcmp %s == %s : %d\n", str1, str3, isEqual);
    return 0;
}