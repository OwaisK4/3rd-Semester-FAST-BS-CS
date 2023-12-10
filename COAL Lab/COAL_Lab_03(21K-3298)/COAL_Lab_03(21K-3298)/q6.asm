TITLE Question 6
INCLUDE Irvine32.inc

.DATA
varA BYTE 00010000b; 10h
varB BYTE 00010101b; 15h
varC BYTE 00100000b; 20h
varD BYTE 00110000b; 30h

.CODE
main PROC

mov eax, 0
mov ebx, 0
mov ecx, 0
mov edx, 0

mov al, varA
mov bl, varA
mov cl, varC
mov dl, varD

add al, varB
sub bl, varB
sub al, bl
add al, cl
add al, dl
mov bl, al

call DumpRegs ; display registers

exit
main ENDP
END main


;ebx = { (a+b) – (a-b) + c } +d