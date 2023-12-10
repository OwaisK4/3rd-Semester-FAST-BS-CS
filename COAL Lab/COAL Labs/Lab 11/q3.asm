TITLE Question 6
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
string1 BYTE "ABCDEFG", 0
string2 BYTE "ABCDEF", 0

.code
main PROC
IsCompare PROTO, source:PTR DWORD, target:PTR DWORD
INVOKE IsCompare, ADDR string1, ADDR string2
exit
main ENDP

IsCompare PROC, source:PTR DWORD, target:PTR DWORD
mWrite "First string: "
mov edx, source
call WriteString
call Crlf
mWrite "Second string: "
mov edx, target
call WriteString
call Crlf
call Crlf
INVOKE STR_COMPARE, source, target
JA greater
JB lesser
JE equal
greater:
	mWrite "First string is greater than second string."
	jmp endd
lesser:
	mWrite "First string is smaller than second string."
	jmp endd
equal:
	mWrite "Both strings are equal."
	jmp endd
endd:
	call Crlf
	ret
IsCompare ENDP
END main