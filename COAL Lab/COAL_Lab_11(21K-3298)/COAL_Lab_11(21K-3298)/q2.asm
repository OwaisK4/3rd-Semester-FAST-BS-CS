INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
beta byte "Not Found", 0
Str1 BYTE "127&j~3#^&*#*#45^", 0

.code
main PROC
push '#'
push LENGTHOF Str1
push OFFSET Str1
call Scan_String
exit
main ENDP

Scan_String PROC, string:DWORD, count:DWORD, character:DWORD
mov edi, string
mov ecx, count
;mov al, '#'
mov al, BYTE PTR character
repne scasb
jnz quit
found:
	dec edi
	mWrite "Found "
	call WriteChar
	mWrite " at index: "
	sub edi, string
	mov eax, edi
	call WriteDec
	jmp endd
quit:
	mov edx, OFFSET  beta
	call WriteString
endd:
	call Crlf
	ret
Scan_String ENDP
END main