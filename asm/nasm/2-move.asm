; move.asm

section .data
  bNum    db    123
  wNum    dw    12345
  dNum    dd    1234567890
  qNum1   dq    1234567890123456789
  qNum2   dq    123456
  qNum3   dq    3.14

section .bss

section .text
  global main

main:
  ; prologue
  push rbp
  mov rbp, rsp

  mov rax, -1             ; fill rax w/1s
  mov al, byte [bNum]     ; does not clear upper bits of rax
  xor rax, rax            ; clear rax
  mov al, byte [bNum]     ; rax correct value

  mov rax, -1
  mov ax, word [wNum]     ; does not clear upper bits of rax
  xor rax, rax
  mov ax, word [wNum]     ; rax correct value

  mov rax, -1
  mov eax, dword [dNum]   ; does clear upper bits of rax

  mov rax, -1
  mov rax, qword [qNum1]  ; does clear upper bits of rax
  mov qword [qNum2], rax  ; move rax -> memory

  mov rax, 123456         ; move inmediate value
  movq xmm0, [qNum3]      ; floating point

  ; epilogue
  mov rsp, rbp
  pop rbp
  ret
