; 04-uppercase-xlat
; Demo of uppercase conversion using xlat
; Usage: ./04-uppercase-xlat < [INPUT FILE]

section .data
  StatMsg: db "Processing...", 10
  StatMsgLen: equ $-StatMsg
  DoneMsg: db "Done.", 10
  DoneMsgLen: equ $-DoneMsg

  UpCase:
  db 20h,20h,20h,20h,20h,20h,20h,20h,20h,09h,0Ah,20h,20h,20h,20h,20h
	db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
	db 20h,21h,22h,23h,24h,25h,26h,27h,28h,29h,2Ah,2Bh,2Ch,2Dh,2Eh,2Fh
	db 30h,31h,32h,33h,34h,35h,36h,37h,38h,39h,3Ah,3Bh,3Ch,3Dh,3Eh,3Fh
	db 40h,41h,42h,43h,44h,45h,46h,47h,48h,49h,4Ah,4Bh,4Ch,4Dh,4Eh,4Fh
	db 50h,51h,52h,53h,54h,55h,56h,57h,58h,59h,5Ah,5Bh,5Ch,5Dh,5Eh,5Fh
	db 60h,41h,42h,43h,44h,45h,46h,47h,48h,49h,4Ah,4Bh,4Ch,4Dh,4Eh,4Fh
	db 50h,51h,52h,53h,54h,55h,56h,57h,58h,59h,5Ah,7Bh,7Ch,7Dh,7Eh,20h
	db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
	db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
	db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
	db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
	db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
	db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
	db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
	db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h

section .bss
  ReadBufSz equ 1024
  ReadBuf: resb ReadBufSz

section .text
global _start

_start:
  mov rbp, rsp    ; init stack frame

  ; Display processing message in stderr
  mov rax, 1          ; sys_write
  mov rdi, 2          ; stderr
  mov rsi, StatMsg    ; message addr
  mov rdx, StatMsgLen ; message sz
  syscall


  ; Read up to ReadBufSz chars into ReadBuf
read:
  mov rax, 0          ; sys_read
  mov rdi, 0          ; stdin
  mov rsi, ReadBuf    ; buffer address
  mov rdx, ReadBufSz  ; length of read buffer
  syscall
  mov rbp, rax        ; save the number of bytes read
  cmp rax, 0          ; if no more bytes, bail out
  je exit

  ; Setup the registers required by XLAT
  mov rbx, UpCase     ; address of table
  mov rdx, ReadBuf    ; address of buffer
  mov rcx, rbp        ; number of bytes in the buffer

  ; use xlat to translate data using the table
translate:
  xor rax, rax
  mov al, byte [rdx-1+rcx]    ; load char for translation
  xlat                        ; translate al using table
  mov byte [rdx-1+rcx], al    ; but translated char back into al
  dec rcx                     ; decrement rcx
  jnz translate

  ; write translated buffer into stdout
write:
  mov rax, 1          ; sys_write
  mov rdi, 1          ; stdout
  mov rsi, ReadBuf    ; buffer
  mov rdx, rbp        ; buffer len
  syscall
  jmp read            ; read next buffer from stdin

exit:
  mov rax, 1          ; sys_write
  mov rdi, 2          ; stderr
  mov rsi, DoneMsg    ; message addr
  mov rdx, DoneMsgLen ; message sz
  syscall
  
  mov rax, 60         ; sys_exit
  mov rdi, 0          ; exit code
  syscall
