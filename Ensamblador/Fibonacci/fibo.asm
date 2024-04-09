section .data
    bas0: dd 0
    bas1: dd 1
section .text
    global _start
_start:
    mov eax,[bas0]
    mov ebx,[bas1]
    ;Numero para calcular
    mov ecx,8
fib:
    mov edx,eax
    add eax,ebx
    mov ebx,edx
    dec ecx
    cmp ecx,1
    jg fib
    mov [bas1],eax
    ;imprimir
imploop:
    ;imprimir centenas
    mov eax,[bas1]
    div 100
    mul 100
    mov ebx,[bas1]
    sub ebx,eax
    mov [bas1],ebx
    mov edx,eax
    ;Impresión primer digito
    mov eax,4
    mov ebx,1
    mov ecx,edx
    ;Imprimir decenas
    mov eax,
    div 10
    sub eax,edx
    