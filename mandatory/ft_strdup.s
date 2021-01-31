section .text
global _ft_strdup
extern	_malloc
extern	___error
extern	_ft_strlen
extern	_ft_strcpy

_ft_strdup:
		push	rdi
		call	_ft_strlen
		mov		rdi, rax
		inc		rdi
		call	_malloc
		cmp		rax, 0x0
		jc		.error
		mov		rdi, rax
		pop		rsi
		call	_ft_strcpy
		ret

.error:
		pop	rdi
		ret