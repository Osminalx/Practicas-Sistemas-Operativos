section .data
    ve1: dd 2,2,3
    ve2: dd 2,2,1
    divider: dd 0
    cont:dd 0
    final:dd 0

section .text
    global _start

_start:
    mov ebx,ve1 
    mov edx,ve2
    mov ecx,1
    mov eax,0
    mov [sum],eax ;se inicializa el resultado
loop:
    mov [con],ecx
    mov eax,[ebx] ;Elemento del vec1
    mov ecx,[edx] ;Elemento del vec2
    mul ecx
    ; Se suma al resultado
    mov ebx,[sum]
    add eax,ebx
    mov [sum],eax
    ; Se mueve la dirección 4 unidades cada ciclo, i.e. 4,8,12,...
    mov ecx,[con]
    mov eax,4
    mul ecx

    mov ebx,ve1
    add ebx,eax 
    mov edx,ve2
    add edx,eax

    inc ecx
    cmp ecx,3
    jle loop

    ;imprimir el resultado
flags:
    mov ecx,100
    mov [divider],ecx
    mov ecx,0
    mov ecx,3
print:
    ;contador
    mov[cont],ecx
    mov edx,0
    mov eax,0
    ;division
    mov eax,[sum]
    mov ebx,[divider]
    div ebx
    ;preparar impresion
    mov [sum],edx
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
    mov ecx,[cont]
    dec ecx
    jnz print

    mov eax,1
    mov ebx,0
    int 0x80

section .bss
    sum resd 1
    con resd 1