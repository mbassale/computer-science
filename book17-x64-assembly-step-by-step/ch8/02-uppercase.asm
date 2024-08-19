; Ex2 Uppercase Program
; Converts file in stdin to uppercase in stdout
; Syntax: ./02-uppercase < input > output

section .bss
  BUFSZ equ 128
  BUF resb BUFSZ

section .data

section .text
  global _start

_start:
  mov rbp, rsp  ; save stack ptr for gdb

read:
  mov rax, 0      ; sys_read syscall
  mov rdi, 0      ; fd = 0 (stdin)
  mov rsi, BUF    ; address to read to
  mov rdx, BUFSZ  ; read BUFSZ chars from stdin
  syscall

  mov r12, rax    ; save number of chars
  cmp rax, 0      ; sys_read return val in RAX
  je exit

  ; setup regs for processing the buffer
  mov rbx, rax    ; set rbx = number of chars read
  mov r13, BUF    ; address of BUF into r13
  dec r13         ; offset 1 to prevent off-by-one error when reading

  ; convert lowercase to uppercase
scan:
  cmp byte [r13+rbx], 61h ; compare *buf char with 'a'
  jb next                 ; if below 'a', not lowercase
  cmp byte [r13+rbx], 7Ah ; compare *buf char with 'z'
  ja next                 ; if above 'z', not lowercase

  sub byte [r13+rbx], 20h ; we have a lowercase char, subtract 20h 
                          ; to have uppercase
next:
  dec rbx                 ; dec counter to read previous char
  cmp rbx, 0              ; pass the beginning of buf, we bail out
  jnz scan                ; still remaining chars, loop again

  ; write block to stdout
write:
  mov rax, 1    ; sys_write
  mov rdi, 1    ; fd = 1 (stdout)
  mov rsi, BUF  ; address to write
  mov rdx, r12  ; number of bytes to write
  syscall
  jmp read      ; read another block

exit:
  mov rax, 60   ; sys_exit
  mov rdi, 0    ; exit code
  syscall

