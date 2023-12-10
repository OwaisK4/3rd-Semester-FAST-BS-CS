Include Irvine32.inc

.data
bufferSize = 100
buffer BYTE bufferSize DUP(?)
filename BYTE "MyFile.txt", 0
fileHandle HANDLE ?
prompt BYTE "Enter string: ", 0

.code
main PROC
mov edx, OFFSET filename
call OpenInputFile
mov fileHandle, eax

mov edx, OFFSET buffer
mov ecx, bufferSize
call ReadFromFile
mov buffer[eax], 0

mov edx, OFFSET buffer
call WriteString

call CloseFile
exit
main ENDP
END main