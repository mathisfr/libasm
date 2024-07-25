; https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
; https://courses.cs.washington.edu/courses/cse378/10au/sections/Section1_recap.pdf
; nasm -g -F dwarf -f elf64 ft_write.s -o ft_write.o
; clang main.c ft_write.o
section .text
    global ft_write
    extern __errno_location

ft_write:
    mov rax, 1
    syscall
    cmp rax, 0
    jl write_error
    ret
write_error:
    neg rax
    push rax
    call __errno_location wrt ..plt
    pop qword [rax]
    mov rax, -1
    ret