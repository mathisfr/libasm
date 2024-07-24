; https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
; https://courses.cs.washington.edu/courses/cse378/10au/sections/Section1_recap.pdf
; nasm -f elf64 ../ft_strcpy/ft_strcpy.s -o ../ft_strcpy/ft_strcpy.o
; gcc -g -no-pie -fsanitize=address main.c ft_strdup.o ../ft_strcpy/ft_strcpy.o ../ft_strlen/ft_strlen.o
section .text
    global ft_strdup
    extern malloc
    extern ft_strlen
    extern ft_strcpy
    extern __errno_location

ft_strdup:
    call ft_strlen
    add rax, 1
    push rdi
    mov rdi, rax
    call malloc
    test rax, rax
    jz dup_error
    pop rsi
    mov rdi, rax
    call ft_strcpy
    ret
dup_error:
    neg rax
    push rax
    call __errno_location
    pop qword [rax]
    mov rax, 0
    ret