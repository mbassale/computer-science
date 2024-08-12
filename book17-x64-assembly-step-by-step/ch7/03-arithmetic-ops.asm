; Ex03 Arithmetic Ops

section .data

section .bss

section .text
  global _start 

_start:
  mov rbp, rsp ; save stack pointer
  nop

  ; convert to negative
ex0:
  mov eax, 42
  neg eax
  add eax, 42
  nop

  ; incorrect sign extension
ex1:
  mov ax, -42
  mov ebx, eax
  nop

  ; correct sign extension
ex2:
  xor rax, rax
  mov ax, -42
  movsx rbx, ax
  nop

  ; multiplication eax * ebx
ex3:
  mov eax, 447
  mov ebx, 1739
  mul ebx
  nop

  ; multiplication with overflow
ex4:
  mov eax, 0FFFFFFFFh
  mov ebx, 03B72h
  mul ebx
  nop

  ; unsigned division
ex5:
  xor rdx, rdx  ; clear rdx
  mov rax, 250  ; dividend is rdx:rax
  mov rbx, 5    ; divisor is rbx
  div rbx       ; unsigned division of rdx:rax / rbx
  nop

  ; unsigned division with remainder
ex6:
  xor rdx, rdx  ; clear rdx
  mov rax, 247  ; divident is rdx:rax
  mov rbx, 17   ; divisor is rbx
  div rbx       ; rdx:rax / rbx
                ; rdx remainder, rax result
  nop

exit:
  nop
  mov rax, 60   ; exit syscall
  mov rdi, 0
  syscall

