TITLE Question 4
INCLUDE Irvine32.inc

.CODE
main PROC
mov eax, 10001101b
sub eax, 0D83h
add eax, 385d
add eax, 10d
add eax, 1111101b
sub eax, "E"
add eax, "F"
call DumpRegs
exit

main ENDP
END main

;10001101 – D83h + 385 + 10 + 1111101 – E + F