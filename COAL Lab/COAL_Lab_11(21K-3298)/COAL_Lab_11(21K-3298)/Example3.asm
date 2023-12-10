INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
alpha BYTE "ABCDEFGH",0

.code
main PROC
mov edi,OFFSET alpha ; EDI points to the string
mov al,'F' ; search for the letter F
mov ecx,LENGTHOF alpha ; set the search count
cld ; direction = forward
repne scasb ; repeat while not equal
jnz quit ; quit if letter not found
dec edi ; found: back up EDI
mWrite "Letter "
call WriteChar
mWrite " found."
jmp endd
quit:
	mWrite "Letter "
	call WriteChar
	mWrite " not found."
endd:
	call Crlf
	exit
main ENDP
END main