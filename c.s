ft_list_push_front:
		push	rbp
		mov		rbp, rsp
		sub		rsp, 32
		mov		[rbp - 24], rdi
		mov		[rbp - 32], rsi
		mov		edi, 16
		call	_malloc
		cmp		rax, 0x0
		je		 .end
		mov		[rbp - 8], rax ; [rbp - 8] = new
		mov		rax, [rbp - 8] ; rax = new
		mov		rdx, [rbp - 32]
		mov		[rax], rdx
		mov		rax, [rbp - 24]
		mov		rdx, [rax]
		mov		rax, [rbp - 8]
		mov		[rax+8], rdx
		mov		rax, [rbp - 24]
		mov		rdx, [rbp - 8]
		mov		[rax], rdx
		jmp		.end
.end:
		leave
		ret