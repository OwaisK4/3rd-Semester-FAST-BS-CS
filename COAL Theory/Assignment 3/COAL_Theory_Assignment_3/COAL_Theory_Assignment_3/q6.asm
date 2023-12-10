TITLE Question 6
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
arrayA SDWORD 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
arrayB SDWORD 1, 2, 3, 4, 5, 6, 7, 8, 9, 9
arraySize DWORD 10
count DWORD 0

.code
main PROC
CountMatches PROTO, arrA:PTR DWORD, arrB:PTR DWORD, arrSize:DWORD
INVOKE CountMatches, ADDR arrayA, ADDR arrayB, arraySize
mov eax, count
mWrite "The total count of same elements is: "
call WriteDec
exit
main ENDP

CountMatches PROC USES esi edi, arrA:PTR DWORD, arrB:PTR DWORD, arrSize:DWORD
mov esi, arrA
mov edi, arrB
mov ecx, arrSize
L1:
	mov eax, [esi]
	cmp eax, [edi]
	jne No_increment
	inc count
	No_increment:
		add esi, 4
		add edi, 4
		loop L1
ret
CountMatches ENDP

END main