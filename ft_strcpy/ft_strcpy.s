; https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
; https://courses.cs.washington.edu/courses/cse378/10au/sections/Section1_recap.pdf
; nasm -f elf64 "name"s -o "name".o
; clang main.c "name".o
section .text
    global ft_strcpy
ft_strcpy:
    xor rax, rax
    push rdi
copy_loop:
    mov al, [rsi]
    mov [rdi], al 
    cmp al, 0
    je  copy_exit
    inc rdi
    inc rsi
    jmp copy_loop
copy_exit:
    pop rax
    ret
