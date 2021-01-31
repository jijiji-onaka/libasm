; int ft_list_size(t_list *begin_list);

section .text
global	_ft_list_size

_ft_list_size:
		cmp	rdi, 0x0
		je	.error
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
.error:
		mov	rax, -1
		ret