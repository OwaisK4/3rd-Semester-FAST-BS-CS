TITLE Practice MIDS
INCLUDE Irvine32.inc

.data
source DWORD 1,2,3,4,5,6,7,8,9,10
dest DWORD LENGTHOF source DUP(0)

.code
main PROC
mov eax, 0
mov ecx, LENGTHOF source
mov esi, 0
L1:
	mov eax, source[esi]
	mul eax
	mov dest[esi], eax
	add esi, TYPE source
	loop L1

call DumpRegs
call CRLF

mov eax, 0
mov ecx, LENGTHOF dest
mov esi, 0
L2:
	mov eax, dest[esi]
	call writeInt
	add esi, TYPE dest
	loop L2
exit
main ENDP
END main