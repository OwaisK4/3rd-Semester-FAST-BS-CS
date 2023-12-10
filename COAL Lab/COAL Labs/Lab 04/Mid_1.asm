TITLE Practice MIDS
INCLUDE Irvine32.inc

.data
x1 WORD	8F7Ah, 7AF8h
x2 WORD 0000h
wArray SWORD 1,-2,7,-6,15,-12,25,-20,37,-30

.code
main PROC
MOV ECX, 5
MOV ESI, OFFSET [wArray+2]
L1:
	call DumpRegs
	NEG WORD PTR [ESI]
	ADD ESI,4
	LOOP L1

call DumpRegs
exit
main ENDP
END main

;mov eax, 0
;mov ebx, 0
;mov ax, x1
;add ax, [x1 + 2]
;call DumpRegs

;mov esi, OFFSET x2
;mov bx,	[esi]
;sub bx, 1
;call DumpRegs