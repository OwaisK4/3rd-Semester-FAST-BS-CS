INCLUDE Irvine32.inc

BUFFER_SIZE = 1000

.data

;;;;;;;;;;;;;;;;;;;;;;;;; BABAR'S WORK DATA ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

binaryNumber BYTE 33 DUP(?) ; 32 characters for 32-bit Binary 
  NumberLength DWORD 0
  base DWORD 2 ; Base of Binary Number
  DecimalNumber DWORD ?

  OuterLoopCount DWORD 0
  msgBinary BYTE " Enter only Binary pls : ",0 ; A null-terminated string
  msgDecimalNumber BYTE " Decimal = ",0
  msgHexNumber BYTE " Hexadecimal = ",0

  msgNotBinary BYTE " Invalid Binary can contain only 0's and 1's",0

;;;;;;;;;;;;;;;;;;;;;;; FILING DATA ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

buffer BYTE BUFFER_SIZE DUP(0)
h_array DWORD 3 DUP(?)
f_handle HANDLE ?
f_name BYTE "test.txt",0
str_len DWORD ?

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.code
main PROC

call Binary_Convert
call filing

exit
main ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

Binary_Convert PROC
    call Crlf                            
    mov edx, OFFSET msgBinary
    call WriteString

    mov edx,OFFSET binaryNumber
    mov ecx,SIZEOF binaryNumber ; length of binaryNumber
    call ReadString ; Reads a string 
    mov NumberLength,eax ; Number of characters read

  ; Find Decimal Number

    mov eax,0
    mov esi,0 ; ESI initialize with zero
    mov ecx, NumberLength ; ECX initialize with length of Number
    whilePart:
        cmp ecx,0 ; Compare ECX and 0
        je displayNumbers ; Jump if number is 0
        mov OuterLoopCount,ecx         

    ifPart:
        cmp binaryNumber[esi],'0' ; Compare binaryNumber[esi] and '0'
        je IncEsi ; jump if equal (==)
        ;Multiplying by zero, equal to zero. do nothing in this case

    elseIfPart:
        cmp binaryNumber[esi],'1' ; Compare binaryNumber[esi] and '1'
        jne elsePart ; if not equal then it is invalid.in other words it is neither 0 nor 1

   ;Calculate pow(base, NumberLength -ESI-1) and add them to eax

   mov ecx, NumberLength
   sub ecx,esi
   dec ecx

   ; Calculate Power
   mov eax,1 ; EAX initialize with 1
   whilePart2:
    cmp ecx,0 ; Compare ECX and 0
    je stop ; jump if equal (==)

    ; Multiply EAX and EBX and save result in EAX
    mov ebx,base
    mul ebx
    dec ecx
   jmp whilePart2
   ; Calculate Power finish

   stop:
    add DecimalNumber,eax
    mov edi, DecimalNumber
   jmp IncEsi

    mov h_array[0], edi

  elsePart:
   mov edx, OFFSET msgNotBinary ; " Invalid Binary Number, Binary Number Contains only 0's or 1's"
   call WriteString
   call Crlf       
   call WaitMsg ; Displays a message and waits for a key to be pressed.
   exit ; exit program

 IncEsi:
  inc esi
  mov ecx,OuterLoopCount 
  dec ecx
  jmp WhilePart

 displayNumbers:
  mov edx, OFFSET msgDecimalNumber
  call WriteString
  
  call Display_Decimal
  call Crlf                            
                 
  mov edx, OFFSET msgHexNumber
  call WriteString
  

 call Display_Hexadecimal
 call Crlf
 call WaitMsg    
 exit   
 Binary_Convert ENDP

 Display_Decimal PROC
    mov edx, 0
    mov eax, DecimalNumber
    mov h_array[4], eax
    call WriteDec
    call crlf
Display_Decimal ENDP

 Display_Hexadecimal PROC
    mov edx, 0
    mov eax, DecimalNumber
    mov h_array[8], eax
    call WriteHex
 Display_Hexadecimal ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;; FILING PROCDEURE ;;;;;;;;;;;;;;;;;;;;;;;;;;

filing PROC

; create a file
mov edx, OFFSET f_name
Call CreateOutputFile
mov f_handle, eax

; ask user to enter a message
mov ecx, BUFFER_SIZE
mov edx, OFFSET h_array
mov str_len, eax

mov ecx, 32
mov esi, OFFSET h_array
mov edi, OFFSET buffer
DWORD_TO_BYTE:
    mov al, BYTE PTR [esi]
    mov BYTE PTR [edi], al
    inc esi
    inc edi
    loop DWORD_TO_BYTE

; Writing to a file
mov eax, f_handle
mov edx, OFFSET buffer
;mov edx, OFFSET h_array
;mov ecx, str_len
mov ecx, BUFFER_SIZE
Call WriteToFile

; Close the file as there are no further operations to perform
Call CloseFile

ret

filing ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
END main