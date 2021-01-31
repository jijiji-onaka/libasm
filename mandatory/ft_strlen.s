section .text
	global _ft_strlen

_ft_strlen:
		xor	rax, rax				; i = 0

.loop:
		cmp rdi, 0x0
		je	.end
		cmp	byte[rdi + rax], 0x0	; rdi -> s and if (s + i == '\0')
		je	.end
		inc	rax						; i++
		jmp	.loop					; then loop

.end:
		ret							; return (rax);