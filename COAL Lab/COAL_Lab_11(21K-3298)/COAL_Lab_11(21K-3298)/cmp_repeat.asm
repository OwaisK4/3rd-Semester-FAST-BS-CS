TITLE Question 4
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
source BYTE "Owais Ali Khan", 0
target BYTE "Owais Ali Khan", 0

.code
main PROC
cld
mov esi, OFFSET source
mov edi, OFFSET target
lea ecx, [LENGTHOF source]
repe cmpsb
jnz NOT_EQUAL
mWrite "Given BYTE strings are equal."
jmp ENDD
NOT_EQUAL:
	mWrite "Not equal."
ENDD:
	call Crlf
exit
main ENDP
END main