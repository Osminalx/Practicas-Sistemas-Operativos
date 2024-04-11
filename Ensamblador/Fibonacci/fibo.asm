section .data
    bas0: dd 0
    bas1: dd 1
    divider: dd 0
    con: dd 0
    final:dd 0
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
flags:
    mov ecx,100
    mov [divider],ecx
    mov ecx,0
    mov ecx,3
print:
    ;contador
    mov[con],ecx
    mov edx,0
    mov eax,0
    ;division
    mov eax,[bas1]
    mov ebx,[divider]
    div ebx
    ;preparar impresion
    mov [bas1],edx
    add eax,'0'
    mov [final],eax
    ;impresion
    mov eax,4
    mov ebx,1
    mov ecx,final
    mov edx,1
    int 0x80
    ;actualizar division
    mov edx,0
    mov ebx,10
    mov eax,[divider]
    div ebx
    mov [divider],eax
    ;actualizar contador
    mov ecx,[con]
    dec ecx
    jnz print

    mov eax,1
    mov ebx,0
    int 0x80