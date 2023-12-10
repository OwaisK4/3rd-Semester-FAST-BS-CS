TITLE Question 4
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
source BYTE "Owais Ali Khan", 0

.code
main PROC
mWrite "Original: "
mov edx, OFFSET source
call WriteString
call Crlf

push LENGTHOF source - 1
push OFFSET source
call Str_String

mWrite "Reversed: "
mov edx, OFFSET source
call WriteString
call Crlf
exit
main ENDP

Str_String PROC ; Takes arguments: OFFSET string, length of string(without null terminator). Reverses in-place.
push ebp
mov ebp, esp
mov eax, 0
mov esi, [ebp + 8]
mov ecx, [ebp + 12]
L1:
	mov al, [esi]
	push eax
	inc esi
	loop L1
mov esi, [ebp + 8]
mov ecx, [ebp + 12]
L2:
	pop eax
	mov [esi], al
	inc esi
	loop L2
mov esp, ebp
pop ebp
ret
Str_String ENDP
END main