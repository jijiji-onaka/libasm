; void	ft_list_sort(t_list **list, int (*cmp)());

section .text
	global	_ft_list_sort

_ft_list_sort:
		push	rbp
		mov		rbp, rsp
		sub		rsp, 32
		mov		[rbp - 24], rdi
		mov		[rbp - 32], rsi
		cmp		rdi, 0x0 ; if (list == NULL)
		je		 .return
		mov		rax, [rbp - 24] ; rax = list
		mov		rax, [rax] ; rax = *list
		cmp		rax, 0x0 ; if (*list == NULL)
		je		 .return
		mov		rax, [rax + 8] ; rax = (*list)->next
		cmp		rax, 0x0 ; if ((*list)->next == NULL)
		je		 .return
		mov		rax, [rbp - 24] ; rax = list
		mov		rax, [rax] ; rax = *list
		mov		[rbp - 8], rax ; [rbp - 8](= begin) = *list
		jmp		.while_loop_condition
.in_loop:
		mov		rsi, [rax] ; rdx = (*list)->next->data
		mov		rdi, [rbp - 24] ; rdi = list
		mov		rdi, [rdi] ; rdi = *list
		mov		rdi, [rdi] ; rdi = (*list)->data
		mov		rcx, [rbp - 32] ; rcx = (*cmp)()
		xor		eax, eax
		call	rcx
		cmp		eax, 0x0
		jg		.swap
		mov		rax, [rbp - 24] ; rax = list
		mov		rax, [rax] ; rax = *list
		mov		rdx, [rax + 8] ; rdx = (*list)->next
		mov		rax, [rbp - 24] ; rax = list
		mov		[rax], rdx ; *list = (*list)->next
		jmp		.while_loop_condition
.swap:
		mov		rax, [rbp - 24] ; rax = list
		mov		rax, [rax] ; rax = *list
		mov		rax, [rax] ; rax = (*list)->data
		mov		[rbp - 16], rax ; [rbp - 16](= tmp) = (*list)->data
		mov		rax, [rbp - 24] ; rax = list
		mov		rdx, [rax] ; rdx = *list
		mov		rdx, [rdx + 8] ; rdx = (*list)->next
		mov		rdx, [rdx] ; rdx = (*list)->next->data
		mov		rax, [rax] ; rax = *list
		mov		[rax], rdx ; (*list)->data = (*list)->next->data
		mov		rax, [rax + 8] ; rax(= *list) = (*list)->next
		mov		rdx, [rbp - 16] ; rdx(= (*list)->next->data) = tmp
		mov		[rax], rdx ; (*list)->next->data = tmp
		mov		rax, [rbp - 24] ; rax = list
		mov		rdx, [rbp - 8] ; rdx = begin
		mov		[rax], rdx ; *list = begin
		jmp		.while_loop_condition
.L6:
		mov		rax, [rbp - 24] ; rax = list
		mov		rax, [rax] ; rax = *list
		mov		rdx, [rax + 8] ; rdx = (*list)->next
		mov		rax, [rbp - 24] ; rax = list
		mov		[rax], rdx ; *list = (*list)->next
.while_loop_condition:
		mov		rax, [rbp - 24] ; rax = list
		mov		rax, [rax] ; rax = *list
		mov		rax, [rax + 8] ; rax = (*list)->next
		cmp	rax, 0x0 ; if ((*list)->next != NULL) -> .in_loop
		jne		.in_loop
		mov		rax, [rbp - 24] ;rax = list
		mov		rdx, [rbp - 8] ; rdx = begin
		mov		[rax], rdx ; *list = begin
		jmp		.return
.return:
		leave
		ret