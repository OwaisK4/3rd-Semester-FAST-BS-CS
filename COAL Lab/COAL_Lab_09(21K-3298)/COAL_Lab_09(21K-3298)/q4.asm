TITLE Question 4
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data

.code
main PROC
mov eax, 0000000011111111b
mov ebx, 0000000000000000b

; Without SHRD
mWrite "Without SHRD Instruction"
call Crlf
ror ax, 1
rcr bx, 1
rol ax, 1

mWrite "eax = "
call WriteBin
call Crlf

mWrite "ebx = "
xchg eax, ebx
call WriteBin
call Crlf
call Crlf
xchg eax, ebx

; With SHRD
mWrite "With SHRD Instruction"
call Crlf
mov eax, 0000000011111111b
mov ecx, 0000000000000000b
shrd cx, ax, 1

mWrite "eax = "
call WriteBin
call Crlf

mWrite "ecx = "
xchg eax, ecx
call WriteBin
call Crlf
xchg eax, ebx

exit
main ENDP
END main