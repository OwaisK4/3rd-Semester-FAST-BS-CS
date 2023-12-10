INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
Str1 BYTE "127&j~3#^&*#*#45^", 0

.code
main PROC
push LENGTHOF Str1
push DWORD PTR Str1
call Scan_String
exit
main ENDP

Scan_String PROC
mov esi, 0
mov eax, '#'
mov ecx, LENGTHOF Str1
L1:
	cmp Str1[esi], al
	jz FOUND
	inc esi
	loop L1
mWrite "No instance of "
call WriteChar
mWrite " found in given string."
jmp endd
FOUND:
	mWrite "Found instance of "
	call WriteChar
	mWrite " at index "
	mov eax, esi
	call WriteDec
endd:
	call Crlf
	ret
Scan_String ENDP
END main