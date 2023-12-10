TITLE Question 3
INCLUDE Irvine32.inc

.DATA
wArray WORD 1,2,3
wArray2 DWORD 1,2,3

.CODE
main PROC
mov ax, wArray[0]
mov bx, wArray[2]
mov cx, wArray[4]

;mov eax, wArray2[0]
;mov ebx, wArray2[4]
;mov ecx, wArray2[8]

call DumpRegs ; display registers
exit

main ENDP
END main
