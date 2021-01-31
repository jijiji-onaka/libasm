;ssize_t
;	read(int fildes, void *buf, size_t nbyte);

section .text
global _ft_read
extern	___error

_ft_read:
		mov		rax, 0x2000003
		syscall
		jc		.error
		ret

.error:
		mov	rdx, rax
		call	___error
		mov		[rax], rdx
		mov		rax, -1
		ret
