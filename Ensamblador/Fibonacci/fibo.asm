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
    mov ebx,100
    mov ecx,0
converloop:
    mov edx,0
    div ebx
    add dl,'0'
    mov [esp + ecx],dl
    inc ecx
    cmp eax,0
    jnz converloop

;imprimir digitos
    mov edx,ecx
    mov ecx,esp
    mov ebx,1
    mov eax,4
    
    mov eax,1
    mov ebx,0
    int 0x80
    



