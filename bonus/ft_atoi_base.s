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
		sub		rsp, 1064
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
		mov		dword[rbp - 4], 0 ; int len = 0;
		jmp		.baselen_loop_condition
.check_base_error_and_baselen:
		mov		rax, qword[rbp - 1056] ; rax = base
		movzx	eax, byte[rax] ; eax = *base
		cmp		al, 45
		je		.return_zero
		cmp		al, 43
		je		.return_zero
		cmp		al, 9
		je		.return_zero
		cmp		al, 10
		je		.return_zero
		cmp		al, 11
		je		.return_zero
		cmp		al, 12
		je		.return_zero
		cmp		al, 13
		je		.return_zero
		cmp		al, 32
		je		.return_zero
		; jmp		.increment
		mov		rax, [rbp - 1056] ; rax = base
		movzx	eax, byte[rax] ;
		movsx	eax, al
		; cdqe : rax レジスタを2倍のビット数に符号拡張
		cdqe
		mov		eax, dword[rbp - 1040 + rax * 4] ; eax = charset[*base]
		cmp		eax, 0x0
		jne		.return_zero
.check_base_error_and_baselen2:
		mov		rax, qword[rbp - 1056] ; rax = base
		movzx	eax, byte[rax] ; eax = *base
		movsx	eax, al
		cdqe
		mov		edx, dword[rbp - 1040 + rax * 4]
		mov		eax, dword[rbp - 4] ; eax = len
		lea		ecx, [rax + 1] ; ecx = len + 1
		mov		rax, qword[rbp - 1056] ; rax = base
		movzx	eax, byte[rax] ; eax = *base
		add		edx, ecx ; edx(= charset[*base]) += len + 1
		cdqe
		mov		dword[rbp - 1040 + rax * 4], edx ; charset[*base] = edx
		jmp		.increment
.increment:
		add		qword[rbp - 1056], 1 ; base++;
		add		dword[rbp - 4], 1 ; len++;
.baselen_loop_condition:
		mov		rax, qword[rbp - 1056] ; rax = base
		mov		al, byte[rax] ; al = *base
		cmp		al, 0x0
		jne		.check_base_error_and_baselen
		cmp		dword[rbp - 4], 2 ; if (len < 2)
		jl		.return_zero
		mov		dword[rbp - 8], 0 ; int ret = 0;
		mov		dword[rbp - 12], 1 ; int flag = 1;
		jmp		.set_negative_flag_condition
.set_negative_flag_condition:
		mov		rax, qword[rbp - 1048] ; rax = str
		movzx	eax, byte[rax] ; dl = *str
		cmp		al, 0
		je		.str_loop
		cmp		al, 45
		je		.set_negative_flag
		cmp		al, 43
		jne		.str_loop
.set_negative_flag:
		mov		rax, qword[rbp - 1048] ; rax = str
		movzx	eax, byte[rax]
		movsx	eax, al
		mov		edx, 44
		sub		edx, eax
		mov		eax, dword[rbp - 12]
		imul	eax, edx
		mov		dword[rbp - 12], eax
		inc		qword[rbp - 1048]
		jmp		.set_negative_flag_condition
.str_loop:
		mov		rax, [rbp - 1048] ; rax = str
		movzx	eax, byte[rax] ; eax = *str
		cmp		al, 0x0
		je		.L1111
		movsx	eax, al
		cdqe
		cmp		al, 0x0
		js		.L1111
		mov		eax, dword[rbp - 1040 + rax * 4]
		cmp		eax, 0x0
		je		.L1111
		mov		eax, dword[rbp - 8] ; eax = ret
		imul	eax, dword[rbp - 4] ; eax *= len
		mov		dword[rbp - 8], eax
		mov		rax, [rbp - 1048]
		movzx	rax, byte[rax]
		mov		eax, dword[rbp - 1040 + rax * 4]
		sub		eax, 1
		add		dword[rbp - 8], eax
		inc		qword[rbp - 1048]
		jmp		.str_loop
		; mov		eax, dword[rbp - 8] ; eax = ret
		; imul	eax, dword[rbp - 12]
; .debug:
; 		mov	eax, -1
; 		leave
; 		ret
.L1111:
		mov		eax, dword[rbp - 8] ; eax = ret
		imul	eax, dword[rbp - 12]
.return:
		; mov		eax, dword[rbp - 8] ; eax = ret
		; imul	eax, dword[rbp - 12]

		; mov		eax, dword[rbp - 8] ; eax = ret
		; ここじゃダメな理由
		; .check_str_errorの最後にmov [rbp - 8], 0を入れるとゼロになることから
		; jneだけど一応通っていてスタックフレームに対する命令は生きているのかも。
		leave
		ret
.return_zero:
		xor		eax, eax
		leave
		ret

.wrong_premise:
		xor		eax, eax
		ret
