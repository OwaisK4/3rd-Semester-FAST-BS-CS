INCLUDE Irvine32.inc

.data
A BYTE "A"
B BYTE "B"

.code
main PROC
mov eax, "A"
mov ebx, "B"
mov ecx, 0
mov cl, A
mov ch, B

call DumpRegs

xchg eax, ebx
xchg A, B
mov cl, A
mov ch, B
call DumpRegs

exit
main ENDP
END main