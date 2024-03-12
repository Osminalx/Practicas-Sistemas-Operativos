        section .data

        section .text
        global _start
_start:
        mov AL,1
        mov AH,7
        inc AX

        mov EAX,1
        mov EBX,0
        init 0x80

        section .bss