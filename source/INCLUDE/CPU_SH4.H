/*
	Header	cpu_sh4.h
	Date	2002/7/17 .. 2002/8/15
	Copyright (C) 2002 by AKIYA

	プロセッサに依存する要素をここで定義
*/

#ifndef	_CPU_SH4_H_
#define	_CPU_SH4_H_

#include <machine.h>

/* ＩＤと構造体ポインタの関係マクロ */
/* （構造体のポインタを加工してＩＤとして使用する為） */
#define	ID2P(aaa)	((VP)((aaa)*2))
#define	P2ID(aaa)	(((UW)(aaa))/2)

/* 割り込みベクタと割り込みナンバーの関係マクロ */
#define MINVCTINO	(0x200)
#define	MAXVCTINO	(0x760)
#define	VCT2INO(aaa)	(((aaa)-MINVCTINO)>>5)
#define	INO2VCT(aaa)	(((aaa)<<5)+MINVCTINO)

/* 割り込み禁止・許可マクロ */
#define	_kernel_cpu_block()	set_cr(get_cr()|0x10000000)	/* 厳密には問題あり */
#define	_kernel_cpu_unblock()	set_cr(get_cr()&0xefffffff)	/* ちょっと問題あり */
#define	_kernel_int_disable()	set_imask(8)
#define	_kernel_int_enable()	set_imask(0)

/* 開始アドレスセット */
#define _kernel_set_adr(aaa,bbb)	((aaa)->ctxbuf.pr=(bbb))
#define _kernel_set_stk(aaa,bbb)	((aaa)->ctxbuf.sp=(bbb))

/* コンテキストバッファ構造体定義 */
typedef struct vt_ctx {
	long	sp;
	long	pr;
	long	r0;
	long	r1;
	long	r2;
	long	r3;
	long	r4;
	long	r5;
	long	r6;
	long	r7;
	long	r8;
	long	r9;
	long	r10;
	long	r11;
	long	r12;
	long	r13;
	long	r14;
	long	gbr;
	long	macl;
	long	mach;
	long	fpscr;
	long	fpul;
	long	fr0;
	long	fr1;
	long	fr2;
	long	fr3;
	long	fr4;
	long	fr5;
	long	fr6;
	long	fr7;
	long	fr8;
	long	fr9;
	long	fr10;
	long	fr11;
	long	fr12;
	long	fr13;
	long	fr14;
	long	fr15;
	long	xf0;
	long	xf1;
	long	xf2;
	long	xf3;
	long	xf4;
	long	xf5;
	long	xf6;
	long	xf7;
	long	xf8;
	long	xf9;
	long	xf10;
	long	xf11;
	long	xf12;
	long	xf13;
	long	xf14;
	long	xf15;
} VT_CTX;

#endif	/* _CPU_SH4_H_ */
