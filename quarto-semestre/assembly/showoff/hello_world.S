.code64
.section .text
.global _start

_start:
	movb (msg), %al
loop:
	push %rax
	movq $1, %rax
	movq $1, %rdi
	movq $msg, %rsi
	movq $msgsize, %rdx
	syscall
	popq %rax

	inc %rax
	movb %al, (msg)
	cmp $58, %rax
	jl loop
endloop:
	movq $60, %rax
	xorq %rdi, %rdi
	syscall

.section .data
msg: .ascii "0\n"
msgsize = . - msg
