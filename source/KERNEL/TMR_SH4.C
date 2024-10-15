/*
	Program	tmr_sh4.c
	Date	2002/8/4 .. 2002/8/15
	Copyright (C) 2002 by AKIYA

	プロセッサ依存のシステム時刻の更新をここで記述
*/

#include "include\system.h"

#include "include\7750.h"

/* === １ｍｓｅｃ周期タイマー === */

#define CNT1MS ((33333300*6)/1000)

void int_tmr();

/* １ｍｓｅｃ周期タイマー設定・起動（ＷＤＣを使用） */
void ini_tmr( void )
{
	T_DINH dinh;

	CPG.WTCSR = 0xa505;	/* stop, CKS=5(/1024) */
	dinh.inhatr = TA_HLNG;
	dinh.inthdr = int_tmr;
	def_inh( 0x560, &dinh );
	INTC.IPRB.BIT.UU = 7;
	CPG.WTCNT = 0x5a00 | (0x100-(CNT1MS/1024));
	CPG.WTCSR = 0xa585;	/* start, CKS=5(/1024) */
}

/* 割り込みハンドラ */
void int_tmr( void )
{
	static int flag = 0;			/* 再入抑止 */

	CPG.WTCNT = 0x5a00 | (0x100-(CNT1MS/1024));
	CPG.WTCSR = 0xa585;			/* 割り込み要因クリア */
	if ( flag++ == 0 ) {
		_kernel_cpu_unblock();		/* ブロック解除 */
		iunl_cpu();			/* 割り込み許可 */
		isig_tim();
	}
	flag--;
}
