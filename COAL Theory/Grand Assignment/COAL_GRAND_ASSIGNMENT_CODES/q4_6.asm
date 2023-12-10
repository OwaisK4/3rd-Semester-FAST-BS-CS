TITLE QUESTION 4(vi)
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
MOON BYTE 20 DUP(?)

.code
main PROC
call STAR_ARRAY
mov esi, OFFSET MOON
mov ecx, 20
PRINT:
	mov al, [esi]
	call WriteChar
	inc esi
	loop PRINT
call Crlf
exit
main ENDP

STAR_ARRAY PROC
push ebp
mov	ebp, esp
sub	esp, 20

mov ecx, 19
L1:
	cmp ecx, 0
	js	L2
	lea	edx, [ebp-20]
	mov eax, ecx
	add	eax, edx
	mov	BYTE PTR [eax], 42			; '*' = 42
	mov eax, ecx
	add	eax, OFFSET MOON
	mov	BYTE PTR [eax], 120			; 'x' = 120
	sub ecx, 1
	jmp L1
L2:
lea esi, [ebp-20]
mov ecx, 20
PRINT:
	mov al, [esi + ecx - 1]
	call WriteChar
	loop PRINT
call Crlf

add esp, 20
pop ebp
ret
STAR_ARRAY ENDP

END main