%include "asm_io.inc"
%define size 64 

SECTION .data
	output1 db "Indice: ", 0
	output2 db " | Tamanho da Classe: ", 0
	SEED	dq 171	; SEED INICIAL

SECTION .bss
	class resd 64 ; Vetor

SECTION .text
global main
main:

	mov ebx, SEED
	mov edx, 0
	do:
		mov ecx, ebx
		mov eax, ebx
		shr ecx, 0
		xor eax, ecx
		shr ecx, 2
		xor eax, ecx
		shr ecx, 3
		xor eax, ecx
		shr ecx, 5
		xor eax, ecx
		shr ecx, 8
		xor eax, ecx
		shr ecx, 15
		xor eax, ecx
		and eax, 1

		shl eax, 15
		shr ebx, 1
		or eax, ebx
		mov ebx, eax

		and eax, 0x003F
	
		add dword [class + eax*4], 1

		inc edx
		cmp edx, 65536
	jne do

	mov ecx, 0
	results:
		mov eax, output1
		call print_string

		mov eax, ecx
		call print_int

		mov eax, output2
		call print_string

		mov eax, [class + ecx*4]
		call print_int

		call print_nl
		inc ecx
		cmp ecx, 64 
	jne results

	mov ebx, 0
	mov eax, 1
	int 0x80