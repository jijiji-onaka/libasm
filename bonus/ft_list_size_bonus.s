; int ft_list_size(t_list *begin_list);

section .text
global	_ft_list_size

_ft_list_size:
		xor	rax, rax
		jmp	.loop

.loop:
		cmp	rdi, 0x0
		je	.end
		inc	rax
		mov	rdi, [rdi + 8]
		jmp	.loop

.end:
		ret