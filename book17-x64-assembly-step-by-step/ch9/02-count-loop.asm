; Ex02 Simple Count to Zero Loop
; Usage: ./02-count-loop.asm

section .bss

section .data
  RunningSum db 0
  CountMsg db "Counter:  ", 10
  CountMsgLen equ $-CountMsg

section .text
  global _start

_start:
  mov rbp, rsp  ; creating stack frame

  mov byte [RunningSum], 0  ; counter
  mov r8, 9                 ; loop counter
  
loop:
  add byte [RunningSum], 1  ; increment conter

  ; format CountMsg for printing
  xor rbx, rbx
  mov bl, byte [RunningSum]
  add bl, '0'               ; convert count to char
  mov byte [CountMsg+CountMsgLen-2], bl
 
  ; print CountMsg to stdout
  mov rax, 1            ; sys_write=1
  mov rdi, 1            ; fd=1 (stdout)
  mov rsi, CountMsg     ; line to print
  mov rdx, CountMsgLen  ; number of chars to print
  syscall

  dec r8
  jnz loop

exit:
  mov rax, 60   ; sys_exit
  mov rdi, 0    ; exit_code=0
  syscall
