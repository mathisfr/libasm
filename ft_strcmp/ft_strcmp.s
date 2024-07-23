; https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
; https://courses.cs.washington.edu/courses/cse378/10au/sections/Section1_recap.pdf
; https://www.cs.uaf.edu/2017/fall/cs301/reference/x86_64.html
; nasm -f elf64 "name"s -o "name".o
; clang main.c "name".o
section .text
    global ft_strcmp

ft_strcmp:
    cmp_loop:
        mov al, [rdi]
        mov r10b, [rsi]
        cmp al, r10b
        jne cmp_notequal
        test al, al
        jz cmp_equal
        test r10b, r10b
        jz cmp_notequal
        inc rdi
        inc rsi
        jmp cmp_loop
    cmp_notequal:
        sub al, r10b
        movsx rax, al
        ret
    cmp_equal:
        mov rax, 0
        ret