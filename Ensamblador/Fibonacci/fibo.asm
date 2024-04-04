section .data
    bas0: dd 0
    bas1: dd 1
section .text
    global _start
_start:
    mov eax,[bas0]
    mov ebx,[bas1]
    mov ecx,6
fib:
    mov edx,eax
    add eax,ebx
    mov ebx,edx
    dec ecx
    cmp ecx,1
    jg fib
    add eax,48
    mov [bas1],eax
    ;imprimir
    mov eax,4
    mov ebx,1
    mov ecx,bas1
    mov edx,1
    int 0x80
    
    mov eax,1
    mov ebx,0
    int 0x80



