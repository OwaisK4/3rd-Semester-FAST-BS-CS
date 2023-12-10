TITLE Question 4
INCLUDE Irvine32.inc

.data
arrayB BYTE 10, 20, 30
arrayW WORD 150, 250, 350
arrayD DWORD 600, 1200, 1800
SUM1 DWORD ?
SUM2 DWORD ?
SUM3 DWORD ?
msg1 BYTE 13, 10, "SUM1 = ", 0
msg2 BYTE 13, 10, "SUM2 = ", 0
msg3 BYTE 13, 10, "SUM3 = ", 0

.code
main PROC
mov eax, 0
add al,  [arrayB]
add ax,  [arrayW]
add eax, [arrayD]

mov ebx, 0
add bl,  [arrayB + 1]
add bx,  [arrayW + 2]
add ebx, [arrayD + 4]

mov ecx, 0
add cl,  [arrayB + 2]
add cx,  [arrayW + 4]
add ecx, [arrayD + 8]

call DumpRegs

mov eax, eax
mov edx, OFFSET msg1
call writestring
call writeint

mov eax, ebx
mov edx, OFFSET msg2
call writestring
call writeint

mov eax, ecx
mov edx, OFFSET msg3
call writestring
call writeint

exit
main ENDP
END main