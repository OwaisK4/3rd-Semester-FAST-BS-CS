TITLE TEST
INCLUDE Irvine32.inc

.data

.code
main PROC
mov eax, 0
mov al, 10101110b ; Clear only bit 3
call WriteBin
call Crlf
and al, 11110110b ; AL = 10100110
call WriteBin
call Crlf
call Crlf

mov al, 11100011b ; set bit 2
call WriteBin
call Crlf
or al, 00000100b ; AL = 11100111
call WriteBin
call Crlf
call Crlf

mov al, 11100011b ; set bit 2
call WriteBin
call Crlf
xor al, 11111111b
call WriteBin
call Crlf
call DumpRegs

exit
main ENDP
END main