; Copyright (c) 2023 João Victor Millane. All Rights Reserved.

global _start
section .data
	m1 db "Digite algum numero entre 0 e 9: ", 0
	m1_sz dd $ - m1

	m2 db "O menor numero é: ", 0
	m2_sz dd $ - m2

	var db '0', 10
	const db '5', 10

section .text
_start:
	; print m1 to screen
	mov eax, 4
	mov ebx, 1
	mov ecx, m1
	mov edx, [m1_sz]
	int 0x80

	; get input byte
	mov eax, 3
	mov ebx, 0
	mov ecx, var
	mov edx, 1
	int 0x80

	; print output message
	mov eax, 4
	mov ebx, 1
	mov ecx, m2
	mov edx, [m2_sz]
	int 0x80

	; compare numbers
	mov al, [var]
	cmp al, [const]
	jl var_less

	mov eax, 4
	mov ebx, 1
	mov ecx, const
	mov edx, 2
	int 0x80
	jmp end

var_less:
	mov eax, 4
	mov ebx, 1
	mov ecx, var 
	mov edx, 2
	int 0x80

end:
	mov eax, 1
	mov ebx, 0
	int 0x80
