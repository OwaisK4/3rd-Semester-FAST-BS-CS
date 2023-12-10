TITLE Question 3
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
string BYTE "Owais Ali Khan", 0

.code
main PROC
mov eax, 0
mov esi, 0
mov edi, 0
mWrite "Original string: "
mov edx, OFFSET string
call WriteString
call Crlf
push OFFSET string
call Reverse
mWrite "Reversed string: "
mov edx, OFFSET string
call WriteString
call Crlf
exit
main ENDP

Reverse PROC
push ebp
mov ebp, esp
mov esi, [ebp + 8]
movzx eax, BYTE PTR [esi]
cmp eax, 0
jne RECURSE
mov esp, ebp
pop ebp
ret 4

RECURSE:
	push eax
	add esi, 1
	push esi
	call Reverse
	pop eax
	mov string[edi], al
	add edi, 1

mov esp, ebp
pop ebp
ret 4
Reverse ENDP

END main