TITLE Question 5
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
char DWORD " "
countBits DWORD 0

.code
main PROC
mov eax, 0
mWrite "TYPE A CHARACTER: "
call ReadChar
call Crlf
and eax, 000000FFh
mov char, eax
mWrite "THE ASCII CODE OF A IN BINARY IS "
call WriteBin
call Crlf

L1:
	shr eax, 1
	adc countBits, 0
	or eax, eax
	jnz L1
mWrite "THE NUMBER OF 1 BITS IS "
mov eax, countBits
call WriteDec
call Crlf
exit
main ENDP

END main