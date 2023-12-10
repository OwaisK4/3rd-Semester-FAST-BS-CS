TITLE QUESTION 4(vii)
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
dividend_d DWORD 0D4A4h
divisor_d DWORD 0Ah
DIVIDE PROTO, dividend:DWORD, divisor:DWORD

.code
main PROC
INVOKE DIVIDE, dividend_d, divisor_d
exit
main ENDP

DIVIDE PROC, dividend:DWORD, divisor:DWORD
mov eax, dividend
mov edx, 0
mWrite "Dividend = "
call WriteHex
call Crlf
div divisor
cmp eax, 05h
jbe BASE
mov dividend, eax
INVOKE DIVIDE, dividend, divisor
BASE:
	ret
DIVIDE ENDP

END main