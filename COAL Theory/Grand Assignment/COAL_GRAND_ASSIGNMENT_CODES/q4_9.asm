TITLE QUESTION 4(ix)
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
string BYTE "SITYA", 0
source BYTE "FAST NATIONAL UNIVERSITY", 0
s_size = ($ - source) - 1
target DWORD s_size DUP(?)

.code
main PROC
mov eax, 0
mov esi, OFFSET source
mov edi, OFFSET target
mov ecx, s_size
L1:
	mov al, BYTE PTR [esi]
	mov DWORD PTR [edi], eax
	add esi, 1
	add edi, 4
	loop L1

mov edi, OFFSET target
mov ecx, s_size
PRINT:
	mov eax, DWORD PTR [edi]
	call WriteDec
	mWrite " "
	add edi, 4
	loop PRINT
call Crlf
call SEARCH

exit
main ENDP

SEARCH PROC
mov esi, OFFSET string
mov edi, OFFSET source
lea ecx, [s_size - 1]
L1:
	INVOKE Str_compare, esi, edi
	je FOUND
	add edi, 1
	loop L1
mWrite "Given substring: "
mov edx, OFFSET string
call WriteString
mWrite " not found in original string."
call Crlf
jmp ENDD
FOUND:
	mWrite "Found substring: "
	mov edx, OFFSET string
	call WriteString
	mWrite " in original string."
	call Crlf

ENDD:
	ret
SEARCH ENDP

END main