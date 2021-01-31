section .text
	global	_ft_atoi_base

_ft_atoi_base:
		cmp		rdi, 0x0
		je		.L19
		cmp		rsi, 0x0
		je		.L19
        push    rbp
        mov     rbp, rsp
        sub     rsp, 936
        mov     [rbp-1048], rdi
        mov     [rbp-1056], rsi
        cmp     [rbp-1048], 0
        je      .L2
        cmp     [rbp-1056], 0
        jne     .L3
.L2:
        mov     eax, 0
        jmp     .L18
.L3:
        mov     DWORD PTR [rbp-4], 0
        jmp     .L5
.L6:
        mov     eax, DWORD PTR [rbp-4]
        lea     edx, [rax+1]
        mov     DWORD PTR [rbp-4], edx
        cdqe
        mov     DWORD PTR [rbp-1040+rax*4], 0
.L5:
        cmp     DWORD PTR [rbp-4], 255
        jle     .L6
        jmp     .L7
.L9:
        add     [rbp-1048], 1
.L7:
        mov     rax, [rbp-1048]
        movzx   eax, BYTE PTR [rax]
        test    al, al
        je      .L8
        mov     rax, [rbp-1048]
        movzx   eax, BYTE PTR [rax]
        cmp     al, 9
        je      .L9
        mov     rax, [rbp-1048]
        movzx   eax, BYTE PTR [rax]
        cmp     al, 10
        je      .L9
        mov     rax, [rbp-1048]
        movzx   eax, BYTE PTR [rax]
        cmp     al, 11
        je      .L9
        mov     rax, [rbp-1048]
        movzx   eax, BYTE PTR [rax]
        cmp     al, 12
        je      .L9
        mov     rax, [rbp-1048]
        movzx   eax, BYTE PTR [rax]
        cmp     al, 13
        je      .L9
        mov     rax, [rbp-1048]
        movzx   eax, BYTE PTR [rax]
        cmp     al, 32
        je      .L9
.L8:
        mov     DWORD PTR [rbp-8], 0
        jmp     .L10
.L14:
        mov     eax, DWORD PTR [rbp-8]
        movsx   rdx, eax
        mov     rax, [rbp-1056]
        add     rax, rdx
        movzx   eax, BYTE PTR [rax]
        movsx   eax, al
        cdqe
        mov     eax, DWORD PTR [rbp-1040+rax*4]
        test    eax, eax
        je      .L11
        mov     eax, 0
        jmp     .L18
.L11:
        mov     eax, DWORD PTR [rbp-8]
        movsx   rdx, eax
        mov     rax, [rbp-1056]
        add     rax, rdx
        movzx   eax, BYTE PTR [rax]
        movsx   eax, al
        cdqe
        mov     edx, DWORD PTR [rbp-1040+rax*4]
        mov     eax, DWORD PTR [rbp-8]
        lea     esi, [rax+1]
        mov     eax, DWORD PTR [rbp-8]
        movsx   rcx, eax
        mov     rax, [rbp-1056]
        add     rax, rcx
        movzx   eax, BYTE PTR [rax]
        movsx   eax, al
        add     edx, esi
        cdqe
        mov     DWORD PTR [rbp-1040+rax*4], edx
        mov     eax, DWORD PTR [rbp-8]
        movsx   rdx, eax
        mov     rax, [rbp-1056]
        add     rax, rdx
        movzx   eax, BYTE PTR [rax]
        cmp     al, 32
        je      .L12
        mov     eax, DWORD PTR [rbp-8]
        movsx   rdx, eax
        mov     rax, [rbp-1056]
        add     rax, rdx
        movzx   eax, BYTE PTR [rax]
        cmp     al, 43
        je      .L12
        mov     eax, DWORD PTR [rbp-8]
        movsx   rdx, eax
        mov     rax, [rbp-1056]
        add     rax, rdx
        movzx   eax, BYTE PTR [rax]
        cmp     al, 32
        jne     .L13
.L12:
        mov     eax, 0
        jmp     .L18
.L13:
        add     DWORD PTR [rbp-8], 1
.L10:
        mov     eax, DWORD PTR [rbp-8]
        movsx   rdx, eax
        mov     rax, [rbp-1056]
        add     rax, rdx
        movzx   eax, BYTE PTR [rax]
        test    al, al
        jne     .L14
        cmp     DWORD PTR [rbp-8], 1
        jg      .L15
        mov     eax, 0
        jmp     .L18
.L15:
        mov     DWORD PTR [rbp-12], 0
        jmp     .L16
.L17:
        mov     eax, DWORD PTR [rbp-12]
        imul    eax, DWORD PTR [rbp-8]
        mov     DWORD PTR [rbp-12], eax
        mov     rax, [rbp-1048]
        movzx   eax, BYTE PTR [rax]
        movsx   eax, al
        cdqe
        mov     eax, DWORD PTR [rbp-1040+rax*4]
        sub     eax, 1
        add     DWORD PTR [rbp-12], eax
        add     [rbp-1048], 1
.L16:
        mov     rax, [rbp-1048]
        movzx   eax, BYTE PTR [rax]
        test    al, al
        jne     .L17
        mov     eax, DWORD PTR [rbp-12]
.L18:
        leave
        ret
.L19:
		xor		eax, eax
		ret