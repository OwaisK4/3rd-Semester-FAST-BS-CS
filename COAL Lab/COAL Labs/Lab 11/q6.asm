TITLE Question 6
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
global_target BYTE "AAEBDCFBBC",0
global_freqTable DWORD 256 DUP(0)

.code
main PROC
Get_frequencies PROTO, target:PTR DWORD, freqTable:PTR DWORD
Print_Frequencies PROTO, target:PTR DWORD, freqTable:PTR DWORD
INVOKE Get_frequencies, ADDR global_target, ADDR global_freqTable
INVOKE Print_frequencies, ADDR global_target, ADDR global_freqTable
exit
main ENDP

Get_frequencies PROC, target:PTR DWORD, freqTable:PTR DWORD
mov esi, target
mov edi, freqTable
INVOKE STR_LENGTH, target
mov ecx, eax
L1:
	mov eax, 0
	mov al, [esi]
	inc DWORD PTR [edi + eax*4]
	inc esi
	loop L1
ret
Get_frequencies ENDP

Print_Frequencies PROC, target:PTR DWORD, freqTable:PTR DWORD
mov esi, target
mov edi, freqTable
INVOKE STR_LENGTH, target
mov ecx, eax
mWrite "Target String: "
L1:
	mov eax, 0
	mov al, [esi]
	inc esi
	call WriteChar
	mWrite " "
	loop L1

call Crlf
mWrite "ASCII Code: "
mov esi, target
INVOKE STR_LENGTH, target
mov ecx, eax
L2:
	mov eax, 0
	mov al, [esi]
	inc esi
	call WriteDec
	mWrite " "
	loop L2

call Crlf
call Crlf
mWrite "Frequency Table: "
mov edi, freqTable
mov ecx, 256
L3:
	mov eax, [edi]
	cmp eax, 0
	je zero_freq
	call WriteDec
	mWrite " "
	zero_freq:
		add edi, 4
		loop L3

call Crlf
mWrite "Index: "
mov edi, freqTable
mov ecx, 256
L4:
	mov eax, [edi]
	cmp eax, 0
	je zero_freq2
	mov eax, edi
	sub eax, freqTable ; reverse of inc DWORD PTR [edi + eax*4]
	mov edx, 0
	mov ebx, 4 ; Since freqTable is of type DWORD
	div ebx
	call WriteDec
	mWrite " "
	zero_freq2:
		add edi, 4
		loop L4

call Crlf
ret
Print_frequencies ENDP
END main