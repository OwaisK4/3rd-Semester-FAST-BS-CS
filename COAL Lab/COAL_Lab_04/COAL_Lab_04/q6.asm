TITLE Question 6
INCLUDE Irvine32.inc

.data
array DWORD 100, 200, 300, 400, 500
value DWORD 20

.code
main PROC
mov ecx, 5
mov esi, 0
Print_before:
	mov eax, [array + esi]
	call writeint
	add esi, TYPE DWORD
	loop Print_before

mov esi, 0
mov eax, value

sub [array + esi], eax
add esi, TYPE DWORD

sub [array + esi], eax
add esi, TYPE DWORD

sub [array + esi], eax
add esi, TYPE DWORD

sub [array + esi], eax
add esi, TYPE DWORD

sub [array + esi], eax
add esi, TYPE DWORD

call DumpRegs

mov ecx, 5
mov esi, 0
Print_after:
	mov eax, [array + esi]
	call writeint
	add esi, TYPE DWORD
	loop Print_after

exit
main ENDP
END main