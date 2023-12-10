include irvine32.inc

.data

array DWORD 1,2,3,4,5,6,7,8,9,10

 addSum proto ,var1:ptr dword,var2:BYTE

.code
main proc
mov eax,0
mov al,10d
mov bl,20d
invoke addSum, addr array,10d
exit
main endp

addSum proc, var1:ptr dword,var2:byte

movzx ecx,var2
mov esi,var1
l2:
mov eax,[esi]
call writeint
add esi,4
loop l2
ret
addSum ENDP
END Main