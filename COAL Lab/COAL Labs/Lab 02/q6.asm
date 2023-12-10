TITLE Question 6
INCLUDE Irvine32.inc

.code
main PROC

mov eax, 65o
mov edx, 0
sub edx, eax
mov eax, edx

add eax, 5ADh
add eax, 65o
add eax, 65d
sub eax, 11110111b
add eax, 150

call DumpRegs
exit
main ENDP
END main

;eax = 5ADh – eax + 65o + 65d – 11110111 + 150