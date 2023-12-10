TITLE Question 3
INCLUDE Irvine32.inc

.CODE
main PROC
mov eax, 101110b
add eax, 50Ah
add eax, 6710d
add eax, 1010001b
add eax, "F"
call DumpRegs
exit

main ENDP
END main

;101110 + 50Ah + 6710d + 1010001 + F