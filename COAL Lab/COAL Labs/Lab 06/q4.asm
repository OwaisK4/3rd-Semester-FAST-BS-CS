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
call CreateOutputFile
mov fileHandle, eax

mov edx, OFFSET prompt
call WriteString
mov edx, OFFSET buffer
mov ecx, bufferSize
call ReadString

mov eax, fileHandle
mov edx, OFFSET buffer
mov ecx, bufferSize
call WriteToFile
call CloseFile

exit
main ENDP
END main