/*
	Program	_setup.c
	Date	2002/7/14 .. 2002/8/15
	Copyright (C) 2002 by AKIYA

	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	必ず、生成されたソースを精査して不都合が無いか確認すること！
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <machine.h>
#include "include\7750.h"

void _SETUP( void );
void _INIT( void );

void dbg_ini( void );
void dbg_sci_err( void );
void dbg_sci_rxd( void );
void dbg_sci_err( void );
void dbg_sci_txd( void );
void dbg_mode_in( void );

void _kernel_inthdl_io( void );

/* ＲＯＭエリアの最後とスタック定義 */
#pragma section ce	/* Pce,Bce */
#pragma inline_asm (code_end)
void code_end( void )
{
}
#define STACKSIZE 1024*1024
typedef union {
	long dummy;
	char stack[STACKSIZE];
} STACK;
STACK stack_area;

/* リセットスタート */
#pragma section rst	/* Prst */

#pragma inline_asm (jmp_rst)
static void jmp_rst( int expevt )
{
	;* r4=expevt *
	tst	r4,r4
	bf	?0
	bra	__SETUP
	nop
?0
	stc	vbr,r1
	shlr2	r4
	shlr	r4
	mov.l	#_vct_tbl-_vbr_adr+H'a0000000,r0
	add	r4,r0
	mov.l	@(r0,r1),r1
	jmp	@r1
	mov	r4,r1
}

#pragma noregalloc (vbr_adr)
void vbr_adr( void )
{
	jmp_rst( EXP.EXPEVT );
}	/* RTS,NOPの無駄がある */

/* 一般例外 */
#pragma section	exc	/* Pexc */

#pragma inline_asm (jmp_exc)
static void jmp_exc( int expevt )
{
	;* r4=expevt *
	stc	vbr,r1
	shlr2	r4
	shlr	r4
	mov.l	#_vct_tbl-_vbr_adr,r0
	add	r4,r0
	mov.l	@(r0,r1),r1
	jmp	@r1
	mov	r4,r1
}

#pragma noregalloc (vof_100)
void vof_100( void )
{
	jmp_exc( EXP.EXPEVT );
}	/* RTS,NOPの無駄がある */

/* ＴＬＢミス */
#pragma	section	tms	/* Ptms */

#pragma inline_asm (jmp_tms)
static void jmp_tms( int expevt )
{
	;* r4=expevt *
	stc	vbr,r1
	shlr2	r4
	shlr	r4
	mov.l	#_vct_tbl-_vbr_adr,r0
	add	r4,r0
	mov.l	@(r0,r1),r1
	jmp	@r1
	mov	r4,r1
}

#pragma noregalloc (vof_400)
void vof_400( void )
{
	jmp_tms( EXP.EXPEVT );
}	/* RTS,NOPの無駄がある */

/* 割り込み */
#pragma section	itr	/* Pitr */

#pragma inline_asm (jmp_itr)
static void jmp_itr( int intevt )
{
	;* r4=intevt *
	stc	vbr,r1
	shlr2	r4
	shlr	r4
	mov.l	#_vct_tbl-_vbr_adr,r0
	add	r4,r0
	mov.l	@(r0,r1),r1
	jmp	@r1
	mov	r4,r1
}

#pragma noregalloc (vof_600)
void vof_600( void )
{
	jmp_itr( EXP.INTEVT );
}	/* RTS,NOPの無駄がある */

/* トラップ命令 */
#pragma section trp	/* Ptrp */

#pragma inline_asm (jmp_tra)
static void jmp_tra( int tra )
{
	;* r4=tra  *
	stc	vbr,r1
	mov.l	#_tra_tbl-_vbr_adr,r0
	add	r4,r0
	mov.l	@(r0,r1),r1
	jmp	@r1
	mov	r4,r1
}

#pragma noregalloc (tra_fnc)
void tra_fnc( void )
{
	jmp_tra( EXP.TRA );
}	/* RTS,NOPの無駄がある */

#pragma noregalloc (vct_non)
void vct_non( int ofs )
{
	ofs *= 8;
	for ( ; ; );
}

#pragma noregalloc (tra_non)
void tra_non( int ofs )
{
	ofs /= 2;
	for ( ; ; );
}

/* 初期化コード */
#pragma section sup	/* Psup */

#pragma inline_asm (get_pca)
static int get_pca( void )
{
	mova	@(0,pc),r0
}

#pragma inline_asm (set_sp)
static int set_sp( char *stack )
{
	mov	r4,sp
}

#pragma inline_asm (jmp_p2)
static void jmp_p2( void )
{
	mov.l	#?1,r0
	mov	#-1,r1		;r1=H'ffffffff
	shlr2	r1		;r1=H'3fffffff
	shlr	r1		;r1=H'1fffffff
	and	r0,r1		;mask
	mov	#H'a0,r0	;r0=H'ffffffa0
	shll8	r0		;r0=H'ffffa000
	shll16	r0		;r0=H'a0000000
	or	r1,r0		;p2 area
	jmp	@r0
	nop
?1
}

#pragma inline_asm(nop_8)
static void nop_8( void )
{
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
}

#pragma noregalloc (_SETUP)
void _SETUP( void )
{
	CPG.WTCSR = 0xa500;

	/* EM0   IO  14QSX HZ 0BE 5BE 6BE DMT B */
	/* 000---00--00000-00 000 000 000 011-0 */
	BSC.BCR1.LONG = 0x0000000c;

	/* A0SZ A6SZ A5SZ A4SZ A3SZ A2SZ A1SZ  P */
	/*  10   11   01   01   00   11   10  -0 */
	BSC.BCR2.WORD = 0xb538;

	/*  DMA 6IW 5IW 4IW 3IW 2IW 1IW 0IW */
	/* -000-000-000-001-000-001-001-001 */
	BSC.WCR1.LONG = 0x00010111;

	/* A6W A6B A5W A5B A4W A3W A2W A1W A0W A0B */
	/* 000 100 001 000 101-001-010 100 100 000 */
	BSC.WCR2.LONG = 0x108a2520;

	/*      SH6 SH5 SH4 SH3 SH2 SH1 SH0 */
	/* -----000-001-001-000-001-001-001 */
	BSC.WCR3.LONG = 0x00110111;

	/* (64msec/4096=15.625usec) > CKIO/16*65 */
	BSC.RTCOR = 0xa500 | 0x41;

	if ( (get_pca() & 0x1f000000) < 0x04000000 ) {
		unsigned long *sp;
		unsigned long *dp;
		unsigned long cc;

		/* 0 0 010---0-011-01 001 000 0 11 0 010 1 0 0 */
		BSC.MCR.LONG = 0x10192194;

		(*(volatile unsigned char *)0xff90008c) = 0xaa;

		/* F E CKS V E L */
		/* 0 0 010 0 0 0 */
		BSC.RTCSR.WORD = 0xa500 | 0x10;

		BSC.RFCR = 0xa400 | 0x00;
		while ( BSC.RFCR < 8 );

		/* 0 1 010---0-011-01 001 000 0 11 0 010 1 0 0 */
		BSC.MCR.LONG = 0x50192194;

		(*(volatile unsigned char *)0xff90008c) = 0xaa;

		sp = (unsigned long *)0xa0000000;
		dp = (unsigned long *)0xa8000000;
		cc = ((int)code_end-(int)vbr_adr)>>2;
		while ( cc-- )
			*dp++ = *sp++;
	}

	set_sp( &(stack_area.stack[STACKSIZE]) );
	stack_area.dummy = STACKSIZE;

	set_vbr( (void **)vbr_adr );

	jmp_p2();
	CACHE.CCR.LONG = 0x00000909;	/*--0---1--10-0-1001 */
	nop_8();

	_INIT();
}

#pragma inline_asm (charget,charput)

char charget( void )
{
	.import	dbg_usr_getc, dbg_usr_putc
	mov.l	#dbg_usr_getc,r1
?1	jsr	@r1
	nop
	;
	bf	?1
	;* echo .. *
	mov.l	#dbg_usr_putc,r1
	jsr	@r1
	nop
	;
	cmp/eq	#H'0d,r0
	bf	?2
	jsr	@r1
	mov	#H'0a,r0
	;
	mov	#H'0d,r0
?2	;* .. echo *
}

void charput( char c )
{
	mov	r4,r0
	mov.l	#dbg_usr_putc,r1
?1	jsr	@r1
	and	#H'ff,r0
	;
	bf	?1
}

/* ベクタテーブル */
void (*vct_tbl[])() = {
			_SETUP,	/* 000 */
			vct_non,	/* 020 */
			vct_non,	/* 040 */
			vct_non,	/* 060 */
			vct_non,	/* 080 */
			vct_non,	/* 0a0 */
			vct_non,	/* 0c0 */
			vct_non,	/* 0e0 */
			vct_non,	/* 100 */
			vct_non,	/* 120 */
			vct_non,	/* 140 */
			tra_fnc,	/*vct_non	/* 160 */
			vct_non,	/* 180 */
			vct_non,	/* 1a0 */
			vct_non,	/* 1c0 */
			vct_non,	/* 1e0 */
			vct_non,	/* 200 */
			vct_non,	/* 220 */
			vct_non,	/* 240 */
			vct_non,	/* 260 */
			vct_non,	/* 280 */
			vct_non,	/* 2a0 */
			vct_non,	/* 2c0 */
			vct_non,	/* 2e0 */
			vct_non,	/* 300 */
			vct_non,	/* 320 */
			vct_non,	/* 340 */
			vct_non,	/* 360 */
			vct_non,	/* 380 */
			vct_non,	/* 3a0 */
			vct_non,	/* 3c0 */
			vct_non,	/* 3e0 */
			vct_non,	/* 400 */
			vct_non,	/* 420 */
			vct_non,	/* 440 */
			vct_non,	/* 460 */
			vct_non,	/* 480 */
			vct_non,	/* 4a0 */
			vct_non,	/* 4c0 */
			vct_non,	/* 4e0 */
			vct_non,	/* 500 */
			vct_non,	/* 520 */
			vct_non,	/* 540 */
			_kernel_inthdl_io,/*vct_non,	/* 560 */
			vct_non,	/* 580 */
			vct_non,	/* 5a0 */
			vct_non,	/* 5c0 */
			vct_non,	/* 5e0 */
			vct_non,	/* 600 */
			vct_non,	/* 620 */
			vct_non,	/* 640 */
			vct_non,	/* 660 */
			vct_non,	/* 680 */
			vct_non,	/* 6a0 */
			vct_non,	/* 6c0 */
			vct_non,	/* 6e0 */
			dbg_sci_err,	/*vct_non	/* 700 */
			dbg_sci_rxd,	/*vct_non	/* 720 */
			dbg_sci_err,	/*vct_non	/* 740 */
			dbg_sci_txd,	/*vct_non	/* 760 */
			vct_non,	/* 780 */
			vct_non,	/* 7a0 */
			vct_non,	/* 7c0 */
			vct_non,	/* 7e0 */
			vct_non,	/* 800 */
			vct_non,	/* 820 */
			vct_non,	/* 840 */
			vct_non,	/* 860 */
			vct_non,	/* 880 */
			vct_non,	/* 8a0 */
			vct_non,	/* 8c0 */
			vct_non		/* 8e0 */
			};

/* トラップテーブル */
void (*tra_tbl[])() = {
			tra_non,	/* 000(00:  0) */
			tra_non,	/* 004(01:  1) */
			tra_non,	/* 008(02:  2) */
			tra_non,	/* 00c(03:  3) */
			tra_non,	/* 010(04:  4) */
			tra_non,	/* 014(05:  5) */
			tra_non,	/* 018(06:  6) */
			tra_non,	/* 01c(07:  7) */
			tra_non,	/* 020(08:  8) */
			tra_non,	/* 024(09:  9) */
			tra_non,	/* 028(0a: 10) */
			tra_non,	/* 02c(0b: 11) */
			tra_non,	/* 030(0c: 12) */
			tra_non,	/* 034(0d: 13) */
			tra_non,	/* 038(0e: 14) */
			tra_non,	/* 03c(0f: 15) */
			tra_non,	/* 040(10: 16) */
			tra_non,	/* 044(11: 17) */
			tra_non,	/* 048(12: 18) */
			tra_non,	/* 04c(13: 19) */
			tra_non,	/* 050(14: 20) */
			tra_non,	/* 054(15: 21) */
			tra_non,	/* 058(16: 22) */
			tra_non,	/* 05c(17: 23) */
			tra_non,	/* 060(18: 24) */
			tra_non,	/* 064(19: 25) */
			tra_non,	/* 068(1a: 26) */
			tra_non,	/* 06c(1b: 27) */
			tra_non,	/* 070(1c: 28) */
			tra_non,	/* 074(1d: 29) */
			tra_non,	/* 078(1e: 30) */
			tra_non,	/* 07c(1f: 31) */
			tra_non,	/* 080(20: 32) */
			tra_non,	/* 084(21: 33) */
			tra_non,	/* 088(22: 34) */
			tra_non,	/* 08c(23: 35) */
			tra_non,	/* 090(24: 36) */
			tra_non,	/* 094(25: 37) */
			tra_non,	/* 098(26: 38) */
			tra_non,	/* 09c(27: 39) */
			tra_non,	/* 0a0(28: 40) */
			tra_non,	/* 0a4(29: 41) */
			tra_non,	/* 0a8(2a: 42) */
			tra_non,	/* 0ac(2b: 43) */
			tra_non,	/* 0b0(2c: 44) */
			tra_non,	/* 0b4(2d: 45) */
			tra_non,	/* 0b8(2e: 46) */
			tra_non,	/* 0bc(2f: 47) */
			tra_non,	/* 0c0(30: 48) */
			tra_non,	/* 0c4(31: 49) */
			tra_non,	/* 0c8(32: 50) */
			tra_non,	/* 0cc(33: 51) */
			tra_non,	/* 0d0(34: 52) */
			tra_non,	/* 0d4(35: 53) */
			tra_non,	/* 0d8(36: 54) */
			tra_non,	/* 0dc(37: 55) */
			tra_non,	/* 0e0(38: 56) */
			tra_non,	/* 0e4(39: 57) */
			tra_non,	/* 0e8(3a: 58) */
			tra_non,	/* 0ec(3b: 59) */
			tra_non,	/* 0f0(3c: 60) */
			tra_non,	/* 0f4(3d: 61) */
			tra_non,	/* 0f8(3e: 62) */
			tra_non,	/* 0fc(3f: 63) */
			tra_non,	/* 100(40: 64) */
			tra_non,	/* 104(41: 65) */
			tra_non,	/* 108(42: 66) */
			tra_non,	/* 10c(43: 67) */
			tra_non,	/* 110(44: 68) */
			tra_non,	/* 114(45: 69) */
			tra_non,	/* 118(46: 70) */
			tra_non,	/* 11c(47: 71) */
			tra_non,	/* 120(48: 72) */
			tra_non,	/* 124(49: 73) */
			tra_non,	/* 128(4a: 74) */
			tra_non,	/* 12c(4b: 75) */
			tra_non,	/* 130(4c: 76) */
			tra_non,	/* 134(4d: 77) */
			tra_non,	/* 138(4e: 78) */
			tra_non,	/* 13c(4f: 79) */
			tra_non,	/* 140(50: 80) */
			tra_non,	/* 144(51: 81) */
			tra_non,	/* 148(52: 82) */
			tra_non,	/* 14c(53: 83) */
			tra_non,	/* 150(54: 84) */
			tra_non,	/* 154(55: 85) */
			tra_non,	/* 158(56: 86) */
			tra_non,	/* 15c(57: 87) */
			tra_non,	/* 160(58: 88) */
			tra_non,	/* 164(59: 89) */
			tra_non,	/* 168(5a: 90) */
			tra_non,	/* 16c(5b: 91) */
			tra_non,	/* 170(5c: 92) */
			tra_non,	/* 174(5d: 93) */
			tra_non,	/* 178(5e: 94) */
			tra_non,	/* 17c(5f: 95) */
			tra_non,	/* 180(60: 96) */
			tra_non,	/* 184(61: 97) */
			tra_non,	/* 188(62: 98) */
			tra_non,	/* 18c(63: 99) */
			tra_non,	/* 190(64:100) */
			tra_non,	/* 194(65:101) */
			tra_non,	/* 198(66:102) */
			tra_non,	/* 19c(67:103) */
			tra_non,	/* 1a0(68:104) */
			tra_non,	/* 1a4(69:105) */
			tra_non,	/* 1a8(6a:106) */
			tra_non,	/* 1ac(6b:107) */
			tra_non,	/* 1b0(6c:108) */
			tra_non,	/* 1b4(6d:109) */
			tra_non,	/* 1b8(6e:110) */
			tra_non,	/* 1bc(6f:111) */
			tra_non,	/* 1c0(70:112) */
			tra_non,	/* 1c4(71:113) */
			tra_non,	/* 1c8(72:114) */
			tra_non,	/* 1cc(73:115) */
			tra_non,	/* 1d0(74:116) */
			tra_non,	/* 1d4(75:117) */
			tra_non,	/* 1d8(76:118) */
			tra_non,	/* 1dc(77:119) */
			tra_non,	/* 1e0(78:120) */
			tra_non,	/* 1e4(79:121) */
			tra_non,	/* 1e8(7a:122) */
			tra_non,	/* 1ec(7b:123) */
			tra_non,	/* 1f0(7c:124) */
			tra_non,	/* 1f4(7d:125) */
			tra_non,	/* 1f8(7e:126) */
			tra_non,	/* 1fc(7f:127) */
			tra_non,	/* 200(80:128) */
			tra_non,	/* 204(81:129) */
			tra_non,	/* 208(82:130) */
			tra_non,	/* 20c(83:131) */
			tra_non,	/* 210(84:132) */
			tra_non,	/* 214(85:133) */
			tra_non,	/* 218(86:134) */
			tra_non,	/* 21c(87:135) */
			tra_non,	/* 220(88:136) */
			tra_non,	/* 224(89:137) */
			tra_non,	/* 228(8a:138) */
			tra_non,	/* 22c(8b:139) */
			tra_non,	/* 230(8c:140) */
			tra_non,	/* 234(8d:141) */
			tra_non,	/* 238(8e:142) */
			tra_non,	/* 23c(8f:143) */
			tra_non,	/* 240(90:144) */
			tra_non,	/* 244(91:145) */
			tra_non,	/* 248(92:146) */
			tra_non,	/* 24c(93:147) */
			tra_non,	/* 250(94:148) */
			tra_non,	/* 254(95:149) */
			tra_non,	/* 258(96:150) */
			tra_non,	/* 25c(97:151) */
			tra_non,	/* 260(98:152) */
			tra_non,	/* 264(99:153) */
			tra_non,	/* 268(9a:154) */
			tra_non,	/* 26c(9b:155) */
			tra_non,	/* 270(9c:156) */
			tra_non,	/* 274(9d:157) */
			tra_non,	/* 278(9e:158) */
			tra_non,	/* 27c(9f:159) */
			tra_non,	/* 280(a0:160) */
			tra_non,	/* 284(a1:161) */
			tra_non,	/* 288(a2:162) */
			tra_non,	/* 28c(a3:163) */
			tra_non,	/* 290(a4:164) */
			tra_non,	/* 294(a5:165) */
			tra_non,	/* 298(a6:166) */
			tra_non,	/* 29c(a7:167) */
			tra_non,	/* 2a0(a8:168) */
			tra_non,	/* 2a4(a9:169) */
			tra_non,	/* 2a8(aa:170) */
			tra_non,	/* 2ac(ab:171) */
			tra_non,	/* 2b0(ac:172) */
			tra_non,	/* 2b4(ad:173) */
			tra_non,	/* 2b8(ae:174) */
			tra_non,	/* 2bc(af:175) */
			tra_non,	/* 2c0(b0:176) */
			tra_non,	/* 2c4(b1:177) */
			tra_non,	/* 2c8(b2:178) */
			tra_non,	/* 2cc(b3:179) */
			tra_non,	/* 2d0(b4:180) */
			tra_non,	/* 2d4(b5:181) */
			tra_non,	/* 2d8(b6:182) */
			tra_non,	/* 2dc(b7:183) */
			tra_non,	/* 2e0(b8:184) */
			tra_non,	/* 2e4(b9:185) */
			tra_non,	/* 2e8(ba:186) */
			tra_non,	/* 2ec(bb:187) */
			tra_non,	/* 2f0(bc:188) */
			tra_non,	/* 2f4(bd:189) */
			tra_non,	/* 2f8(be:190) */
			tra_non,	/* 2fc(bf:191) */
			tra_non,	/* 300(c0:192) */
			tra_non,	/* 304(c1:193) */
			tra_non,	/* 308(c2:194) */
			tra_non,	/* 30c(c3:195) */
			tra_non,	/* 310(c4:196) */
			tra_non,	/* 314(c5:197) */
			tra_non,	/* 318(c6:198) */
			tra_non,	/* 31c(c7:199) */
			tra_non,	/* 320(c8:200) */
			tra_non,	/* 324(c9:201) */
			tra_non,	/* 328(ca:202) */
			tra_non,	/* 32c(cb:203) */
			tra_non,	/* 330(cc:204) */
			tra_non,	/* 334(cd:205) */
			tra_non,	/* 338(ce:206) */
			tra_non,	/* 33c(cf:207) */
			tra_non,	/* 340(d0:208) */
			tra_non,	/* 344(d1:209) */
			tra_non,	/* 348(d2:210) */
			tra_non,	/* 34c(d3:211) */
			tra_non,	/* 350(d4:212) */
			tra_non,	/* 354(d5:213) */
			tra_non,	/* 358(d6:214) */
			tra_non,	/* 35c(d7:215) */
			tra_non,	/* 360(d8:216) */
			tra_non,	/* 364(d9:217) */
			tra_non,	/* 368(da:218) */
			tra_non,	/* 36c(db:219) */
			tra_non,	/* 370(dc:220) */
			tra_non,	/* 374(dd:221) */
			tra_non,	/* 378(de:222) */
			tra_non,	/* 37c(df:223) */
			tra_non,	/* 380(e0:224) */
			tra_non,	/* 384(e1:225) */
			tra_non,	/* 388(e2:226) */
			tra_non,	/* 38c(e3:227) */
			tra_non,	/* 390(e4:228) */
			tra_non,	/* 394(e5:229) */
			tra_non,	/* 398(e6:230) */
			tra_non,	/* 39c(e7:231) */
			tra_non,	/* 3a0(e8:232) */
			tra_non,	/* 3a4(e9:233) */
			tra_non,	/* 3a8(ea:234) */
			tra_non,	/* 3ac(eb:235) */
			tra_non,	/* 3b0(ec:236) */
			tra_non,	/* 3b4(ed:237) */
			tra_non,	/* 3b8(ee:238) */
			tra_non,	/* 3bc(ef:239) */
			tra_non,	/* 3c0(f0:240) */
			tra_non,	/* 3c4(f1:241) */
			tra_non,	/* 3c8(f2:242) */
			tra_non,	/* 3cc(f3:243) */
			tra_non,	/* 3d0(f4:244) */
			tra_non,	/* 3d4(f5:245) */
			tra_non,	/* 3d8(f6:246) */
			tra_non,	/* 3dc(f7:247) */
			tra_non,	/* 3e0(f8:248) */
			tra_non,	/* 3e4(f9:249) */
			tra_non,	/* 3e8(fa:250) */
			tra_non,	/* 3ec(fb:251) */
			tra_non,	/* 3f0(fc:252) */
			tra_non,	/* 3f4(fd:253) */
			tra_non,	/* 3f8(fe:254) */
			dbg_mode_in	/*tra_non	/* 3fc(ff:255) */
			};

