; Hexdump: Improved hexdump implementation with ASCII column display
; Usage: 01-hexdump < FILE

section .bss
  BuffSz      equ 10h
  Buff:       resb BuffSz

section .data
  ; line str that will be written to stdout with the hex values
  HexStr:     db  " 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 "
  HexStrSz    equ $-HexStr
  ; AsciiLine represents the printable chars for the hex values
  AsciiLine:  db  "|................|", 10
  AsciiLineSz equ $-AsciiLine
  FullSz      equ $-HexStr

  ; lookup table for hex digits
  HexDigits:     db "0123456789ABCDEF"

  AsciiXlat:
    db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
    db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
    db 20h,21h,22h,23h,24h,25h,26h,27h,28h,29h,2Ah,2Bh,2Ch,2Dh,2Eh,2Fh
    db 30h,31h,32h,33h,34h,35h,36h,37h,38h,39h,3Ah,3Bh,3Ch,3Dh,3Eh,3Fh
    db 40h,41h,42h,43h,44h,45h,46h,47h,48h,49h,4Ah,4Bh,4Ch,4Dh,4Eh,4Fh
    db 50h,51h,52h,53h,54h,55h,56h,57h,58h,59h,5Ah,5Bh,5Ch,5Dh,5Eh,5Fh
    db 60h,61h,62h,63h,64h,65h,66h,67h,68h,69h,6Ah,6Bh,6Ch,6Dh,6Eh,6Fh
    db 70h,71h,72h,73h,74h,75h,76h,77h,78h,79h,7Ah,7Bh,7Ch,7Dh,7Eh,2Eh
    db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
    db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
    db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
    db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
    db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
    db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
    db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
    db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh

section .text

; Proc ClearHexStr
; Clears HexStr to zeroes
ClearHexStr:
  push rax
  push rbx
  push rcx
  push rdx

  mov rdx, 15   ; 16 pokes, zero-based
.poke:
  mov rax, 0
  call PutHexChar
  sub rdx, 1
  jae .poke     ; repeat if rdx >= 0

  pop rdx
  pop rcx
  pop rbx
  pop rax
  ret

; PutHexChar
; Poke a value in the HexStr buffer
; rax: byte to be poked
; rdx: logical position (0-15) in the HexStr buffer
PutHexChar:
  push rbx
  push rdi

  ; Insert the input byte into the AsciiLine
  mov bl, [AsciiXlat+rax]     ; get ascii repr for byte
  mov [AsciiLine+rdx+1], bl   ; put the byte into AsciiLine

  ; Insert the input byte as two hex chars
  mov rbx, rax                ; save copy of input byte
  lea rdi, [rdx*2+rdx]        ; calc offset into HexStr (rdx * 3)

  ; Get low nybble char
  and rax, 0Fh                ; mask out all but the low nybble
  mov al, [HexDigits+rax]     ; get corresponding hex char
  mov byte [HexStr+rdi+2], al ; put hex char into HexStr

  ; Get high nybble char
  and rbx, 0F0h               ; mask out all but the high nybble
  shr rbx, 4                  ; shift high 4 bits from high nybble 
                              ; into the low nybble
  mov bl, [HexDigits+rbx]     ; get corresponding hex char
  mov byte [HexStr+rdi+1], bl ; put hex char into HexStr

  pop rdi
  pop rbx
  ret

; Prints HexStr to stdout
PrintHexStr:
  push rax
  push rbx
  push rcx
  push rdx
  push rsi
  push rdi

  mov rax, 1                  ; sys_write
  mov rdi, 1                  ; stdout
  mov rsi, HexStr             ; buffer
  mov rdx, FullSz             ; HexStr + AsciiLine sz
  syscall

  pop rdi
  pop rsi
  pop rdx
  pop rcx
  pop rbx
  pop rax
  ret

; Fills Buff from stdin
; Returns:
;   r15: number of bytes read from stdin
LoadBuff:
  push rax
  push rdx
  push rsi
  push rdi

  mov rax, 0                  ; sys_read
  mov rdi, 0                  ; stdin
  mov rsi, Buff               ; buffer
  mov rdx, BuffSz             ; buffer sz
  syscall
  mov r15, rax                ; return value
  xor rcx, rcx

  pop rdi
  pop rsi
  pop rdx
  pop rax
  ret

;------------------------------------------------
; START
;------------------------------------------------
global _start
_start: mov rbp, rsp          ; init stack frame
  
  ; Initialization
  xor r15, r15                ; variable for number of bytes read by LoadBuff
  xor rsi, rsi                ; counter for total bytes processed
  xor rcx, rcx                ; index of byte processed in Buff
  call LoadBuff               ; load Buff, r15 contains bytes read
  cmp r15, 0                  ; if stdin is empty exit
  jbe exit

  ; Loop to convert binary bytes to hex digits 
scan:
  xor rax, rax                ; clean reg
  mov al, byte [Buff+rcx]     ; get next byte from Buff
  mov rdx, rsi                ; save rsi into rdx as position offset in Buff
  and rdx, 0Fh                ; char counter can be 2^4=16 positions only
                              ; by masking we're getting the hex position into HexStr
  call PutHexChar             ; put rax at position rdx in HexStr

  ; bump buffer pointer to next byte
  inc rsi                     ; increment total chars processed
  inc rcx                     ; increment buffer pointer
  cmp rcx, r15                ; check if there is still Buff bytes to process
  jb .modTest
  call LoadBuff               ; load next 16 bytes
  cmp r15, 0                  ; no more input, exit
  jbe done

  ; if we're at the of a block of 16 bytes, display next line
.modTest:
  test rsi, 0Fh               ; test 4 lowest bits for 0
                              ; if 4 bits is 0, we're at 15 byte boundary
                              ; and we need to print a new line
  jnz scan
  call PrintHexStr
  call ClearHexStr
  jmp scan

done:
  call PrintHexStr            ; print remainder data

exit:
  mov rax, 60                 ; sys_exit
  mov rdi, 0                  ; exit_code=0
  syscall

