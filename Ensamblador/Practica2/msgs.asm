section .data
    ms1: DB 'El numero es positivo',10
    m1l: EQU $-ms1
    ms2: DB 'El numero es negativo',10
    m2l: EQU $-ms2
    ms3: DB 'El numero es igual a cero',10
    m3l: EQU $-ms3
;jg je jl jz jnz jge jle
section .text
    global _start
_start:
    mov eax,0
    mov ebx,0
    cmp eax,ebx
    jz Cero
    jg positivo
    mov eax,4
    mov ebx,1
    mov ecx,ms2
    mov edx,m2l
    int 80h
    jmp continuar

positivo:
    mov eax,4
    mov ebx,1
    mov ecx,ms1
    mov edx,m1l
    int 0x80

Cero:
    mov eax,4
    mov ebx,1
    mov ecx,ms3
    mov edx, m3l
    int 0x80

continuar:
    mov eax,1
    mov ebx,0
    int 0x80