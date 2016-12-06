; $Id: toc.asm 956 2008-10-19 22:24:23Z hsc $

;******************************************************************************
;* Betriebssysteme                                                            *
;*----------------------------------------------------------------------------*
;*                                                                            *
;*                               T O C . A S M                                *
;*                                                                            *
;*----------------------------------------------------------------------------*
;*
;******************************************************************************

%include "machine/toc.inc"

; EXPORTIERTE FUNKTIONEN

[GLOBAL toc_switch]
[GLOBAL toc_go]

; IMPLEMENTIERUNG DER FUNKTIONEN

[SECTION .text]

; TOC_GO : Startet den ersten Prozess ueberhaupt.
;
; C Prototyp: void toc_go (struct toc* regs);
toc_go:
; Hier muesst ihr selbst Code vervollstaendigen
	;push ebp
	;mov  ebp,esp
	mov eax, [esp+4]
	mov ebx, [eax+ebx_offset]
	mov esi, [eax+esi_offset]
	mov edi, [eax+edi_offset]
	mov esp, [eax+esp_offset]
	mov ebp, [eax+ebp_offset]
	;pop ebp
ret
; TOC_SWITCH : Prozessumschaltung. Der aktuelle Registersatz wird     
;              gesichert und der Registersatz des neuen "thread of control"
;              wird in den Prozessor eingelesen.  
;
; C Prototyp: void toc_switch (struct toc* regs_now,
;                              struct toc* reg_then);
toc_switch:
; Hier muesst ihr selbst Code vervollstaendigen
	mov [esp+ebx_offset],esp
	mov [esp+esi_offset],esi
	mov [esp+edi_offset],edi
	mov [esp+ebp_offset],ebp
	mov [esp+esp_offset],esp

	add esp, 4
	mov ebx, [esp+ebx_offset]
	mov esi, [esp+esi_offset]
	mov edi, [esp+edi_offset]
	mov ebp, [esp+ebp_offset]
	mov esp, [esp+esp_offset]








