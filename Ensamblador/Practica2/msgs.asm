        section .data
msg1: db 'El numero es positivo',10
ms1: equ $-msg1
msg2:db 'El numero es negativo',10
ms2: equ $-msg2

    section .text
    global _start
-_start:
    mov eax,5
    mov ebx,0
    cmp eax,ebx
    jg bigger
    mov eax,4
    mov ebx, 1
    mov ecx,msg2
    mov edx,ms2
    int 0x80

bigger:
    mov eax,4
    mov ebx,1
    mov ecx,msg1
    mov edx,ms1
    int 0x80

end:
    mov eax,1
    mov ebx,0
    int 0x80

    section .bss
    