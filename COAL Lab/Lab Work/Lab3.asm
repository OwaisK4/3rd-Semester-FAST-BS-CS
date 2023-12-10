TITLE Task1
INCLUDE Irvine32.inc 

.data
val1 SWORD ?
val2 SBYTE -10

.code
main PROC
mov ax , val1		; ax = 74740000
mov bl , val2		; bl = 7EFDE0F6
mov val1 , 10		; val1 = 10
mov ax, val1		; ax = 7470000A
 
call DumpRegs
exit
main ENDP
END main

;;;;;;;;;;;;;;;;;;;;;;

TITLE Task2
INCLUDE Irvine32.inc 

.data
val3 SDWORD -2147483647

.code
main PROC
mov eax , val3		
; eax = 800000001
 
call DumpRegs
exit
main ENDP
END main

;;;;;;;;;;;;;;;;;;;;;;;;;;

TITLE Task3
INCLUDE Irvine32.inc 

.data
wArray WORD 100,200,300

.code
main PROC
mov cx , wArray[0]
mov bx , wArray[2]
mov ax , wArray[4]
 
call DumpRegs
exit
main ENDP
END main

;;;;;;;;;;;;;;;;;;

TITLE Task4
INCLUDE Irvine32.inc 

.data
col BYTE "Red",0
varA WORD 12 
varB WORD 2
varC WORD 13
varD WORD 8 
varE WORD 14

.code 
main PROC
mov ax , varA
mov bx , varB
mov cx , varC
mov dx , varD
mov si , varE

call DumpRegs
mov edx, offset col
call writestring

exit
main ENDP
END main

;;;;;;;;;;;;;;;;;;;;;

TITLE Task5
INCLUDE Irvine32.inc 

.data
a equ 10h
b equ 15h
f equ 20h
d equ 30h

.code
main PROC
mov eax, a
mov ecx, b
add eax, ecx
mov edx, a
mov ecx, a
sub edx, ecx
sub eax, edx
add ecx, f 
add eax, ecx
mov edx, d
add eax, edx
mov ebx, eax

call DumpRegs
exit
main ENDP
END main

;;;;;;;;;;;;;;;;;;;;;

TITLE Task6
INCLUDE Irvine32.inc 

.data
a equ 00010000b
b equ 00010101b
f equ 00100000b
d equ 00110000b

.code
main PROC
mov ah, a
mov al, b
add ah, al
mov bl, a
mov al, a
sub bh, al
sub ah, bl
add al, f
add ah, al
mov bl, d
add ah, bl
mov ch, ah

call DumpRegs
exit
main ENDP
END main

;;;;;;;;;;;;;;;;;;;;;;;;;;;;

TITLE Task 7
INCLUDE Irvine32.inc

.data
Imm8 equ 20
Data1 WORD 8
Data2 WORD 15
Data3 WORD 20

.code
main PROC

movzx ebx, Data1
movzx ecx, Data2
movzx edx, Data3
mov eax, 0
add eax, Imm8
add eax, ebx
sub eax, edx
add eax, Imm8
add eax, ecx

call DumpRegs
exit
main ENDP
END main
