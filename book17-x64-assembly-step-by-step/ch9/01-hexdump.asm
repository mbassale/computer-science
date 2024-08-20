; Ex01 HexDump
; Dumps a binary file as hexadecimal
; Usage: ./01-hexdump < binary-file

section .bss
  BUFSZ equ 16
  BUF   resb BUFSZ

section .data
  ; line str that will be written to stdout with the hex values
  HEXSTR db  " 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00", 10
  HEXLEN equ $-HEXSTR

  ; lookup table for hex digits
  DIGITS db "0123456789ABCDEF"

section .text
  global _start

_start:
  mov rbp, rsp  ; creating stack frame

read:
  mov rax, 0    ; sys_read
  mov rdi, 0    ; fd=0 (stdin)
  mov rsi, BUF  ; char buffer
  mov rdx, BUFSZ  ; buffer size BUFSZ
  syscall

  mov r15, rax  ; save number of bytes read
  cmp rax, 0    ;
  je exit

  mov rsi, BUF      ; address of BUF into rsi
  mov rdi, HEXSTR   ; address of HEXSTR into rdi
  xor rcx, rcx      ; zero counter

scan:
  xor rax, rax      ; zero accumulator

  ; offset into line string, is rcx * 3 = rcx * 2 + rcx = (rcx << 1) + rcx
  mov rdx, rcx      ; copy counter into rdx
  shl rdx, 1        ; multiply by two
  add rdx, rcx      ; 2+1

  ; get next character from the buffer and put it into rax and rbx
  mov al, byte [rsi+rcx]
  mov rbx, rax

  ; lookup the low nibble (al & 0Fh) into the DIGITS lookup table
  ; and copy the corresponding character into the HEXSTR line for output
  and al, 0Fh       ; mask out except low nibble, 
                    ; gets the index into the lookup table DIGITS
  mov al, byte [DIGITS+rax]   ; move the corresponding character into al
  mov byte [HEXSTR+rdx+2], al   ; override the character in the line str

  ; lookup the hight nibble (bl >> 4) and insert into HEXSTR
  shr bl, 4         ; (bl >> 4)
  mov bl, byte [DIGITS+rbx]   ; lookup the digit
  mov byte [HEXSTR+rdx+1], bl ; override char in the line str

  inc rcx       ; move to next char in the buffer
  cmp rcx, r15  ; are we at the end of the buffer?
  jna scan      ; if rcx <= r15 continue

  ; write the line to stdout
  mov rax, 1    ; sys_write=1
  mov rdi, 1    ; fd=1 (stdout)
  mov rsi, HEXSTR   ; line to print
  mov rdx, HEXLEN   ; number of chars to print
  syscall
  jmp read          ; continue reading next buffer block

exit:
  mov rax, 60   ; sys_exit
  mov rdi, 0    ; exit_code=0
  syscall
