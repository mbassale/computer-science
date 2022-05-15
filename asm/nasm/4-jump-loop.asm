
extern printf

section .data
    number      dq  1000000000
    fmt         db  "The sum from 0 to %ld if %ld", 10, 0

section .bss

section .text
global main
main:
    push rbp
    mov rbp, rsp

    mov rbx, 0      ; counter    
    mov rax, 0      ; sum in rax
    
jloop:
    add rax, rbx
    inc rbx
    cmp rbx, [number]   ; rbx < number ?
    jle jloop
    
    mov rdi, fmt
    mov rsi, [number]
    mov rdx, rax        ; sum value
    mov rax, 0          ; no mmx
    call printf
    
exit:
    mov rsp, rbp
    pop rbp
    ret