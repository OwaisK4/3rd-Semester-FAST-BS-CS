TITLE Add and Subtract Task 1
INCLUDE Irvine32.inc

.data
V1 equ 47d
V2 equ 39d
V3 equ 60d
V4 equ 85d
V5 equ 64d
V6 equ 54o
V7 equ 0Ah

.code
main PROC
mov eax, V1
add eax, V2
add eax, V3
add eax, V4
add eax, V5
add eax, V6
sub eax, V7

call DumpRegs
exit
main ENDP
END main

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

TITLE Add and Subtract Task 2
INCLUDE Irvine32.inc

.data
V1 equ 30d
V2 equ 9d
V3 equ 186d
V4 equ 150d

.code
main PROC
mov eax, V1
sub eax, V2
add eax, V3
sub eax, V4

call DumpRegs
exit
main ENDP
END main 

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

TITLE Add and Subtract Task 3
INCLUDE Irvine32.inc

.data
V1 equ 101110b
V2 equ 50Ah
V3 equ 6710d
V4 equ 1010001b
V5 equ 'F'

.code
main PROC
mov eax, V1
add eax, V2
add eax, V3
add eax, V4
add eax, V5 

call DumpRegs
exit
main ENDP
END main

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

TITLE Add and Subtract Task 4
INCLUDE Irvine32.inc

.data
V1 equ 101110b
V2 equ 0D83h
V3 equ 385d
V4 equ 10d
V5 equ 1111101b
V6 equ 'E'
V7 equ 'F'

.code
main PROC
mov eax, V1
sub eax, V2
add eax, V3
add eax, V4
add eax, V5
sub eax, V6
add eax, V7

call DumpRegs
exit
main ENDP
END main

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

TITLE Add and Subtract Task 5
INCLUDE Irvine32.inc

.data
V1 equ 1d
V2 equ OAh
V3 equ 65o
V4 equ 73d

.code
main PROC
mov edx, 0 
mov eax, 0Ah
mov ebx, 65o
mov ecx, 73d
sub edx, eax
mov eax, edx 
add eax, V1
add eax, ebx
add eax, edx
sub eax, ecx
add eax, 0Ah
sub eax, 65o
add eax, 73d
mov edx, eax

call DumpRegs
exit
main ENDP
END main

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

TITLE Add and Subtract Task 6
INCLUDE Irvine32.inc

.data
V1 equ 150d
V2 equ 11110111d
V3 equ 65d
V4 equ 65o

.code
main PROC
mov edx, 0 
mov eax, 5ADh
sub edx, eax 
mov eax, edx
add eax, V4
add eax, V3
add eax, V1
sub eax, V2
add eax, 5ADh

call DumpRegs
exit
main ENDP
END main
