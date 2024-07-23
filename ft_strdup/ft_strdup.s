; https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
; https://courses.cs.washington.edu/courses/cse378/10au/sections/Section1_recap.pdf
; nasm -f elf64 "name"s -o "name".o
; clang main.c "name".o
section .text
    global ft_strdup
    extern malloc
    extern strlen
    extern strcpy

ft_strdup:
    push rdi
    call strlen
    pop rdi
    add rax, 1

    mov rdi, rax
    call malloc
    test rax, rax
    jz dup_end

    mov rsi, rdi
    mov rdi, rax
    call strcpy

dup_end:
    ret