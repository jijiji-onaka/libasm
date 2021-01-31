section .text
global	_ft_list_remove_if
extern	_free

; void	ft_list_remove_if2(t_list **list,
;			void *data, int (*cmp)(), void (*free_fct)(void *))

; rdi = t_list **list
; 第1引数

; rsi
; 第2引数

; rdx
; 第3引数

; rcx
; 第4引数

; local variables
; t_list	*begin;
; t_list	*save;


_ft_list_remove_if:
		push	rbp ; Push to restore the base pointer
		mov		rbp, rsp ; move rbp to current rsp
		sub		rsp, 48 ; Create a stack frame
						; to allocate an area that can be freely used as a local variable.
		mov		[rbp - 24], rdi ; first argument(= list) set
		mov		[rbp - 32], rsi ; second argument(= data) set
		mov		[rbp - 40], rdx ; third argument(= (*cmp)()) set
		mov		[rbp - 48], rcx ; fourth argument(= (*free_fct)()) set
		mov		rax, [rbp - 24] ; rax = list
		mov		rax, [rax] ; rax = *list
		cmp		rax, 0x0 ; if (*list == NULL)
		je		 .return
		mov		[rbp - 8], rax ; [rbp - 8](= begin) = *list
		jmp		.check_while_loop_condition
.compare_except_first_data:
		mov		rax, [rbp - 24] ; rax = list
		mov		rax, [rax] ; rax = *list
		mov		rax, [rax + 8] ; rax = (*list)->next
		mov		rsi, [rax] ; rsi = (*list)->next->data
		mov		rdi, [rbp - 32] ; rdi = data
		mov		rcx, [rbp - 40] ; rcx = (*cmp)()
		xor		eax, eax ; eax = 0;
		call	rcx ; eax = cmp(rdi, rsi)
		cmp		eax, 0x0 ; if (eax == 0)
		jne		.next_list
		mov		rax, [rbp - 24] ; rax = list
		mov		rax, [rax] ; rax = *list
		mov		rax, [rax + 8] ; rax = (*list)->next
		mov		[rbp - 16], rax ; [rbp - 16](= save) = (*list)->next
		mov		rdx, rax ; rdx = (*list)->next
		mov		rdx, [rdx + 8] ; rdx = (*list)->next->next
		mov		rax, [rbp - 24] ; rax = list
		mov		rax, [rax] ; rax = *list
		mov		[rax + 8], rdx ; [rax + 8](= (*list)->next) = (*list)->next->next
		mov		rdi, [rbp - 16] ; rdi = save
		mov		rdi, [rdi] ; rdi = save->data
		mov		rdx, [rbp - 48]
		call	rdx
		mov		rdi, [rbp - 16] ; rdi = save
		call	_free
.next_list:
		mov		rax, [rbp - 24] ; rax = list
		mov		rdx, [rax] ; rdx = *list
		mov		rdx, [rdx + 8] ; rdx = (*list)->next
		mov		[rax], rdx ; [rax](= *list) =  (*list)->next
.check_while_loop_condition:
		mov		rax, [rbp - 24] ; rax = list
		mov		rax, [rax] ; rax = *list
		cmp		rax, 0x0 ; if (*list== NULL)
		je		.compare_first_data
		mov		rax, [rax + 8] ; rax = (*list)->next
		cmp		rax, 0x0 ; if ((*list)->next == NULL)
		jne		.compare_except_first_data
.compare_first_data:
		mov		rax, [rbp - 24] ; rax = list
		mov		rdx, [rbp - 8] ; rdx = begin(== *list)
		mov		[rax], rdx ; [rax](= *list) = begin
		mov		rax, [rax] ; rax = *list
		mov		rdx, [rax] ; rdx = (*list)->data
		mov		rax, [rbp - 32] ; rax = data
		mov		rcx, [rbp - 40] ; rcx = (*cmp)()
		mov		rsi, rdx ; rsi = (*list)->data
		mov		rdi, rax ; rdi = data
		xor		eax, eax ; eax = 0 // いるのかしら
		call	rcx ; eax = cmp(data, (*list)->data)
		cmp		eax, 0x0 ; if (eax == 0)
		jne		.return
		mov		rax, [rbp - 24] ; rax = list
		mov		rax, [rax] ; rax = *list
		mov		rax, [rax + 8] ; rax = (*list)->next
		mov		[rbp - 16], rax ; [rbp - 16](= save) = (*list)->next
		mov		rdi, [rbp - 24] ; rdi = list
		mov		rdi, [rdi] ; rdi = *list
		mov		rdi, [rdi] ; rdi = (*list)->data
		mov		rdx, [rbp - 48] ; rdx = (*free_fct)()
		call	rdx ; free_fct((*list)->data)
		mov		rax, [rbp - 24] ; rax = list
		mov		rdi, [rax] ; rdi = *list
		call	_free ; free(*list)
		mov		rax, [rbp - 24] ; rax = list
		mov		rdx, [rbp - 16] ; rdx = save
		mov		[rax], rdx ; [rax](= *list) = save
		jmp		.return
.return:
		leave
		ret