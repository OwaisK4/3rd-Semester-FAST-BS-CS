TITLE Question 6
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
g_source BYTE 10 DUP(0), 0
encrypt PROTO, source:PTR BYTE

.code
main PROC
mWrite "Enter string: "
mov edx, OFFSET g_source
mov ecx, 10
call ReadString
call Crlf
mov ecx, 0
INVOKE encrypt, ADDR g_source
mov edx, OFFSET g_source
call WriteString
exit
main ENDP

encrypt PROC, source:PTR BYTE
mov esi, source
cmp ecx, 10
JE BASE
mov al, BYTE PTR [esi]
ror al, cl
;ror al, 1
;call WriteChar
mov BYTE PTR [esi], al
add source, 1
add ecx, 1
INVOKE encrypt, source
BASE:
	;mov BYTE PTR [source], 0
	ret
encrypt ENDP

END main