TITLE Question 1
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
intArray SDWORD 30, -40, 20, 65, 80, 45
count DWORD LENGTHOF intArray

.code
main PROC
mWrite "Array values:"
mov ecx, count
mov esi, OFFSET intArray
PRINT:
	mov eax, [esi]
	call WriteInt
	mWrite " "
	add esi, TYPE intArray
	loop PRINT
call Crlf
call Crlf
mWrite "j = 20 and k = 50 for 1st call"
call Crlf
push 50 ; K
push 20 ; J
push count
push OFFSET intArray
call SumArray
mWrite "Sum = "
call WriteInt
call Crlf
call Crlf

mWrite "j = 35 and k = 90 for 1st call"
call Crlf
push 90 ; K
push 35 ; J
push count
push OFFSET intArray
call SumArray
mWrite "Sum = "
call WriteInt
call Crlf
exit
main ENDP

SumArray PROC USES ebx ecx edx esi, array:PTR DWORD, array_size:DWORD, J:DWORD, K:DWORD
mov esi, array
mov ecx, array_size
mov eax, 0
L1:
	mov ebx, [esi]
	cmp ebx, J
	JL NEXT
	cmp ebx, K
	JG NEXT
	add eax, ebx
	NEXT:
		add esi, 4
		loop L1
ret
SumArray ENDP

END main