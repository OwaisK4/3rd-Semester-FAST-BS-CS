TITLE Task1
INCLUDE Irvine32.inc

.data
val1 SDWORD 8000d

.code
main PROC

mov eax, val1
add val1, 1

call DumpRegs
exit
main ENDP

END main

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

TITLE Task2
INCLUDE Irvine32.inc

.data

.code
main PROC

mov ax, 7FF0h
add al, 10h
add ah, 1 
add ax, 2

call DumpRegs
exit
main ENDP
END main

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

TITLE Task3
INCLUDE Irvine32.inc

.data
arr DWORD 8, 5, 1, 2, 6
tvar DWORD ?

.code
main PROC
mov eax, 0
mov ebx, 0
mov ecx, 0
mov edx, 0
mov esi, 0

mov eax, [arr+0]
mov ebx, [arr+4]
mov ecx, [arr+8]
mov edx, [arr+12]
mov esi, [arr+16]

mov tvar, ecx
mov ecx, eax
mov eax, tvar ; 1, 5, 8, 2, 6
mov tvar, edx
mov edx, ebx
mov ebx, tvar ; 1, 2, 8, 5, 6
mov tvar, esi
mov esi, ecx
mov ecx, tvar ; 1, 2, 6, 5, 8
mov tvar, edx
mov edx, ecx
mov ecx, tvar ; 1, 2, 5, 6, 8

call DumpRegs
exit
main ENDP
END main

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

TITLE Task4
INCLUDE Irvine32.inc

.data
arrayB BYTE 10, 20, 30
arrayW WORD 150, 250, 350
arrayD DWORD 600, 1200, 1800
SUM1 DWORD 0
SUM2 DWORD 0
SUM3 DWORD 0

.code
main PROC
mov eax, SUM1
add eax, DWORD PTR arrayB+0
add eax, DWORD PTR arrayW+0
add eax, arrayD+0
mov SUM1, eax
add ebx, DWORD PTR arrayB+1
add ebx, DWORD PTR arrayW+2
add ebx, arrayD+4
mov SUM2, ebx
add ecx, DWORD PTR arrayB+2
add ecx, DWORD PTR arrayW+4
add ecx, arrayD+8
mov SUM3, ecx

call DumpRegs
exit
main ENDP
END main
 
;;;;;;;;;;;;;;;;;;;;;;;;;;;

TITLE Task5
INCLUDE Irvine32.inc

.data
array1 BYTE 10, 20, 30, 40
array2 BYTE 4 DUP (?)

.code
main PROC

mov eax, 0
mov ebx, 0
mov ecx, 0
mov edx, 0

mov ah, [array1+0]
mov dl, [array2+3]
xchg dl, ah

mov bh, [array1+1]
mov cl, [array2+2]
xchg cl, bh

mov ch, [array1+2]
mov bl, [array2+1]
xchg bl, ch

mov dh, [array1+3]
mov al, [array1+0]
xchg al, dh

call DumpRegs
exit
main ENDP
END main

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

TITLE Task6
INCLUDE Irvine32.inc

.data
arr DWORD 100, 9, 8, 7, 6

.code
main PROC
mov eax, [arr+0]
sub eax, [arr+4]
sub eax, [arr+8]
sub eax, [arr+12]
sub eax, [arr+16]

call DumpRegs
exit
main ENDP
END main

;;;;;;;;;;;;;;;;;;;;;;;;;;

TITLE Task7
INCLUDE Irvine32.inc 

.data 
arrayB BYTE 60, 70, 80
arrayW WORD 150, 250, 350 
arrayD DWORD 600, 1200, 1800 

.code 
main PROC
mov eax, 0
mov ebx, 0
mov ecx, 0
mov edx, 0

mov esi, 0
mov al, arrayB[esi * TYPE arrayB]
mov edi, 2
mov bl, arrayB[edi * TYPE arrayB]
add al, bl

mov bx, arrayW[esi * TYPE arrayW]
mov cx, arrayW[edi * TYPE arrayW]
add bx, cx

mov ecx, arrayD[esi * TYPE arrayD]
mov edx, arrayD[edi * TYPE arrayD]
add ecx, edx

call DumpRegs
exit
main ENDP
END main

