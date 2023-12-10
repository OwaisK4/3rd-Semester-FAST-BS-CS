TITLE Question 2
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
array1 DWORD 1,2,3,4,5
array2 DWORD 1,2,3,4,5

.code
main PROC
call Array12Sum
exit
main ENDP

Array1Sum PROC uses esi ; Returns sum value in eax
	mov eax, 0
	mov ebx, 0
	mov ecx, LENGTHOF array1
	mWrite "Array 1: "
	L1:
		add eax, array1[esi]
		mov ebx, eax
		call WriteDec
		mWrite " "
		add esi, TYPE array1
		loop L1
	call Crlf
	mWrite "Sum of Array1: "
	xchg eax, ebx
	call WriteDec
	call Crlf
	ret
	Array1Sum ENDP

Array2Sum PROC uses esi ; Returns sum value in eax
	mov eax, 0
	mov ebx, 0
	mov ecx, LENGTHOF array2
	mWrite "Array 2: "
	L1:
		add eax, array2[esi]
		mov ebx, eax
		call WriteDec
		mWrite " "
		add esi, TYPE array2
		loop L1
	call Crlf
	mWrite "Sum of Array2: "
	xchg eax, ebx
	call WriteDec
	call Crlf
	ret
Array2Sum ENDP

Array12Sum PROC
	mov eax, 0
	mov esi, 0
	call Array1Sum
	call Crlf
	mov ebx, eax
	call Array2Sum
	add eax, ebx
	call Crlf
	mWrite "Sum of Array1 and Array2: "
	call WriteDec
	call Crlf
	ret
Array12Sum ENDP

END main