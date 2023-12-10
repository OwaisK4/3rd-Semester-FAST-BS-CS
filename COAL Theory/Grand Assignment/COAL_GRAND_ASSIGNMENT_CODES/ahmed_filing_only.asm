INCLUDE Irvine32.inc
INCLUDE Macros.inc

fputs PROTO

.Data
fileHandle HANDLE ?
total DWORD 69420      ;total is a variable which holding a math calc output
buffer BYTE 100 DUP(0)
totalTXT BYTE " Hello World",0
fname BYTE "file.txt",0

 .code
 main PROC
 mov eax, 0
 mov eax, total
 mov totalTXT, al
 mov ecx, 5
 mov esi, OFFSET total
 mov edi, OFFSET buffer
 mov ebx, 10
 L1:
	mov edx, 0
	mov eax, [esi]
	div ebx
	add dl, 30h
	mov BYTE PTR [edi], dl
	mov [esi], eax
	add esi, 1
	add edi, 1
	loop L1
mov BYTE PTR [edi], 0

 Call WRITE_TO_FILE
 exit
 main ENDP

 WRITE_TO_FILE proc               ;assume file is successfully opened
 mov edx, OFFSET fname
 call CreateOutputFile
 mov fileHandle, eax

 mov eax,fileHandle 
 ;mov edx, OFFSET   totalTXT
 ;mov edx, OFFSET total
 ;mov ecx, LENGTHOF total
 mov edx, OFFSET buffer
 mov ecx, 100
 
 Call WriteToFile
 Call CloseFile

 ret
  WRITE_TO_FILE endp 
 END main