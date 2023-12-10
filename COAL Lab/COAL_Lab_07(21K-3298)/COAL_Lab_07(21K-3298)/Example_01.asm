Include Irvine32.inc

.code
main PROC
mov eax, 0
mov al, 10101110b ; Clear only bit 3
and al, 11110110b ; AL = 10100110
call WriteBin
call Crlf

mov al, 11100011b ; set bit 2
or al, 00000100b ; AL = 11100111
call WriteBin
call Crlf

mov al, 10110101b ; 5 bits means odd parity
xor al, 0 ; PF = 0 (PO)
call WriteBin
call Crlf

mov al, 10100101b ; 4 bits means even parity
xor al, 0 ; PF = 1 (PE)
call WriteBin
call Crlf

mov al, 11110000b
not al ; AL = 00001111b
call WriteBin
call Crlf

mov al, 00100101b
test al, 00001001b ; ZF = 0
call DumpRegs
call WriteBin
call Crlf

mov al, 00100101b

test al, 00001000b ; ZF = 1
call DumpRegs
call WriteBin
call Crlf

exit
main ENDP
END main