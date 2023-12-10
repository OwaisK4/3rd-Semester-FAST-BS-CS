INCLUDE Irvine32.inc

.data
fibonacci DWORD 1

.code
main PROC
mov eax, 0
mov ebx, 0
mov ecx, 10
L1:
	add eax, fibonacci
	mov ebx, eax
	sub ebx, fibonacci
	mov fibonacci, ebx
	call writeInt
	call Crlf
	loop L1

exit
main ENDP
END main