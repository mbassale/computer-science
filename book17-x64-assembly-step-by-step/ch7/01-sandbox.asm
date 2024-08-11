; Chapter 7: Sandbox for testing instructions

section .data

section .bss

section .text
  global main

main:
  mov rbp, rsp
  nop

  ; little endian ordering
  mov eax, 'WXYZ'
  nop

  ; set to zero
  xor rax, rax
  nop

  ; xchg
xchg_ex:
  xor rcx, rcx
  mov cl, 1h
  mov ch, 2h
  xchg cl, ch
  nop

  ; inc, dec and flags
inc_ex:
  mov ebx, 02Dh
  dec ebx
  mov eax, 0FFFFFFFFh
  inc eax

  ; loop
loop_ex:
  mov rax, 5
loop01:
  dec rax
  jnz loop01

  nop
  mov rax, 60   ; exit syscall
  mov rdi, 0
  syscall

section .note.GNU-stack noalloc noexec nowrite progbits
