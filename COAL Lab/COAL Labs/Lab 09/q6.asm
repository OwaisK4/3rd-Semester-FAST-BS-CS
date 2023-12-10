TITLE Question 6
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
first QWORD 0000FFFFFFFFFFFFh
second QWORD 0000EEEEEEEEEEEEh

.code
main PROC
push DWORD PTR second
push DWORD PTR second + 4
push DWORD PTR first
push DWORD PTR first + 4
call Extended_Add
exit
main ENDP

Extended_Add PROC ; Returns value in esi:eax:ebx with final carry in esi
mov eax, [esp + 4] ; 0000FFFF
mov ebx, [esp + 8] ; FFFFFFFF
mov ecx, [esp + 12] ; 0000EEEE
mov edx, [esp + 16] ; EEEEEEEE
mov esi, 0
call DumpRegs

add ebx, edx
adc eax, ecx
adc esi, 0
;adc eax, ebx

call Crlf
mWrite "Sum of 64-bit integers: "
xchg eax, esi
call WriteHex
xchg eax, esi
call WriteHex
xchg eax, ebx
call WriteHex
call Crlf

ret
Extended_Add ENDP
END main