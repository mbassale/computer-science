; Newlines: procedure to put lines in stdout
; Usage: ./05-new-lines [1-15]

section .data

section .bss

section .text
  global _start

;------------------------------------------------
; proc newlines: print lines to stdout
; args: 
;   rdx: number of lines to print [1-15] lines
;------------------------------------------------
newlines:
  cmp rdx, 15     ; validate no more than 15 lines
  ja .exit

  mov rsi, EOLs   ; buffer to print
  mov rax, 1      ; sys_write
  mov rdi, 1      ; stdout
  syscall

.exit:
  ret

  EOLs db 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10


;------------------------------------------------
; START
;------------------------------------------------

_start:
  mov rdx, 5
  call newlines

  mov rdx, 20
  call newlines

  mov rdx, 1
  call newlines
  
exit:
  mov rax, 60     ; sys_exit
  mov rdi, 0      ; exit code
  syscall
