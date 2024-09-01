; Ex03 Test Instruction
; Usage: ./03-test

section .bss

section .data
  BitSetMsg db "Bit is set", 10
	BitSetMsgLen equ $-BitSetMsg

section .text
  global _start

_start:
  mov rbp, rsp	; create initial stack frame

	xor rax, rax	; clear rax
	not rax				; set rax to all 1s
	test rax, 08h	; test bit 3 in binary 00001000B, 08h
	jz exit

; 3bit is set, print message to stdout
  mov rax, 1						; sys_write=1
	mov rdi, 1						; fd=1 (stdout)
	mov rsi, BitSetMsg		; msg to print
	mov rdx, BitSetMsgLen	; msg length
	syscall
  

exit:
  mov rax, 60		; sys_exit
	mov rdi, 0		; exit_code=0
	syscall

