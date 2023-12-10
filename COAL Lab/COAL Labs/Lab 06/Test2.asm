Include Irvine32.inc
.data
myInt DWORD ?
myChar BYTE ?
myStr BYTE 30 dup (0)
myPrompt BYTE "Enter a string: ",0
myPrompt2 BYTE "Enter a number: ",0

.code
main PROC
; Output 2 random numbers
call Randomize ; Only call randomize once
call Random32
call WriteInt ; output EAX as int
call Crlf
call RandomRange
call WriteInt ; output EAX as int
call Crlf

; Get and display a string
mov edx, offset myprompt
call Writestring ; Display prompt
mov ecx, 30 ; Max length of 30
mov edx, offset myStr
call Readstring
call Writestring ; Output what was typed
Call Crlf

; Get a number and display it
mov edx, offset myprompt2
call Writestring ; Display prompt
call ReadInt ; Int stored in EAX
call WriteInt
call Crlf
exit
main endp
end main