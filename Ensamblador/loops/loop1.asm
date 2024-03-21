section .data
msg:  db 'Entrandoal loop',10
ms1: equ $-msg

    section .text
    global _start    
_start:
    ;; loop init
    mov ecx,9
    
ciclo:
    dec ecx
    mov ecx,temp
    mov eax,4
    mov ebx,1
    mov ecx,ms1
    mov edx,m1l
    int 0x80
    mov temp,ecx
    jnz ciclo
fin:
    mov eax,1
    mov ebx,0
    int 0x80
    section .bss
    con resb 1
    tmp temp 0