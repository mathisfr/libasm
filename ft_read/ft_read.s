; https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
; https://courses.cs.washington.edu/courses/cse378/10au/sections/Section1_recap.pdf
; nasm -f elf64 ft_strlen.s -o ft_strlen.o
; clang main.c ft_strlen.o
section .text
    global ft_read
    extern __errno_location

ft_read:
    mov rax, 0
    syscall
    cmp rax, 0
    jl read_error
    ret
read_error:
    neg rax
    push rax
    call __errno_location
    pop qword [rax]
    mov rax, -1
    ret
