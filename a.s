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
        push    rbp ; Push to restore the base pointer
        mov     rbp, rsp ; move rbp to current rsp
        sub     rsp, 48 ; Create a stack frame
						; to allocate an area that can be freely used as a local variable.
        mov     [rbp - 24], rdi ; first argument(= list) set
        mov     [rbp - 32], rsi ; second argument(= data) set
        mov     [rbp - 40], rdx ; third argument(= (*cmp)()) set
        mov     [rbp - 48], rcx ; fourth argument(= (*free_fct)()) set
        mov     rax, [rbp - 24] ; rax = list
        mov     rax, [rax] ; rax = *list
        cmp    rax, 0x0 ; if (*list == NULL)
        je      .L8
        mov     [rbp - 8], rax ; [rbp - 8](= begin) = *list
        ; mov     rax, [rbp - 24] ; rax = list
        ; mov     rax, [rax] ; rax = *list
        jmp     .L4
.L7:
        mov     rax, [rbp - 24]
        mov     rax, [rax]
        mov     rax, [rax+8]
        mov     rdx, [rax]
        mov     rax, [rbp - 32]
        mov     rcx, [rbp - 40]
        mov     rsi, rdx
        mov     rdi, rax
        mov     eax, 0
        call    rcx
        test    eax, eax
        jne     .L5
        mov     rax, [rbp - 24]
        mov     rax, [rax]
        mov     rax, [rax+8]
        mov     [rbp - 16], rax
        mov     rax, [rbp - 24]
        mov     rax, [rax]
        mov     rdx, [rax+8]
        mov     rax, [rbp - 24]
        mov     rax, [rax]
        mov     rdx, [rdx+8]
        mov     [rax+8], rdx
        mov     rax, [rbp - 16]
        mov     rax, [rax]
        mov     rdi, rax
        call    _free
        mov     rax, [rbp - 16]
        mov     rdi, rax
        call    _free
.L5:
        mov     rax, [rbp - 24]
        mov     rax, [rax]
        mov     rdx, [rax+8]
        mov     rax, [rbp - 24]
        mov     [rax], rdx
.L4:
        mov     rax, [rbp - 24]
        mov     rax, [rax]
        test    rax, rax
        je      .L6
        mov     rax, [rbp - 24]
        mov     rax, [rax]
        mov     rax, [rax+8]
        test    rax, rax
        jne     .L7
.L6:
        mov     rax, [rbp - 24]
        mov     rdx, [rbp - 8]
        mov     [rax], rdx
        mov     rax, [rbp - 24]
        mov     rax, [rax]
        mov     rdx, [rax]
        mov     rax, [rbp - 32]
        mov     rcx, [rbp - 40]
        mov     rsi, rdx
        mov     rdi, rax
        mov     eax, 0
        call    rcx
        test    eax, eax
        jne     .L1
        mov     rax, [rbp - 24]
        mov     rax, [rax]
        mov     rax, [rax+8]
        mov     [rbp - 16], rax
        mov     rax, [rbp - 24]
        mov     rax, [rax]
        mov     rax, [rax]
        mov     rdi, rax
        call    _free
        mov     rax, [rbp - 24]
        mov     rax, [rax]
        mov     rdi, rax
        call    _free
        mov     rax, [rbp - 24]
        mov     rdx, [rbp - 16]
        mov     [rax], rdx
        jmp     .L1
.L8:
        nop
.L1:
        leave
        ret