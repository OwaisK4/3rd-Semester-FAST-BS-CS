TITLE Prime_Double
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
w_array WORD 1, 3, 4, 6, 7, 8, 11, 13, 19, 21
array_size DWORD LENGTHOF w_array
multiplier DWORD 2
PrimeDouble PROTO, array:PTR WORD, count:DWORD

.code
main PROC
INVOKE PrimeDouble, ADDR w_array, array_size
mov ecx, array_size
mov esi, OFFSET w_array
PRINT:
	movzx eax, WORD PTR [esi]
	call WriteDec
	mWrite " "
	add esi, TYPE w_array
	loop PRINT
call Crlf
exit
main ENDP

PrimeDouble PROC, array:PTR WORD, count:DWORD
mov ecx, count
mov esi, array
L1:
	mov bx, 2
	mov ax, WORD PTR [esi]
	L2:
		cmp bx, ax
		JGE PRIME_TRUE
		push ax
		mov dx, 0
		div bx
		pop ax
		cmp dx, 0
		JNE END_INNER
		jmp END_OUTER
		PRIME_TRUE:
			mWrite "Prime"
			call Crlf
			mov dx, 0
			mul multiplier
			mov WORD PTR [esi], ax
			jmp END_OUTER
		END_INNER:
			inc bx
			jmp L2
	END_OUTER:
		add esi, 2
		loop L1
ret
PrimeDouble ENDP

END main