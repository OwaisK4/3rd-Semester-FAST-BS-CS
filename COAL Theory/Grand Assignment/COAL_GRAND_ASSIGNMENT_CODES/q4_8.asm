TITLE QUESTION 4(viii)
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
ArraySearchValues BYTE 20 DUP(1)
ArrayValues BYTE 1000 DUP(1)

.code
main PROC
cld
mov esi, OFFSET ArraySearchValues
mov edi, OFFSET ArrayValues
lea ecx, [1000 - 20]
L1:
	push ecx
	push esi
	push edi
	mov ecx, 20
	repe cmpsb
	je FOUND
	pop edi
	pop esi
	pop ecx
	add edi, 1
	loop L1
mWrite "ArraySearchValues not found in ArrayValues."
call Crlf
jmp ENDD
FOUND:
	mWrite "ArraySearchValues found at "
;	mov eax, esi
	lea eax, [esi - 20]
	sub eax, OFFSET ArraySearchValues
	call WriteDec
	call Crlf
ENDD:
	exit
main ENDP

END main