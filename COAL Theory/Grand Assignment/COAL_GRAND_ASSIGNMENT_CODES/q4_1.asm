TITLE Question 4(i)
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
Sequence_Number DWORD 0
Revision_Count DWORD 0
Status DWORD 0
Sensor_Data DWORD 0

.code
main PROC
mov ebx, eax
AND ebx, 0FFFh
mov Sequence_Number, ebx
mov ebx, eax
shr ebx, 12
AND ebx, 111b
mov Revision_Count, ebx
mov ebx, eax
shr ebx, 15
AND ebx, 1b
mov Status, ebx
mov ebx, eax
shr ebx, 16
AND ebx, 0FFFFh
mov Sensor_Data, ebx

mWrite "EAX: "
call WriteBin
call Crlf
mWrite "Sequence_Number: "
mov eax, Sequence_Number
call WriteBin
call Crlf
mWrite "Revision_Count: "
mov eax, Revision_Count
call WriteBin
call Crlf
mWrite "Status: "
mov eax, Status
call WriteBin
call Crlf
mWrite "Sensor_Data: "
mov eax, Sensor_Data
call WriteBin
call Crlf

exit
main ENDP
END main