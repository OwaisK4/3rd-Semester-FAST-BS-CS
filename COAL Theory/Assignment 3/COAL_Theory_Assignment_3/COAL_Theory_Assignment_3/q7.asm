TITLE Question 7
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
;first DWORD 0FFFFFFFFh, 0FFFFFFFFh, 0FFFFFFFFh, 0000FFFFh
;second DWORD 0EEEEEEEEh, 0EEEEEEEEh, 0EEEEEEEEh, 0000EEEEh
first DWORD 00000000h, 00000000h, 00000000h, 00009999h
second DWORD 00000000h, 00000000h, 00000000h, 00008888h
len DWORD 4			; 32 bits = 4, 4x4 = 16
diff DWORD 5 DUP(0)

.code
main PROC
push len
push OFFSET second
push OFFSET first
call Extended_Sub
mov esi, OFFSET diff
mov ecx, len
L2:
	mov eax, [esi]
	;call WriteDec
	call WriteHex
	mWrite " "
	add esi, 4
	loop L2
call Crlf
exit
main ENDP

Extended_Sub PROC, num1:PTR DWORD, num2:PTR DWORD, count:DWORD ; Subtracts num2 from num1
mov esi, num1
mov edi, num2
mov ebx, OFFSET diff
mov ecx, count
clc
L1:
	mov eax, [esi]
	sbb eax, [edi]
	pushfd
	mov [ebx], eax
	add esi, 4
	add edi, 4
	add ebx, 4
	popfd
	loop L1
sbb DWORD PTR [ebx], 0
ret
Extended_Sub ENDP

END main