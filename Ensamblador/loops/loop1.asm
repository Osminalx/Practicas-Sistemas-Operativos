section .data
msg:  db 'Entrandoal loop',10
ms1: equ $-msg
ptr: db 

    section .text
    global _start    
_start:
    ;; loop init
    mov ecx,9
    
ciclo:
    mov [con],ecx
    mov eax,48
    add eax, [con]
    mov [con],eax

    ;;imprimir
    mov eax,4
    mov ebx,1
    mov ecx,con
    ;;mov ecx,ptr
    mov eax,1
    int 0x80
    ;;fin impresion
    mov eax,[con]
    sub eax,48
    mov [con],eax
    
    mov ecx,[con]
    dec ecx
    jnz ciclo
fin:
    mov eax,1
    mov ebx,0
    int 0x80
    section .bss
    con resb 1