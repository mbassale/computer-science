;0-hello.asm

%define newline 0xA

section .data
  msg db "hello, world!", newline, 0
section .bss
section .text
  global main
main:
  
  ; write string to stdout
  mov rax, 1    ; 1 = write
  mov rdi, 1    ; 1 = stdout file#
  mov rsi, msg  ; ptr to message
  mov rdx, 14   ; strlen
  syscall       ; linux syscall

  ; terminate the process
  mov rax, 60   ; exit process syscall
  mov rdi, 0    ; process exit code
  syscall
