; Chapter 7: Sandbox for testing instructions

section .data

section .bss

section .text
  global main

main:
  mov rbp, rsp
  nop


  nop

  mov rax, 60   ; exit syscall
  mov rdi, 0
  syscall

section .note.GNU-stack noalloc noexec nowrite progbits
