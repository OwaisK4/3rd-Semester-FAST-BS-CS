TITLE FIBONACCI
INCLUDE Irvine32.inc
INCLUDE Macros.inc

Factorial PROTO, X:DWORD

.data
n DWORD 1

.code
main PROC
mov eax, 0
mov al, 127
;mov ebx,1
call WriteBin
call Crlf
neg al
;mov ebx,1
call DumpRegs
call WriteBin
call Crlf
call WriteInt
;mWrite "Enter value of n: "
;call ReadDec
mov n, eax
call Crlf
;mWrite "Factorial of N is: "
;INVOKE Factorial, n
;call WriteDec
;call Crlf
exit
main ENDP

Factorial PROC, X:DWORD
cmp X, 1
JE BASE
mov edx, 0

BASE:
ret
Factorial ENDP

END main