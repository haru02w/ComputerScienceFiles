global _start

section .text
_start:
	mov eax, 4
	mov ebx, 1
	mov ecx, hello
	mov edx, (size)
	int 0x80
	mov eax, 1
	int 0x80

section .data
hello db "hello world", 0x0A
size equ $ - hello

