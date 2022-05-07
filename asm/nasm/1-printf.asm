; 1-printf.asm

%macro syswrite 2
  mov rax, 1    ; 1 = write
  mov rdi, 1    ; 1 = stdout
  mov rsi, %1   ; buffer addr
  mov rdx, %2   ; buffer len
  syscall
%endmacro

; Extern Definitions
extern    printf

section .data
  msg1    db    "Hello, world!", 10, 0
  msg1Len equ   $-msg1-1 ; current addr - msg1 addr - null terminator

  msg2    db    "Alive and Kicking!", 0

  fmtstr  db    "This is our string: %s", 10, 0   ; str print format
  fmtflt  db    "Float: %lf", 10, 0               ; float print format
  fmtint  db    "Int: %d", 10, 0                  ; int print format

  radius  dq    357
  pi      dq    3.14

section .bss

section .text
  global main

main:
; function prologue
  push  rbp       ; adjust bp to enable dynamic locals
  mov   rbp, rsp

  syswrite msg1, msg1Len

; print msg2
  mov   rdi, fmtstr
  mov   rsi, msg2
  mov   rax, 0    ; no mmx floating point numbers
  call  printf

; print radius
  mov   rax, 0
  mov   rdi, fmtint
  mov   rsi, [radius]
  call  printf

; print pi
  mov   rax, 1
  movq  xmm0, [pi]
  mov   rdi, fmtflt
  call printf

; function epilogue
  mov   rsp, rbp
  pop   rbp

; return to caller
  ret



