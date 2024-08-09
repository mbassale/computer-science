; Example 1: Syscall

; Initialized data section
SECTION .data
  TextMsg: db "Hello, world!", 10
  TextMsgLen: equ $-TextMsg

; Uninitialized data section
SECTION .bss

; Code section
SECTION .text
  global _start         ; linker entry point

_start:
  mov rbp, rsp          ; gdb preamble
  nop                   ;

  ; write TextMsg to stdout
  mov rax, 1            ; sys_write syscall
  mov rdi, 1            ; 1=stdout
  mov rsi, TextMsg      ; text message
  mov rdx, TextMsgLen   ; length of the text being written
  syscall

  ; exit program
  mov rax, 60           ; exit program syscall
  mov rdi, 0            ; exit code
  syscall


