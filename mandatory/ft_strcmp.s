;int	ft_strcmp(const char *p1, const char *p2)
;{
;	const unsigned char	*s1;
;	const unsigned char	*s2;
;
;	s1 = (const unsigned char *)p1;
;	s2 = (const unsigned char *)p2;
;	while (*s1 && *s1 == *s2)
;	{
;		s1++;
;		s2++;
;	}
;	return (*s1 - *s2);
;}

section .data

section .text
global _ft_strcmp

_ft_strcmp:
		mov	rax, -1
		xor	rdx, rdx
		xor	rcx, rcx
		jmp	.compare

.compare:
		inc	rax
		mov	dl, byte[rdi + rax]
		mov	cl, byte[rsi + rax]
		cmp	dl, 0x0
		je	.end
		cmp	edx, ecx
		je	.compare
		jz	.end

.end:
		cmp	edx, ecx
		jl	.little
		je	.equal
		jg	.greater

.little:
		mov	rax, -1
		ret

.equal:
		xor	rax, rax
		ret

.greater:
		mov	rax, 1
		ret
