section .data
    ve1: dd 1,2,3
    ve2: dd 2,2,1

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
    mov eax,[sum]
    add eax,'0'
    mov [sum],eax


section .bss
    sum resd 1
    con resd 1