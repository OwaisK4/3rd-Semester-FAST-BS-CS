TITLE Question 10
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
arr1 SDWORD 1, 9, 5, 23, 68, 6
arr2 SDWORD 0, 2, 3, 4, 5, 3
count DWORD 6
difference DWORD 5

.code
main PROC
CountNearMatches PROTO, array1:PTR SDWORD, array2:PTR SDWORD, arrSize:DWORD, diff:DWORD
INVOKE CountNearMatches, ADDR arr1, ADDR arr2, count, difference
mWrite "The count of near matches in given arrays is: "
call WriteDec
call Crlf
exit
main ENDP

CountNearMatches PROC USES esi edi ebx ecx, array1:PTR SDWORD, array2:PTR SDWORD, arrSize:DWORD, diff:DWORD
mov eax, 0
mov esi, array1
mov edi, array2
mov ecx, arrSize
L1:
	mov ebx, [esi]
	sub ebx, [edi]
	cmp ebx, diff
	JG NotIncremented
	inc eax
	NotIncremented:
		add esi, 4
		add edi, 4
		loop L1
ret
CountNearMatches ENDP

END main