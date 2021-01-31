;char *strcpy(char *s1, const char *s2)
;{
;	char *s = s1;
;	while ((*s++ = *s2++) != 0)
;		;
;	return (s1);
;}

;メモリからメモリの移動は許されない(X : move byte[], byte[])
section .text
	global _ft_strcpy

_ft_strcpy:
		push	rdi
		xor		rax, rax

.cpy:
		mov		dl, BYTE[rsi + rax]
		mov		BYTE[rdi + rax], dl
		cmp		BYTE[rsi + rax], 0x0
		je		.end
		inc		rax
		jmp		.cpy

.end:
		pop		rax
		ret