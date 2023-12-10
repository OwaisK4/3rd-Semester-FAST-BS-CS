INCLUDE Irvine32.inc

.data
string_1 BYTE "Hellooo",0

.code
main PROC
INVOKE Str_trim,ADDR string_1,'o'
mov edx,OFFSET string_1
call WriteString
exit
main ENDP
END main