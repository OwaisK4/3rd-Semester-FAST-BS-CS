TITLE Question 4(iv)
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
source BYTE "this is the source string.", 0
size_S = ($ - source)
target BYTE size_S DUP(0)

.code
main PROC
cld
mWrite "Source string: "
mov edx, OFFSET source
call WriteString
call Crlf
mov ebx, 0
mov esi, OFFSET source
mov ecx, size_S
L1:
	push ecx
	mov edi, OFFSET target
	lodsb
	mov ecx, size_S
	repne scasb
	jz CONTINUE
	mov target[ebx], al
	add ebx, 1
	CONTINUE:
		pop ecx
		loop L1
mov target[ebx], 0
mWrite "Target string: "
mov edx, OFFSET target
call WriteString
call Crlf

exit
main ENDP
END main