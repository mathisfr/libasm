; https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
; https://courses.cs.washington.edu/courses/cse378/10au/sections/Section1_recap.pdf
; nasm -f elf64 ft_strlen.s -o ft_strlen.o
; clang main.c ft_strlen.o
section .text
    global ft_strlen

ft_strlen:
    xor rcx, rcx
    count_len:
        cmp byte [rdi+rcx], 0 
        je count_len_exit
        inc rcx
        jmp count_len
    count_len_exit:
        mov rax, rcx
        ret

