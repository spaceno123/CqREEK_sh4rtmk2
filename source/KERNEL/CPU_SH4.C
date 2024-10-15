/*
	Program	cpu_sh4.c
	Date	2002/7/28 .. 2002/8/16
	Copyright (C) 2002 by AKIYA

	プロセッサ依存コードをここで記述

	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	必ず、生成されたソースを精査して不都合が無いか確認すること！
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include "include\system.h"

#pragma inline_asm (_kernel_save_context)
int _kernel_save_context( VT_CTX *ctxbuf )
{
ofs_sp		.equ	4*0
ofs_pr		.equ	4*1
ofs_r0		.equ	4*2
ofs_r1		.equ	4*3
ofs_r2		.equ	4*4
ofs_r3		.equ	4*5
ofs_r4		.equ	4*6
ofs_r5		.equ	4*7
ofs_r6		.equ	4*8
ofs_r7		.equ	4*9
ofs_r8		.equ	4*10
ofs_r9		.equ	4*11
ofs_r10		.equ	4*12
ofs_r11		.equ	4*13
ofs_r12		.equ	4*14
ofs_r13		.equ	4*15
ofs_r14		.equ	4*16
ofs_gbr		.equ	4*17
ofs_macl	.equ	4*18
ofs_mach	.equ	4*19
ofs_fpscr	.equ	4*20
ofs_fpul	.equ	4*21
ofs_fr0		.equ	4*22
ofs_fr1		.equ	4*23
ofs_fr2		.equ	4*24
ofs_fr3		.equ	4*25
ofs_fr4		.equ	4*26
ofs_fr5		.equ	4*27
ofs_fr6		.equ	4*28
ofs_fr7		.equ	4*29
ofs_fr8		.equ	4*30
ofs_fr9		.equ	4*31
ofs_fr10	.equ	4*32
ofs_fr11	.equ	4*33
ofs_fr12	.equ	4*34
ofs_fr13	.equ	4*35
ofs_fr14	.equ	4*36
ofs_fr15	.equ	4*37
ofs_xf0		.equ	4*38
ofs_xf1		.equ	4*39
ofs_xf2		.equ	4*40
ofs_xf3		.equ	4*41
ofs_xf4		.equ	4*42
ofs_xf5		.equ	4*43
ofs_xf6		.equ	4*44
ofs_xf7		.equ	4*45
ofs_xf8		.equ	4*46
ofs_xf9		.equ	4*47
ofs_xf10	.equ	4*48
ofs_xf11	.equ	4*49
ofs_xf12	.equ	4*50
ofs_xf13	.equ	4*51
ofs_xf14	.equ	4*52
ofs_xf15	.equ	4*53
	;* r4=ctxbuf address *
	mov.l	r0,@(ofs_r0,r4)
	mov.l	r4,@(ofs_r4,r4)
	add	#ofs_fpscr,r4
	sts	fpscr,r0
	mov.l	r0,@r4
	swap.w	r0,r0		;fr=1,sz=0
	or	#H'20,r0	;
	not	r0,r0		;
	or	#H'10,r0	;
	not	r0,r0		;
	swap.w	r0,r0		;
	lds	r0,fpscr	;
	add	#((ofs_xf15+4)-ofs_fpscr)/2,r4
	add	#((ofs_xf15+4)-ofs_fpscr)/2,r4
	fmov.s	fr15,@-r4
	fmov.s	fr14,@-r4
	fmov.s	fr13,@-r4
	fmov.s	fr12,@-r4
	fmov.s	fr11,@-r4
	fmov.s	fr10,@-r4
	fmov.s	fr9,@-r4
	fmov.s	fr8,@-r4
	fmov.s	fr7,@-r4
	fmov.s	fr6,@-r4
	fmov.s	fr5,@-r4
	fmov.s	fr4,@-r4
	fmov.s	fr3,@-r4
	fmov.s	fr2,@-r4
	fmov.s	fr1,@-r4
	fmov.s	fr0,@-r4
	sts	fpscr,r0	;fr=0,sz=0
	swap.w	r0,r0		;
	xor	#H'20,r0	;
	swap.w	r0,r0		;
	lds	r0,fpscr	;
	fmov.s	fr15,@-r4
	fmov.s	fr14,@-r4
	fmov.s	fr13,@-r4
	fmov.s	fr12,@-r4
	fmov.s	fr11,@-r4
	fmov.s	fr10,@-r4
	fmov.s	fr9,@-r4
	fmov.s	fr8,@-r4
	fmov.s	fr7,@-r4
	fmov.s	fr6,@-r4
	fmov.s	fr5,@-r4
	fmov.s	fr4,@-r4
	fmov.s	fr3,@-r4
	fmov.s	fr2,@-r4
	fmov.s	fr1,@-r4
	fmov.s	fr0,@-r4
	sts.l	fpul,@-r4
	add	#-4,r4	;fpscr
	mov	@r4,r0		;fr=?,sz=?
	lds	r0,fpscr	;
	sts.l	mach,@-r4
	sts.l	macl,@-r4
	stc.l	gbr,@-r4
	mov.l	r14,@-r4
	mov.l	r13,@-r4
	mov.l	r12,@-r4
	mov.l	r11,@-r4
	mov.l	r10,@-r4
	mov.l	r9,@-r4
	mov.l	r8,@-r4
	mov.l	r7,@-r4
	mov.l	r6,@-r4
	mov.l	r5,@-r4
	add	#-4,r4	;r4
	mov.l	r3,@-r4
	mov.l	r2,@-r4
	mov.l	r1,@-r4
	add	#-4,r4	;r0
	sts.l	pr,@-r4
	mov.l	r15,@-r4
	mov	#0,r0
}

#pragma inline_asm (_kernel_load_context)
int _kernel_load_context( VT_CTX *ctxbuf, int rcf )
{
	;* r4=ctxbuf address, r5=return code *
	mov.l	r5,@(ofs_r0,r4)
	sts	fpscr,r0	;fr=0,sz=0
	swap.w	r0,r0		;
	not	r0,r0		;
	or	#H'30,r0	;
	not	r0,r0		;
	swap.w	r0,r0		;
	lds	r0,fpscr	;
	add	#ofs_fr0,r4
	fmov.s	@r4+,fr0
	fmov.s	@r4+,fr1
	fmov.s	@r4+,fr2
	fmov.s	@r4+,fr3
	fmov.s	@r4+,fr4
	fmov.s	@r4+,fr5
	fmov.s	@r4+,fr6
	fmov.s	@r4+,fr7
	fmov.s	@r4+,fr8
	fmov.s	@r4+,fr9
	fmov.s	@r4+,fr10
	fmov.s	@r4+,fr11
	fmov.s	@r4+,fr12
	fmov.s	@r4+,fr13
	fmov.s	@r4+,fr14
	fmov.s	@r4+,fr15
	sts	fpscr,r0	;fr=1,sz=0
	swap.w	r0,r0		;
	xor	#H'20,r0	;
	swap.w	r0,r0		;
	lds	r0,fpscr	;
	fmov.s	@r4+,fr0
	fmov.s	@r4+,fr1
	fmov.s	@r4+,fr2
	fmov.s	@r4+,fr3
	fmov.s	@r4+,fr4
	fmov.s	@r4+,fr5
	fmov.s	@r4+,fr6
	fmov.s	@r4+,fr7
	fmov.s	@r4+,fr8
	fmov.s	@r4+,fr9
	fmov.s	@r4+,fr10
	fmov.s	@r4+,fr11
	fmov.s	@r4+,fr12
	fmov.s	@r4+,fr13
	fmov.s	@r4+,fr14
	fmov.s	@r4+,fr15
	add	#-(ofs_xf15+4)/2,r4
	add	#-(ofs_xf15+4)/2,r4
	mov.l	@r4+,r15
	lds.l	@r4+,pr
	mov.l	@r4+,r0
	mov.l	@r4+,r1
	mov.l	@r4+,r2
	mov.l	@r4+,r3
	add	#4,r4
	mov.l	@r4+,r5
	mov.l	@r4+,r6
	mov.l	@r4+,r7
	mov.l	@r4+,r8
	mov.l	@r4+,r9
	mov.l	@r4+,r10
	mov.l	@r4+,r11
	mov.l	@r4+,r12
	mov.l	@r4+,r13
	mov.l	@r4+,r14
	ldc.l	@r4+,gbr
	lds.l	@r4+,macl
	lds.l	@r4+,mach
	lds.l	@r4+,fpscr
	lds.l	@r4+,fpul
	add	#-ofs_fr0,r4
	tst	r0,r0
	bf	?0
	mov	#-1,r0
?0
}

#pragma inline_asm (save_sregs)
static void save_sregs( void )
{
	stc.l	spc,@-sp
	stc.l	ssr,@-sp
	stc.l	sr,@-sp		; for BL=1
}

#pragma inline_asm (get_r1_bank)
static int get_r1_bank( void )
{
	stc	r1_bank,r0
}

#pragma inline_asm (load_sregs)
static void load_sregs( void )
{
	ldc.l	@sp+,sr		; BL=1
	ldc.l	@sp+,ssr
	ldc.l	@sp+,spc
}

FP _kernel_inthdl_table[VCT2INO(MAXVCTINO)+1];

#pragma interrupt (int_jmp)
static void int_jmp( void )
{
	/* MD=1,RB=0,BL=1,r1_bank=INTEVT */
	save_sregs();
	_kernel_inthdl_io_service( get_r1_bank() );
	load_sregs();
}

#pragma inline_asm (int_jmp_fnc)
static void int_jmp_fnc( void (*adr)(void) )
{
	;* MD=1,RB=1,BL=1,r1=INTEVT/8,r4=int_jmp *
	shll2	r1
	shll	r1
	sts.l	pr,@-sp	;!
	lds	r4,pr
	stc	sr,r0
	mov	#H'df,r4;
	swap.b	r4,r4	;
	swap.w	r4,r4	;
	and	r4,r0	;
	ldc	r0,sr	; RB=0
	;* MD=1,RB=0,BL=1,r1=INTEVT,pr=int_jmp *
	rts
	lds.l	@sp+,pr	;!
}

#pragma noregalloc (_kernel_inthdl_io)
void _kernel_inthdl_io( void )
{
	/* MD=1,RB=1,BL=1,r1=INTEVT/8 */
	int_jmp_fnc( int_jmp );
}	/* RTS,NOPの無駄がある */

FP _kernel_inthdl_table[] = {
				_kernel_inthdl_null,	/* 0x200 */
				_kernel_inthdl_null,	/* 0x220 */
				_kernel_inthdl_null,	/* 0x240 */
				_kernel_inthdl_null,	/* 0x260 */
				_kernel_inthdl_null,	/* 0x280 */
				_kernel_inthdl_null,	/* 0x2A0 */
				_kernel_inthdl_null,	/* 0x2C0 */
				_kernel_inthdl_null,	/* 0x2E0 */
				_kernel_inthdl_null,	/* 0x300 */
				_kernel_inthdl_null,	/* 0x320 */
				_kernel_inthdl_null,	/* 0x340 */
				_kernel_inthdl_null,	/* 0x360 */
				_kernel_inthdl_null,	/* 0x380 */
				_kernel_inthdl_null,	/* 0x3A0 */
				_kernel_inthdl_null,	/* 0x3C0 */
				_kernel_inthdl_null,	/* 0x3E0 */
				_kernel_inthdl_null,	/* 0x400 */
				_kernel_inthdl_null,	/* 0x420 */
				_kernel_inthdl_null,	/* 0x440 */
				_kernel_inthdl_null,	/* 0x460 */
				_kernel_inthdl_null,	/* 0x480 */
				_kernel_inthdl_null,	/* 0x4A0 */
				_kernel_inthdl_null,	/* 0x4C0 */
				_kernel_inthdl_null,	/* 0x4E0 */
				_kernel_inthdl_null,	/* 0x500 */
				_kernel_inthdl_null,	/* 0x520 */
				_kernel_inthdl_null,	/* 0x540 */
				_kernel_inthdl_null,	/* 0x560 */
				_kernel_inthdl_null,	/* 0x580 */
				_kernel_inthdl_null,	/* 0x5A0 */
				_kernel_inthdl_null,	/* 0x5C0 */
				_kernel_inthdl_null,	/* 0x5E0 */
				_kernel_inthdl_null,	/* 0x600 */
				_kernel_inthdl_null,	/* 0x620 */
				_kernel_inthdl_null,	/* 0x640 */
				_kernel_inthdl_null,	/* 0x660 */
				_kernel_inthdl_null,	/* 0x680 */
				_kernel_inthdl_null,	/* 0x6A0 */
				_kernel_inthdl_null,	/* 0x6C0 */
				_kernel_inthdl_null,	/* 0x6E0 */
				_kernel_inthdl_null,	/* 0x700 */
				_kernel_inthdl_null,	/* 0x720 */
				_kernel_inthdl_null,	/* 0x740 */
				_kernel_inthdl_null	/* 0x760 */
				};
