TITLE Task1
INCLUDE irvine32.inc
.data

.code
main PROC
mov eax, 0
mov ebx, 1
mov ecx, 10

l1:
	mov edx, eax
	add edx, ebx
	call WriteDec
	mov eax, 0
	mov eax, ebx
	mov ebx, 0
	mov ebx, edx
	Call Crlf
loop l1

exit
main ENDP
END main

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

TITLE Task2
INCLUDE Irvine32.inc
.data
arr DWORD 8,5,1,2,6

.code
main PROC
mov edx,0
l7:
	inc edx
	cmp edx,4
	je l5
	mov esi,0
	mov ecx,4
	
	l4:
	cmp ecx,0
	je l7

mov eax,arr[esi*4]
mov ebx,arr[esi*4+4]
cmp eax,ebx
jg l3
inc esi
loop l4
	l3:
	mov arr[esi*4],ebx
	mov arr[esi*4+4],eax
	jmp l4
l5:
	mov esi,0
	mov ecx,6
	jmp l6
l6:
	cmp ecx,1
	je l8
	mov eax,arr[esi*4]
	call writedec
	call crlf
	inc esi
	loop l6
		loop l7
l8:
exit
main ENDP
END main

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

TITLE Task3
INCLUDE irvine32.inc
.data

.code
main PROC

mov eax, 1
mov ebx, 0
mov ecx, 4
mov edx, 0

l2:
add edx, 1
mov ebx, ecx
mov ecx, edx
	l1:
		call writedec
		loop l1
		call crlf
		mov ecx, ebx
loop l2

call crlf

mov edx, 5
mov ecx, 4
mov ebx, 0

l3:
sub edx, 1
mov ebx, ecx
mov ecx, edx
	l4:
		call writedec
		loop l4
		mov ecx, ebx
		call crlf
loop l3

call crlf

mov eax, 4
mov edx, 5
mov ecx, 4
mov ebx, 0

l5:
mov eax, 4
sub edx, 1
mov ebx, ecx
mov ecx, edx
	l6:
		call writedec
		sub eax, 1
	loop l6
	
	mov ecx, ebx
	call crlf
loop l5

call crlf

mov eax, 1
mov edx, 5
mov ecx, 4
mov ebx, 0

l7:
mov eax, 1
sub edx, 1
mov ebx, ecx
mov ecx, edx
	l8:
	call writedec
	add eax, 1
	loop l8
	mov ecx, ebx
	call crlf
loop l7

exit
main ENDP
END MAIN

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

TITLE Task4
INCLUDE Irvine32.inc 
.data
empID DWORD ?,?,?,?,?
empName DWORD ?,?,?,?,?
empYOB DWORD ?,?,?,?,?
empSalary DWORD ?,?,?,?,?
totalSalary DWORD ?
askID BYTE "Enter employee ID: ",0
askName BYTE "Enter employee name: ",0
askYOB BYTE "Enter year of Birth: ",0
askYS BYTE "Enter yearly salary: ",0

.code 
main PROC
mov ecx, 5
mov ebx, totalSalary
mov esi, 0
l1:
	mov edx, OFFSET askID 
	call WriteString
	call ReadInt
	mov empID[esi], eax
	mov edx, OFFSET askName
	call WriteString
	call ReadString
	mov empName[esi], eax
	mov edx, OFFSET askYOB
	call WriteString
	call ReadString
	mov empYOB[esi], eax
	mov edx, OFFSET askYS
	call WriteString
	call ReadInt
	mov empSalary[esi], eax
	add ebx, eax
	call Crlf
	add esi, 4
loop l1

call Crlf
mov eax, ebx
call WriteDec

exit
main ENDP
END main

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

TITLE Task5
INCLUDE Irvine32.inc 
.data
source BYTE "Hello World",0
target BYTE SIZEOF source DUP(0),0

.code 
main PROC
mov ecx, SIZEOF source
mov esi, 0

l1:
	mov al, source[esi]
	mov target[esi],al
	call WriteChar
	add esi, 1
loop l1

exit
main ENDP
END main

;;;;;;;;;;;;;;;;;;;;;;;;;;;

TITLE Task6
INCLUDE irvine32.inc
.data
arr DWORD 10,20,30,40

.code
main PROC
mov ecx, lengthof arr/2
mov esi, 0
mov ebx, lengthof arr
sub ebx, 1

l1:
	mov eax, arr[esi * TYPE arr]
	mov edx, arr[ebx * TYPE arr]
	xchg eax, edx
	mov arr[esi * TYPE arr], eax
	mov arr[ebx * TYPE arr], edx
	inc esi
	sub ebx, 1
loop l1

mov ecx, lengthof arr
mov esi, 0

l2:
	mov eax, arr[esi *TYPE arr]
	call writedec
	call crlf
	inc esi
loop l2

exit
main ENDP
END main