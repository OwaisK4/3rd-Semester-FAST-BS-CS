TITLE Task1
Include Irvine32.inc

.data
gen BYTE "Generating 20 random integers between 0 and 990", 0

.code 
main proc 
call Randomize
call Clrscr
mov edx, OFFSET gen
call WriteString
call Crlf

mov dh, 1
mov dl, 0
mov ecx, 20

l2:
	call Gotoxy
	mov eax, 50
	call Delay
	add dh, 1
	mov eax, 990
	call RandomRange
	add dl, 1
	call WriteDec
	call Crlf
loop l2

exit

;;;;;;;;;;;;;;;;;;;;;;;;

TITLE Task2
Include Irvine32.inc

.data

.code 
main proc
call Randomize
mov ecx, 100

l2:
	mov eax, 0FFFFh
	call RandomRange
	mov dh, ah
	mov dl, al
	call Gotoxy
	
	mov eax, 100h
	call RandomRange
	call WriteDec
	mov eax, 100
	call Delay
	
loop l2

exit
main ENDP 
END main

;;;;;;;;;;;;;;;;;;;;;;;

TITLE Task3
Include Irvine32.inc

.data
msg32 BYTE "Printing 0 to 4,294,967,294 ranged values", 0
msg BYTE "Printing -50 to +49 ranged values", 0

.code 
main PROC
call Randomize

mov edx, OFFSET msg32
call WriteString
call Crlf
mov ecx, 10
l1:
	call Random32
	call WriteDec
	call Crlf
loop l1

call Crlf
mov edx, OFFSET msg
call WriteString
call Crlf
mov ecx, 10
l2:
	mov eax, 100d
	call RandomRange
	sub eax, 50d
	call WriteInt
	call Crlf
loop l2

exit
main ENDP 
END main

;;;;;;;;;;;;;;;

TITLE Task4
INCLUDE Irvine32.inc

BUFFER_SIZE = 100

.data
message BYTE BUFFER_SIZE DUP(?)
f_handle HANDLE ?
f_name BYTE "test.txt",0
str_len DWORD ?
msg1 BYTE "Enter your message you want to store in the file: ", 0

.code
main PROC

; create a file
mov edx, OFFSET f_name
Call CreateOutputFile
mov f_handle, eax

; ask user to enter a message
mov edx, OFFSET msg1 ; edx = output
Call WriteString
mov ecx, BUFFER_SIZE
mov edx, OFFSET message
Call ReadString
mov str_len, eax

; Writing to a file
mov eax, f_handle
mov edx, OFFSET message
mov ecx, str_len
Call WriteToFile

; Close the file as there are no further operations to perform
Call CloseFile

exit
main ENDP
END main

;;;;;;;;;;;;;;;;;;;;

.data
buffer BYTE BUFFER_SIZE DUP(?)
filename BYTE 80 DUP(0)
fileHandle HANDLE ?

.code
main PROC
; Let user input a filename.
mWrite "Enter an input filename: " 
mov edx,OFFSET filename
mov ecx,SIZEOF filename 
call ReadString
; Open the file for input. 
mov edx,OFFSET filename 
call OpenInputFile
mov fileHandle,eax
; Read the file into a buffer.
mov edx,OFFSET buffer 
mov ecx,BUFFER_SIZE 
call ReadFromFile
mov buffer[eax],0 ; insert null terminator mWrite "File size: "
call WriteDec ; display file size 
call Crlf
; Display the buffer.
mWrite <"Buffer:",0dh,0ah,0dh,0ah>
mov edx,OFFSET buffer ; display the buffer call WriteString
call Crlf
mov eax,fileHandle 
call CloseFile
exit
main ENDP 
END main
