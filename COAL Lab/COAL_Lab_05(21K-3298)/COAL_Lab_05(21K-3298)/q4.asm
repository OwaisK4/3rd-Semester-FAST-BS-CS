INCLUDE Irvine32.inc

.data
stringSize = 10
TotalSalary DWORD 0
Employee DWORD ?, stringSize DUP(0), 0, ?, ?
		DWORD ?, stringSize DUP(0), 0, ?, ?
		DWORD ?, stringSize DUP(0), 0, ?, ?
		DWORD ?, stringSize DUP(0), 0, ?, ?
		DWORD ?, stringSize DUP(0), 0, ?, ?

ID BYTE "Enter ID of Employee: ", 0
ID_2 = ID + 6

EmpName BYTE "Enter Name of Employee: ", 0
EmpName_2 = EmpName + 6

Year BYTE "Enter Year of Employee: ", 0
Year_2 = Year + 6

Salary BYTE "Enter Salary of Employee: ", 0
Salary_2 = Salary + 6
Salary_3 BYTE "Total Salary of all employees: ", 0


.code
main PROC
mov eax, 0
mov esi, 0
mov ecx, 5
INPUT:
	mov edx, OFFSET ID
	call WriteString
	call ReadInt
	mov Employee[esi], eax
	add esi, TYPE Employee

	mov edx, OFFSET EmpName
	call WriteString
	mov edx, OFFSET Employee
	add edx, esi
	push ecx
	mov ecx, stringSize
	call ReadString
	pop ecx
	add esi, stringSize * TYPE Employee

	mov edx, OFFSET Year
	call WriteString
	call ReadInt
	mov Employee[esi], eax
	add esi, TYPE Employee

	mov edx, OFFSET Salary
	call WriteString
	call ReadInt
	mov Employee[esi], eax
	add TotalSalary, eax
	add esi, TYPE Employee
	call Crlf
loop INPUT


mov esi, 0
mov ecx, 5
PRINT:
	mov edx, OFFSET ID_2
	call WriteString
	mov eax, Employee[esi]
	call WriteDec
	call Crlf
	add esi, TYPE Employee

	mov edx, OFFSET EmpName_2
	call WriteString
	mov edx, OFFSET Employee
	add edx, esi
	call WriteString
	call Crlf
	add esi, 10 * TYPE Employee

	mov edx, OFFSET Year_2
	call WriteString
	mov eax, Employee[esi]
	call WriteDec
	call Crlf
	add esi, TYPE Employee

	mov edx, OFFSET Salary_2
	call WriteString
	mov eax, Employee[esi]
	call WriteDec
	call Crlf
	call Crlf
	add esi, TYPE Employee
loop PRINT

mov edx, OFFSET Salary_3
call WriteString
mov eax, TotalSalary
call WriteDec
call Crlf

exit
main ENDP
END main