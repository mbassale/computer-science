; 6-memory

section .data
  bNum    db      123
  wNum    dw      12345
  warray  times   5 dw 0 ; warray[5] = 0

  dNum    dd      12345
  qNum1   dq      12345
  text1   db      "abc", 0
  qNum2   dq      3.141592654
  text2   db      "cde", 0

section .bss
  bvar    resb    1
  dvar    resd    1
  wvar    rest   10
  qvar    resq    3

section .text
  global main
main:
    mov rbp, rsp; for correct debugging
  push rbp
  mov rbp, rsp

  xor rax, rax
  lea rax, [bNum]   ; load addr bNum in rax
  mov rax, bNum     ; load addr bNum in rax

  mov rax, [bNum]   ; load value at bNum in rax
  mov [bvar], rax   ; move rax (8 bytes) -> addr of bvar overriding dvar and partially wvar

  lea rax, [bvar]   ; load addr bvar in rax
  lea rax, [wNum]   ; load addr wNum in rax
  mov rax, [wNum]   ; load value at wNum in rax

  lea rax, [text1]  ; load address of text1 in rax
  mov rax, text1    ; load address of text1 in rax

  mov rax, text1+1  ; load address of text1 second char in rax
  lea rax, [text1+1]; load address of text1 second char in rax

  xor rax, rax
  mov rax, [text1]  ; load 8 bytes from text1 in rax
  mov rax, [text1]  ; load 8 bytes from text1+1 in rax

  mov rsp, rbp
  pop rbp
  ret
