Include Irvine32.inc

.data
A DWORD 10000000000000000000000000000111b
B DWORD 10000001010100000000011101100011b
msg1 BYTE "A intersection B is: ", 0
msg2 BYTE "A union B is: ", 0
msg3 BYTE "Complement of A is: ", 0

.code
main proc
mov eax, A
and eax, B	; A intersection B
mov edx, OFFSET msg1
call WriteString
mov ebx, TYPE DWORD
call WriteBinB
call Crlf
mov eax, A
or eax, B	; A union B
mov edx, OFFSET msg2
call WriteString
mov ebx, TYPE DWORD
call WriteBinB
call Crlf
mov eax, A
not eax		; A complement
mov edx, OFFSET msg3
call WriteString
mov ebx, TYPE DWORD
call WriteBinB
call Crlf
call DumpRegs
exit
main ENDP
END main