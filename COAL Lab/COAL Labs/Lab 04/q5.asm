TITLE Question 4
INCLUDE Irvine32.inc

.data
array1 BYTE 10, 20, 30, 40
array2 BYTE 4 DUP (?)
newline BYTE 13, 10, 0

.code
main PROC
mov eax, 0
;mov eax, DWORD PTR array1
;mov DWORD PTR array2, eax
mov esi, OFFSET array1
mov al, [esi + 3]
mov bl, [esi + 2]
mov cl, [esi + 1]
mov dl, [esi]
mov [array2], al
mov [array2 + 1], bl
mov [array2 + 2], cl
mov [array2 + 3], dl

call DumpRegs

mov eax, 0
mov al, [array1]
call writeint
mov al, [array1 + 1]
call writeint
mov al, [array1 + 2]
call writeint
mov al, [array1 + 3]
call writeint

mov edx, OFFSET newline
call writestring

mov eax, 0
mov al, [array2]
call writeint
mov al, [array2 + 1]
call writeint
mov al, [array2 + 2]
call writeint
mov al, [array2 + 3]
call writeint
exit
main ENDP
END main