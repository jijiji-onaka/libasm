section .text
global	_ft_list_remove_if
extern	_free

; rdi
; 第1引数
; rsi
; 第2引数
; rdx
; 第3引数
; rcx
; 第4引数

; r8 = lst(= *begin_lst)


_ft_list_remove_if:
		push	rbp
		mov		rbp, rsp
		jmp		.first_error_check

.loop:
		cmp		r8, 0x0
		je		.end
		jmp 	.data_compare
		mov		r8, [r8 + 8]
		jmp		.loop

.data_compare:
		push	rdi
		push	rsi
		push	rdx
		push	rcx
		mov		rdi, [r8]
		cmp		rdi, 0
		je		.end	;error
		call	rdx
		pop		rcx
		pop		rdx
		pop		rsi
		pop		rdi
		cmp		rax, 0x0
		je		.free_func
		mov		r8, [r8 + 8]
		jmp		.loop

.free_func:
		mov		rdi, [r8] ; rdi = r8 = lst->data
		call	rcx
		mov		r8, [r8 + 8]
		jmp		.loop

.first_error_check:
		cmp		rdi, 0
		je		.error
		cmp		rsi, 0
		je		.error
		cmp		rdx, 0
		je		.error
		cmp		rcx, 0
		je		.error
		mov		r8, [rdi]
		cmp		r8, 0
		je		.error
		jmp		.loop

.error:
		leave
		ret
.end:
		leave
		ret