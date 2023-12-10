TITLE Question 3
INCLUDE Irvine32.inc

.data
array DWORD 8, 5, 1, 2, 6

.code
main PROC
mov eax, array[2 * TYPE array]
xchg eax, array[0 * TYPE array]
xchg eax, array[4 * TYPE array]
xchg eax, array[3 * TYPE array]
xchg eax, array[1 * TYPE array]
xchg eax, array[2 * TYPE array]

call DumpRegs

mov eax, [array]
call writeint
mov eax, [array + 4]
call writeint
mov eax, [array + 8]
call writeint
mov eax, [array + 12]
call writeint
mov eax, [array + 16]
call writeint

exit
main ENDP
END main