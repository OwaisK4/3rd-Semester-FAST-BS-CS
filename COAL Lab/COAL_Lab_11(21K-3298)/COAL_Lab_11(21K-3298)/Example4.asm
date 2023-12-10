INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
string1 BYTE 'abcd' ,0
string2 BYTE 'abcde',0

.code
main PROC
;Str_compare PROTO
INVOKE Str_compare, ADDR string1, ADDR string2
JA greater
JB lesser
JE equal
equal:
	mWrite "Strings are equal."
	jmp endd
greater:
	mWrite "String1 is greater."
	jmp endd
lesser:
	mWrite "String2 is greater."
	jmp endd
endd:
	call Crlf
	exit
main ENDP
END main