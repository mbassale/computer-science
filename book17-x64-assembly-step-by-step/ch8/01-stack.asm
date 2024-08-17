; 01-stack.asm Stack Exercises

section .data
  val0  DQ  0FFFFFFFFFFFFFFFFh

section .bss

section .text
  global _start

_start:
  mov rbp, rsp
  nop

  mov rax, 1
  mov rbx, 2
  mov rcx, 3
  mov rdx, val0 ; mov address of val0 into rcx

  ; push values
  pushfq      ; push RFlags register
  push rax    ; push dq rax
  push rbx    ; push dq rbx
  push rcx    ; push dq rcx
  push QWORD [rdx]  ; push dq val0

  ; clear registers
  xor rax, rax
  xor rbx, rbx
  xor rcx, rcx

  ; pop values
  pop QWORD [rdx] ; pop dq into val0
  pop rcx         ; pop rcx
  pop rbx         ; pop rbx
  pop rax         ; pop rax
  popfq           ; pop RFlags register

exit:
  nop
  mov rax, 60   ; exit syscall
  mov rdi, 0
  syscall

