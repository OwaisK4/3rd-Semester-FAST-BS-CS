INCLUDE Irvine32.inc

.data
string1 BYTE "this is first string", 0
string2 BYTE "this is second string", 0

.code
main PROC
cld ; clear direction flag
mov esi,OFFSET string1 ; ESI points to source
mov edi,OFFSET string2 ; EDI points to target
mov ecx,sizeof string1 ; set counter to 10
rep movsb ; move bytes
mov edx,offset string2
call writestring
exit
main ENDP
END main