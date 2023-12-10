TITLE Filing_test
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
bufferSize = 5000
buffer BYTE bufferSize DUP(?)
filehandle HANDLE ?
filename BYTE "input.txt", 0
bytesRead DWORD ?
answer_array DWORD 11 DUP(0)

q1c_size = 90
q1c BYTE 91 DUP(?)
q2c_size = 183
q2c BYTE 184 DUP(?)
q3c_size = 151
q3c BYTE 152 DUP(?)
q4c_size = 220
q4c BYTE 221 DUP(?)
q5c_size = 99
q5c BYTE 100 DUP(?)
q6c_size = 179
q6c BYTE 180 DUP(?)
q7c_size = 75
q7c BYTE 76 DUP(?)
q8c_size = 95
q8c BYTE 96 DUP(?)
q9c_size = 115
q9c BYTE 116 DUP(?)
q10c_size = 102
q10c BYTE 103 DUP(?)
addresses DWORD 11 DUP(?)
;finalSize = 92, 185, 422, 640, 737, 918, 997, 1094, 1211, 1315

Level3_Print PROTO, questions:PTR DWORD, answers:PTR DWORD

.code
main PROC
cld
mov edx, OFFSET filename
call OpenInputFile
mov filehandle, eax

mov edx, OFFSET buffer
mov ecx, bufferSize
call ReadFromFile
mov bytesRead, eax

mov ecx, q1c_size
mov esi, OFFSET buffer
mov edi, OFFSET q1c
rep movsb
mov q1c[91], 0
mov addresses[1 * TYPE addresses], OFFSET q1c

mov ecx, q2c_size
add esi, 2
mov edi, OFFSET q2c
rep movsb
mov q2c[184], 0
mov addresses[2 * TYPE addresses], OFFSET q2c

mov ecx, q3c_size
add esi, 2
mov edi, OFFSET q3c
rep movsb
mov q3c[152], 0
mov addresses[3 * TYPE addresses], OFFSET q3c

mov ecx, q4c_size
add esi, 2
mov edi, OFFSET q4c
rep movsb
mov q4c[221], 0
mov addresses[4 * TYPE addresses], OFFSET q4c

mov ecx, q5c_size
add esi, 2
mov edi, OFFSET q5c
rep movsb
mov q5c[100], 0
mov addresses[5 * TYPE addresses], OFFSET q5c

mov ecx, q6c_size
add esi, 2
mov edi, OFFSET q6c
rep movsb
mov q6c[180], 0
mov addresses[6 * TYPE addresses], OFFSET q6c

mov ecx, q7c_size
add esi, 2
mov edi, OFFSET q7c
rep movsb
mov q7c[76], 0
mov addresses[7 * TYPE addresses], OFFSET q7c

mov ecx, q8c_size
add esi, 2
mov edi, OFFSET q8c
rep movsb
mov q8c[96], 0
mov addresses[8 * TYPE addresses], OFFSET q8c

mov ecx, q9c_size
add esi, 2
mov edi, OFFSET q9c
rep movsb
mov q9c[116], 0
mov addresses[9 * TYPE addresses], OFFSET q9c

mov ecx, q10c_size
add esi, 2
mov edi, OFFSET q10c
rep movsb
mov q10c[103], 0
mov addresses[10 * TYPE addresses], OFFSET q10c

mWrite "Total bytes in file: "
call WriteDec
call Crlf
call Crlf

INVOKE Level3_Print, ADDR addresses, ADDR answer_array

exit
main ENDP

Level3_Print PROC, questions:PTR DWORD, answers:PTR DWORD
mov ecx, 10
mov esi, questions
mov edi, answers
add esi, 4
add edi, 4
L1:
	mov edx, [esi]
	call WriteString
	call Crlf
	call ReadDec
	mov [edi], eax
	call Crlf
	add esi, 4
	add edi, 4
	loop L1
ret
Level3_Print ENDP
END main