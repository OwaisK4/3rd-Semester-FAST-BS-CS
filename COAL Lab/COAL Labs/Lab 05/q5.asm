INCLUDE Irvine32.inc

.data
source BYTE "Owais Ali Khan", 0
target BYTE SIZEOF source DUP(?), 0

.code
main PROC
mov eax, 0
mov esi, 0
mov ecx, LENGTHOF source
L1:
	mov al, source[esi]
	mov target[esi], al
	add esi, TYPE source
	loop L1

mov edx, OFFSET source
call writeString
call Crlf
mov edx, OFFSET target
call writeString

exit
main ENDP
END main