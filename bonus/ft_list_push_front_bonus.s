; void ft_list_push_front(t_list **begin_list, void *data)

section .text
	global _ft_list_push_front
	extern _malloc
_ft_list_push_front:
		push	rbp
		mov		rbp, rsp
		sub		rsp, 24
		cmp		rdi, 0
		je		 .end
		mov		[rbp - 16], rdi
		mov		[rbp - 24], rsi
		mov		edi, 16
		call	_malloc
		cmp		rax, 0x0
		je		 .end
		mov		[rbp - 8], rax ; [rbp - 8] = new
		mov		rdx, [rbp - 24] ; rdx = data
		mov		[rax], rdx ; new->data = data
		mov		rdx, [rbp - 16] ; rdx = begin_list
		mov		rdx, [rdx] ; rdx = *begin_list
		mov		[rax + 8], rdx ; [rax + 8](= new->next) = *begin_list
		mov		rax, [rbp - 16] ; rax = begin_list
		mov		rdx, [rbp - 8] ; rdx = new
		mov		[rax], rdx ; *begin_list = new
.end:
		leave
		ret
