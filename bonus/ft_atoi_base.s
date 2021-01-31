; int		ft_atoi_base(char *str, char *base)

section .text
	global	_ft_atoi_base

_ft_atoi_base:
		cmp		rdi, 0x0
		je		.wrong_premise
		cmp		rsi, 0x0
		je		.wrong_premise
		push	rbp
		mov		rbp, rsp
		sub		rsp, 936
		mov		[rbp - 1048], rdi
		mov		[rbp - 1056], rsi
		mov		dword[rbp - 4], 0 ; [rbp - 4](= int i) = 0
		xor		rax, rax
		jmp		.initialize_charset_condition
.initialize_charset:
		mov		eax, dword[rbp - 4] ; eax = i
		; cdge : eax を符号拡張して rax に設定
		; しなければ dword[rbp - 1040 + rax * 4]ができない
		cdqe
		mov		dword[rbp - 1040 + rax * 4], 0
		inc		dword[rbp - 4]
.initialize_charset_condition:
		cmp		dword[rbp - 4], 255 ; while (i < 256)
		jle		.initialize_charset
		jmp		.is_white_space_and_null_char
.skip_white_space:
		add		qword[rbp - 1048], 1
.is_white_space_and_null_char:
		mov		rax, [rbp - 1048] ; rax = str
		mov		al, byte[rax] ; al = *str
		cmp		al, 0x0 ; *str == '\0'
		je		 .finish_skip_and_set_local_variable
		mov		rax, [rbp - 1048] ; rax = str
		mov		al, byte[rax] ; al = *str
		cmp		al, 9
		je		 .skip_white_space
		cmp		al, 10
		je		 .skip_white_space
		cmp		al, 11
		je		 .skip_white_space
		cmp		al, 12
		je		 .skip_white_space
		cmp		al, 13
		je		 .skip_white_space
		cmp		al, 32
		je		 .skip_white_space
		jmp		.finish_skip_and_set_local_variable
.finish_skip_and_set_local_variable:
		mov		dword[rbp - 8], 0 ; int len = 0;
		jmp		.baselen_loop_condition
.check_base_error_and_baselen:
		mov		rax, [rbp - 1056] ; rax = base
		movzx   eax, byte[rax] ;
		; cdqe : rax レジスタを2倍のビット数に符号拡張
		cdqe
		mov		eax, dword[rbp - 1040 + rax * 4] ; eax = charset[*base]
		cmp		eax, 0x0
		je		 .check_base_error_and_baselen2
		jmp		.return_zero
.check_base_error_and_baselen2:
		mov		rax, qword[rbp - 1056] ; rax = base
		movzx   eax, byte[rax] ; eax = *base
		cdqe
		mov		edx, dword[rbp - 1040 + rax * 4]
		mov		eax, dword[rbp - 8] ; eax = len
		lea		ecx, [rax + 1] ; ecx = len + 1
		mov		rax, qword[rbp - 1056] ; rax = base
		movzx   eax, byte[rax] ; eax = *base
		add		edx, ecx ; edx(= charset[*base]) += len + 1
		cdqe
		mov		dword[rbp - 1040 + rax * 4], edx ; charset[*base] = edx
		mov		rax, qword[rbp - 1056] ; rax = base
		movzx   eax, byte[rax] ; eax = *base
		cmp		al, 45
		je		 .return_zero
		cmp		al, 43
		je		 .return_zero
		cmp		al, 32
		je		 .return_zero
		jmp		.L13
.return_zero:
		xor		eax, eax
		jmp		.return
.L13:
		add		qword[rbp - 1056], 1 ; base++;
		add		dword[rbp - 8], 1 ; len++;
.baselen_loop_condition:
		mov		rax, qword[rbp - 1056] ; rax = base
		mov		al, byte[rax] ; al = *base
		cmp	al, 0x0
		jne		.check_base_error_and_baselen
		cmp		dword[rbp - 8], 1 ; if (len < 2)
		jl		.return_zero
		mov		dword[rbp - 12], 0 ; int ret = 0;
		jmp		.str_loop_condition

.set_return_value:
		imul	eax, dword[rbp - 8] ; eax = ret *= len
		mov		dword[rbp - 12], eax ; [rbp - 12] = eax
		mov		rax, [rbp - 1048] ; rax = str
		mov   al, byte[rax] ;
		movsx   rax, al
		mov		eax, dword[rbp - 1040 + rax * 4] ; eax = charset[*str]
		sub		eax, 1 ; eax = eax - 1
		add		dword[rbp - 12], eax ; ret += eax
		inc		qword[rbp - 1048] ; str++;
.str_loop_condition:
		mov		rax, [rbp - 1048] ; rax = str
		mov		al, byte[rax] ; al = *str
		cmp		al, 0x0
		mov		eax, dword[rbp - 12] ; eax = ret(= 0)
		jne		.set_return_value
		; jmp		.return

.return:
		leave
		ret

.wrong_premise:
		xor		eax, eax
		ret
