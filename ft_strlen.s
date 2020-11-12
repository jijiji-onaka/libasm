section .data

section .text
	global _ft_strlen

_ft_strlen:
		xor	rax, rax				; i = 0

loop:	cmp	byte[rdi + rax], 0x0	; rdi -> s and if (s + i == '\0')
		jz	end
		inc	rax						; i++
		jne	loop					; then loop

end:	ret