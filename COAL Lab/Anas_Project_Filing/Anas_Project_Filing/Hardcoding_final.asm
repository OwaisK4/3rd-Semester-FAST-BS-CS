TITLE My First Project   
INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
bufferSize = 5000
buffer BYTE bufferSize DUP(?)
filehandle HANDLE ?
filename BYTE "input.txt", 0
bytesRead DWORD ?

BUFFER_SIZE = 501
;buffer BYTE 40 DUP(?),0dh,0ah
;bufSize DWORD ($-buffer)
errMsg BYTE "Cannot open file",0dh,0ah,0
;filename     BYTE "output.txt",0
;fileHandle   HANDLE ?			; handle to output file
bytesWritten DWORD ?    			; number of bytes written   ;File VAriables
quesL1 DWORD 10 DUP(?)
quesL2 DWORD 10 DUP(?)
quesL3 DWORD 10 DUP(?)			;QUESTION ADDRESSES
player BYTE "Enter Player Name: ",0
spaces1 BYTE "                                                                      ",0
arr1 BYTE 1,4,2,2,3,3,1,2,4,3
arr2 BYTE 2,4,3,1,2,2,1,1,1,4
arr3 BYTE 3,4,3,2,4,1,1,1,2,3		;ANSWERS
name1 BYTE 10 DUP(?)
scoreL1 BYTE ?  
scoreL2 BYTE ?  
scoreL3 BYTE ?						;SCORE OF EACH LEVEL 
msg1 BYTE "YOUR LEVEL 1 SCORE: ",0
msg3 BYTE "YOUR LEVEL 2 SCORE: ",0
msg4 BYTE "YOUR LEVEL 3 SCORE: ",0
string1 BYTE "Excellent IQ LEVEL",0
string2 BYTE "FAIR IQ LEVEL ",0
string3 BYTE "POOR IQ LEVEL",0				;IQ STAGING
string4 BYTE 'C','O','N','G','R','A','T','U','L','A','T','I','O','N',' ','L','E','V','E','L',' ','P','A','S','S','E','D',0	;REWARD
string5 BYTE "    QUIZ/INTELLIGENCE GAME",0
string6 BYTE "         PROJECT BY",0dh,10,"                                                                          Muhammad Anas 21K-4556",0dh,10,"                                                                        Muhammad Shaheer  21K-3323",13,10," ",13,0
string7 BYTE "PRESS ANY KEY TO CONTINUE!!!!",0
QuizScore BYTE "YOUR QUIZ SCORE: ",0
finalmsg BYTE "YOUR IQ LEVEL: ",0
Opt BYTE "WHAT DO YOU WANT ? ",0ah,"1: PLAY A QUIZ GAME ",0ah,"2: CALCULATE YOUR IQ ",0ah,"Enter choice: ",0
life BYTE 5		;LIFE FOR PLAYER ONLY IN OPT QUIZ
TotalScore WORD ?
count DWORD 27
QLEVEL3 PROTO, ques3:PTR DWORD, scor3:BYTE
QLEVEL2 PROTO, ques:PTR DWORD, lev2q:PTR BYTE,scor2:BYTE
QLEVEL1 PROTO, quesA:PTR DWORD, lev1q:PTR BYTE,scor:BYTE		;QUIZ FUNCTIONS
LEVEL1 PROTO, quesA:PTR DWORD, lev1q:PTR BYTE,scor:BYTE
LEVEL2 PROTO, ques:PTR DWORD, lev2q:PTR BYTE,scor2:BYTE
LEVEL3 PROTO, questions:PTR DWORD, scor3:BYTE		;IQ FUNCTIONS

q1c_size = 90
q1c BYTE 91 DUP(?)
q2c_size = 182
q2c BYTE 183 DUP(?)
q3c_size = 149
q3c BYTE 150 DUP(?)
q4c_size = 216
q4c BYTE 217 DUP(?)
q5c_size = 95
q5c BYTE 96 DUP(?)
q6c_size = 179
q6c BYTE 180 DUP(?)
q7c_size = 77
q7c BYTE 78 DUP(?)
q8c_size = 95
q8c BYTE 96 DUP(?)
q9c_size = 115
q9c BYTE 116 DUP(?)
q10c_size = 102
q10c BYTE 103 DUP(?)
qC_addresses DWORD 10 DUP(?)
;finalSize = 92, 185, 422, 640, 737, 918, 997, 1094, 1211, 1315

;////////Shaheer LEVEL 2 QUESTION
Level2Q BYTE "Q1).What will be the next number in series 39,42,48,? ",0ah,"1) 59" ,0ah,"2) 60",0ah,"3) 82",0ah,"4) 23",0  
	q1A=($-Level2Q)
		BYTE "Q2).What number comletes best analogy: 8:4 as 10:",0ah,"1) 30",0ah,"2) 2",0ah,"3) 24",0ah,"4) 5",0
    q2A=($-Level2Q-q1A)
		BYTE "Q3).A bat and a ball together cost $1.10. The bat costs $1 more than the ball. How much does the ball cost?",0ah,"1) 3 cents",0ah,"2) 4 cents ",0ah,"3) 5 cents ",0ah,"4) 6 cents",0 ;5    13
    q3A=($-Level2Q-q1A-q2A)
		 BYTE "Q4).If it takes 5 machines 5 minutes to make 5 widgets, how long would it take 100 machines to make 100 widgets?",0ah,"1) 5 minutes",0ah,"2) 10 minutes",0ah,"3) 20 minutes",0ah,"4) 30 minutes",0 ;5
    q4A=($-Level2Q-q1A-q2A-q3A)
		 BYTE "Q5).At a conference, 12 members shook hands with each other before & after the meeting. How many total number of hand shakes occurred?",0ah,"1) 130",0ah,"2) 132",0ah,"3) 142",0ah,"4) 144",0 ;132
	q5A=($-Level2Q-q1A-q2A-q3A-q4A)
		BYTE "Q6).Forest is to tree as tree is to ?",0ah,"1) Plant",0ah,"2) Leaf",0ah,"3) Branch",0ah,"4) Mangrove",0
	q6A=($-Level2Q-q1A-q2A-q3A-q4A-q5A)
		BYTE "Q7).The day after the day after tomorrow is four days before Monday. What day is it today?",0ah,"1) Monday",0ah,"2) Tuesday",0ah,"3) Wednesday",0ah,"4) Saturday",0
	q7A=($-Level2Q-q1A-q2A-q3A-q4A-q5A-q6A)
		BYTE "Q8).Complete this series of numbers: 9 = 4, 21 = 9, 22 = 9, 24 = 10, 8 = 5, 7 = 5, 99 = 10, 100 = 7, 17 =?",0ah,"1) 9",0ah,"2) 8",0ah,"3) 7",0ah,"4) 6",0
	q8A=($-Level2Q-q1A-q2A-q3A-q4A-q5A-q6A-q7A)
		BYTE "Q9).What is the maximum number of times a single page of a newspaper can be folded in half by hand?",0ah,"1) 1",0ah,"2) 3",0ah,"3) 4",0ah,"4) 6",0
	q9A=($-Level2Q-q1A-q2A-q3A-q4A-q5A-q6A-q7A-q8A)
		BYTE "Q10).If you divide 30 by half and add ten, what do you get?",0ah,"1) 5",0ah,"2) 35",0ah,"3) 65",0ah,"4) 70",0
     q10A=($-Level2Q-q1A-q2A-q3A-q4A-q5A-q6A-q7A-q8A-q9A)

;/////////Anas
Level1Q BYTE "Q1).How many sides are there in a hexagon?",0ah,"1) 6"	,0ah,"2) 2",0ah,"3) 3",0ah,"4) 5",0   
	 q1=($-Level1Q)											
	   BYTE "Q2).Area of a rectangle with L=4 and B=3",0ah,"1) 7",0ah,"2) 14",0ah,"3) 16",0ah,"4) 12",0		
     q2=($-Level1Q-q1)
	   BYTE "Q3).Name of current president of America",0ah,"1)BArrayAak Obama",0ah,"2)Joe Bidden ",0ah,"3)Trump ",0ah,"4)Henry Clinton",0 ;5    13
     q3=($-Level1Q-q1-q2)
	   BYTE "Q4).If speed of car is 10km/h, how far will it reach in 3 hours?",0ah,"1) 25km",0ah,"2) 30km",0ah,"3) 13km",0ah,"4) 50km",0 ;5
     q4=($-Level1Q-q1-q2-q3)
	   BYTE "Q5).How many continents are there on Earth",0ah,"1) 20",0ah,"2) 15",0ah,"3) 7",0ah,"4) 50",0 ;132
	 q5=($-Level1Q-q1-q2-q3-q4)
	   BYTE "Q6).Who was the first man on moon?",0ah,"1)Lance Armstrong",0ah,"2)George Washington",0ah,"3)Neil Armstrong",0ah,"4)Newton",0
	 q6=($-Level1Q-q1-q2-q3-q4-q5)
	   BYTE "Q7).How many months in a year have 28 days",0ah,"1) 1 ",0ah,"2) 3",0ah,"3) 4",0ah,"4) 1,once in every 4 years",0
	 q7=($-Level1Q-q1-q2-q3-q4-q5-q6)
		BYTE "Q8).Which one of the following produces honey? ",0ah,"1) Wasp",0ah,"2) Bee",0ah,"3) Hornet",0ah,"4) Flying ant",0
	 q8=($-Level1Q-q1-q2-q3-q4-q5-q6-q7)
		BYTE "Q9).If the time is 9pm, and duration of flight is 6 hours, what will be the time at arrival? ",0ah,"1) 2pm",0ah,"2) 6pm",0ah,"3) 9am",0ah,"4) 3am",0
	 q9=($-Level1Q-q1-q2-q3-q4-q5-q6-q7-q8)
		BYTE "Q10).What is the value of 20mod2?",0ah,"1) 10",0ah,"2) 5",0ah,"3) 0",0ah,"4) 1",0
     q10=($-Level1Q-q1-q2-q3-q4-q5-q6-q7-q8-q9)

buffer2 BYTE BUFFER_SIZE DUP(10)
f_name BYTE "players.txt",0
f_handle HANDLE ?
stringlength dword ?
str1 byte  "cannot open",0
space byte 0dh,0ah


.code

READ_FILE PROC
cld
mov edx, OFFSET filename
call OpenInputFile
mov filehandle, eax

mov edx, OFFSET buffer
mov ecx, bufferSize
call ReadFromFile
mov bytesRead, eax

mov ecx, q1c_size
mov esi, OFFSET buffer
mov edi, OFFSET q1c
rep movsb
mov q1c[91], 0
mov qc_addresses, OFFSET q1c

mov ecx, q2c_size
mov esi, OFFSET buffer + 92
mov edi, OFFSET q2c
rep movsb
mov q2c[184], 0
mov qc_addresses[4], OFFSET q1c

mov ecx, q3c_size
mov esi, OFFSET buffer + 275
mov edi, OFFSET q3c
rep movsb
mov q3c[150], 0
mov qc_addresses[8], OFFSET q1c

mov ecx, q4c_size
mov esi, OFFSET buffer + 424
mov edi, OFFSET q4c
rep movsb
mov q4c[217], 0
mov qc_addresses[12], OFFSET q1c

mov ecx, q5c_size
mov esi, OFFSET buffer + 642
mov edi, OFFSET q5c
rep movsb
mov q5c[96], 0
mov qc_addresses[16], OFFSET q1c

mov ecx, q6c_size
mov esi, OFFSET buffer + 739
mov edi, OFFSET q6c
rep movsb
mov q6c[180], 0
mov qc_addresses[20], OFFSET q1c

mov ecx, q7c_size
mov esi, OFFSET buffer + 920
mov edi, OFFSET q7c
rep movsb
mov q7c[180], 0
mov qc_addresses[24], OFFSET q1c

mov ecx, q8c_size
mov esi, OFFSET buffer + 999
mov edi, OFFSET q8c
rep movsb
mov q8c[96], 0
mov qc_addresses[28], OFFSET q1c

mov ecx, q9c_size
mov esi, OFFSET buffer + 1096
mov edi, OFFSET q9c
rep movsb
mov q9c[116], 0
mov qc_addresses[32], OFFSET q1c

mov ecx, q10c_size
mov esi, OFFSET buffer + 1213
mov edi, OFFSET q10c
rep movsb
mov q10c[103], 0
mov qc_addresses[36], OFFSET q1c

mWrite "Total bytes in file: "
call WriteDec
call Crlf

ret
READ_FILE ENDP

main PROC
call READ_FILE
mov eax,white+(red*16)
call settextcolor

;///////FILING - APPEND MODE////////////////
;;START OF PROGRAM
mov edx,offset f_name
call outputfile
mov f_handle,eax
cmp eax,INVALID_HANDLE_VALUE     
jne file_ok
mov edx,offset str1
call writestring
jmp quit

file_ok:
mov edx,offset PLAYER
call writestring
mov ecx,BUFFER_SIZE
mov edx,offset buffer2
call readstring
mov stringlength,eax

INVOKE SetFilePointer,
f_Handle,0,0,FILE_END

mov eax,f_handle
mov edx,offset space
mov ecx,1
call writetofile

mov eax,f_handle
mov edx,offset buffer2
mov ecx,stringlength
call writetofile

call crlf

INVOKE CloseHandle, fileHandle	;FILING
quit:
call spaces
mov edx,offset string5
call writestring
call crlf
call spaces
mov edx,offset string6
call writestring
call crlf
call spaces
mov edx,offset string7
call writestring
call crlf
call readchar
call clrscr								;MAIN MENU
mov eax,0
mov esi,0
mov quesL1[esi],q1
mov quesL1[esi+4],q2
mov quesL1[esi+8],q3
mov quesL1[esi+12],q4
mov quesL1[esi+16],q5
mov quesL1[esi+20],q6
mov quesL1[esi+24],q7
mov quesL1[esi+28],q8
mov quesL1[esi+32],q9
mov quesL1[esi+36],q10	
mov esi,0
mov quesL2[esi],q1A
mov quesL2[esi+4],q2A
mov quesL2[esi+8],q3A
mov quesL2[esi+12],q4A
mov quesL2[esi+16],q5A
mov quesL2[esi+20],q6A
mov quesL2[esi+24],q7A
mov quesL2[esi+28],q8A
mov quesL2[esi+32],q9A
mov quesL2[esi+36],q10A
mov esi,0						;ADDRESSES STORED

call clrscr
mov edx,offset Opt
call WriteString
Call ReadDec							
cmp eax,1
je Quiz   ;///PLAYERS JUMPS TO QUIZ IF CHOICE==1



;///CALLING IQ LEVEL FUNCTIONS////////
;INVOKE LEVEL1,ADDR quesL1,ADDR Level1Q,scoreL1
;mov ax,2000
;call Delay 
;call clrscr
;INVOKE LEVEL2,ADDR quesL2,ADDR Level2Q,scoreL2
;mov ax,2000
;call Delay
call clrscr
INVOKE LEVEL3,ADDR qC_addresses,scoreL3
call clrscr

mov ax,0
mov al,scoreL1
push ax
mov al,scoreL2
push ax
mov al,scoreL3
push ax
call Percentage   ;//PERCENTAGE FUNCTION TO CALCULATE PERCENTAGE OF IQ
mov ax,TotalScore
push eax
call standing
jmp exi



Quiz:				;QUIZ FUNCTIONS CALLED
INVOKE QLEVEL1,ADDR quesL1,ADDR Level1Q,scoreL1
mov ax,2000
call Delay
call clrscr
mov al,life
cmp al,0
je I1
call Crlf
call reward
call crlf
mov ax,2000
call Delay 
call clrscr

INVOKE QLEVEL2,ADDR quesL2,ADDR Level2Q,scoreL2
mov ax,2000
call Delay
call clrscr
mov al,life
cmp al,0
je I2
;call Crlf
call reward
;call crlf
mov ax,2000
call Delay
call clrscr 

INVOKE QLEVEL3, ADDR qC_addresses, scoreL3
mov ax,1000
call Delay
call clrscr
mov al,life
cmp al,0
je I3
;call Crlf
call reward
call crlf
mov ax,2000
call Delay 
call clrscr

mov eax,0
mov al,scoreL1
add al,scoreL2
add al,scoreL3
call Crlf
mov edx,offset QuizScore
call WriteString
call WriteDec
call Crlf
jmp exi
I1:
call clrscr
mov eax,0
mov al,scoreL1
call crlf
mov edx,offset QuizScore
call WriteString
call WriteDec
call Crlf
jmp exi

I2:
mov eax,0
mov al,scoreL1
add al,scoreL2
call Crlf
mov edx,offset QuizScore
call WriteString
call WriteDec
call Crlf
jmp exi

I3:
mov eax,0
mov al,scoreL1
add al,scoreL2
add al,scoreL3
call Crlf
mov edx,offset QuizScore
call WriteString
call WriteDec
call Crlf
exi:
exit
main ENDP

;/////////MAIN ENDP



;//FUNCTIONS DEFINED

reward Proc		;//REWARD WILL BE DISPLAYED AFTER PLAYER CROSSES LEVEL
pushad
mov dl,69
mov dh,18
call gotoxy
mov ebx,0
mov esi,0
L5:
cmp ebx,count
jz Rw
mov al,string4[esi]
call WriteChar
mov eax,150
call Delay
inc esi
dec count
jmp L5

Rw:
mov eax,27
mov count,eax
mov eax,0
popad
ret
reward ENDP





Percentage Proc
push ebp
mov ebp,esp
mov eax,0
mov ax,[ebp+8]		;RESTORING SCORES FROM STACK
add ax,[ebp+10]
add ax,[ebp+12]
mov bx,100
mul bx
mov bx,60
div bx
mov TotalScore,ax
mov edx,offset finalmsg
call WriteString
mov ax,TotalScore
call writedec
mov al,'%'
call WriteChar
call Crlf
pop ebp
ret 
Percentage ENDP




;//////IQ GAME LEVELS
LEVEL3 PROC, questions:PTR DWORD,scor3:BYTE
pushad
mov esi, questions
mov edi, OFFSET arr3
mov ecx, 10
L3_loop:
	mov edx, [esi]
	call WriteString
	call Crlf
	loop L3_loop

popad
ret
LEVEL3 ENDP




LEVEL2 PROC, ques:PTR DWORD, lev2q:PTR BYTE,scor2:BYTE
pushad
mov edi,ques
mov ebp,lev2q
mov esi,offset arr2
mov ebx,0
mov ecx,10
L2:
mov edx,ebp
call writestring
call crlf
add ebp,[edi]
add edi,4
call readdec
cmp al,[esi]
JNE E1
add bl,2
E1:
inc esi
loop L2
call crlf
mov edx,offset msg3
call writestring
mov al,bl
call writedec
mov scoreL2,bl
mov scor2,0
popad
ret
LEVEL2 ENDP



LEVEL1 PROC, quesA:PTR DWORD, lev1q:PTR BYTE,scor:BYTE
pushad
mov edi,quesA
mov ebp,lev1q
mov esi,offset arr1
mov ebx,0
mov ecx,10
L7:
mov edx,ebp
call writestring
call crlf
add ebp,[edi]
add edi,4
call readdec
cmp al,[esi]
JNE K
inc bl
K:
inc esi
loop L7
call crlf
mov edx,offset msg1
call writestring
mov al,bl
call WriteDec
mov scoreL1,bl
mov scor,0
popad
ret
LEVEL1 ENDP




;//////QUIZ GAME QUES
QLEVEL3 PROC, Ques3:PTR DWORD,scor3:BYTE
pushad
mov esi,offset arr3
mov ebx,0
mov ecx,10
L3:
mov edx,ebp
call writestring
call crlf
add ebp,[edi]
add edi,4
call readdec
cmp al,[esi]
JNE E1
add bl,3
jmp E2
E1:
dec life
mov al,life
cmp al,0
je S 
E2:
inc esi
loop L3
S:
call crlf
mov edx,offset msg4
call writestring
mov al,bl
call writedec
mov scoreL3,bl
mov scor3,0
popad
ret
QLEVEL3 ENDP

;/////LEVEL 2 QUESTIONS
QLEVEL2 PROC, ques:PTR DWORD, lev2q:PTR BYTE,scor2:BYTE
pushad
mov edi,ques
mov ebp,lev2q
mov esi,offset arr2
mov ebx,0
mov ecx,10
L2:
mov edx,ebp
call writestring
call crlf
add ebp,[edi]
add edi,4
call readdec
cmp al,[esi]
JNE E1
add bl,2
jmp E2
E1:
dec life
mov al,life
cmp al,0
je S2
E2:
inc esi
loop L2
S2:
call crlf
mov edx,offset msg3
call writestring
mov al,bl
call writedec
mov scoreL2,bl
mov scor2,0
popad
ret
QLEVEL2 ENDP


;//////LEVEL 1 QUESTIONS
QLEVEL1 PROC, quesA:PTR DWORD, lev1q:PTR BYTE,scor:BYTE
pushad
mov edi,quesA
mov ebp,lev1q
mov esi,offset arr1
mov ebx,0
mov ecx,10
L7:
	mov edx,ebp
	call writestring
	call crlf
	add ebp,[edi]
	add edi,4
call readdec
cmp al,[esi]
JNE K
inc bl
jmp L
K:
dec life
mov al,life
cmp al,0
je S3
L:
inc esi
loop L7
S3:
call crlf
mov edx,offset msg1
call writestring
mov al,bl
call WriteDec
mov scoreL1,bl
mov scor,0
popad
ret
QLEVEL1 ENDP

;//////IQ STANDING
standing PROC
push ebp
mov ebp,esp
mov eax,[ebp+8]
mov TotalScore,ax
cmp TotalScore,100
JE EQUAL
cmp TotalScore,60
JGE GREATER
mov edx,offset string3
call crlf
call writestring
call crlf
exit
EQUAL:
mov edx,offset string1
call crlf
call writestring
call crlf
exit
GREATER:
mov edx, offset string2
call crlf
call writestring
call crlf
pop ebp
ret
standing endp

spaces PROC
call crlf
call crlf
call crlf
mov edx,offset spaces1
call writestring
ret
spaces endp

outputfile proc
invoke createfile,
addr f_name,
generic_write,
do_not_share,
null,
OPEN_existing,
file_attribute_normal,
0
ret
outputfile endp

END main