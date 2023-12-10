INCLUDE Irvine32.inc

.data
val BYTE 10, 20, 30, 40, 50
Var WORD "AB", 0ABh, 20 DUP(10 DUP("AB"), 10 DUP(0ABh), "AB", 0ABh)

.code
main PROC
mov eax, 0
;mov ax, LENGTHOF val
mov esi, OFFSET val
mov eax, OFFSET val
mov ch, val
mov ebx, [eax]
mov eax, SIZEOF Var
call writeint

call DumpRegs

exit
main ENDP
END main