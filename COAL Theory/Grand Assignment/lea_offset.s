	.file	"lea_offset.cpp"
	.intel_syntax noprefix
	.globl	_moon
	.bss
	.align 4
_moon:
	.space 20
	.text
	.globl	__Z10star_arrayv
	.def	__Z10star_arrayv;	.scl	2;	.type	32;	.endef
__Z10star_arrayv:
LFB0:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 32
	mov	DWORD PTR [ebp-4], 19
L3:
	cmp	DWORD PTR [ebp-4], 0
	js	L4
	lea	edx, [ebp-24]
	mov	eax, DWORD PTR [ebp-4]
	add	eax, edx
	mov	BYTE PTR [eax], 42
	mov	eax, DWORD PTR [ebp-4]
	add	eax, OFFSET FLAT:_moon
	mov	BYTE PTR [eax], 120
	sub	DWORD PTR [ebp-4], 1
	jmp	L3
L4:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE0:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
