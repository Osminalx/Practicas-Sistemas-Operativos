section .data
    matrix1 dq 1, 2, 3, 4         ; Matriz 1: [1, 2, 3, 4]
    matrix2 dq 5, 6, 7, 8         ; Matriz 2: [5, 6, 7, 8]
    result dq 0                    ; Variable para almacenar el resultado
    result_format db "El producto punto es: %lf", 10, 0  ; Formato para imprimir el resultado

section .text
    extern printf                   ; Declaración externa de la función printf

    global _start

_start:
    mov rsi, matrix1               ; Dirección de inicio de la matriz 1
    mov rdi, matrix2               ; Dirección de inicio de la matriz 2
    mov rcx, 4                     ; Número de elementos en las matrices (4 en este caso)

    xorpd xmm0, xmm0               ; Limpiar el registro xmm0 para almacenar el resultado

dot_product_loop:
    movsd xmm1, [rsi]              ; Cargar el primer elemento de la matriz 1 en xmm1
    movsd xmm2, [rdi]              ; Cargar el primer elemento de la matriz 2 en xmm2
    mulsd xmm1, xmm2               ; Multiplicar los elementos
    addsd xmm0, xmm1               ; Sumar el resultado al acumulador en xmm0

    add rsi, 8                     ; Avanzar a siguiente elemento de la matriz 1 (8 bytes)
    add rdi, 8                     ; Avanzar a siguiente elemento de la matriz 2 (8 bytes)
    loop dot_product_loop          ; Repetir para el siguiente elemento

    movsd [result], xmm0           ; Almacenar el resultado en la variable result

    ; Llamada a printf para imprimir el resultado
    mov rdi, result_format         ; Dirección del formato de la cadena
    movq xmm0, [result]            ; Cargar el resultado en xmm0 para imprimirlo como argumento flotante
    call printf                    ; Llamar a la función printf

    ; Código de salida
    mov rax, 60                    ; Código de salida para sys_exit
    xor rdi, rdi                   ; Código de salida 0
    syscall
