; Ex02 Lowercase Conversion

section .data
  StrBuffer db "LOREMIPSUM", 0
  StrBufferLen equ $-StrBuffer-1

section .bss

section .text
  global _start 

_start:
  mov rbp, rsp ; save stack pointer
  nop

; convert to lower case
  mov rbx, StrBuffer    ; load StrBuffer memory
  mov rax, StrBufferLen ; load StrBufferLen static value
loop01:
  add byte [rbx], 32    ; add 32 to convert to uppercase
  inc rbx               ; move to next char
  dec rax               ; decrement counter
  jnz loop01            ; loop if still chars to process

exit:
  nop
  mov rax, 60   ; exit syscall
  mov rdi, 0
  syscall

