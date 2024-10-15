/*
	Program	maintask.c
	Date	2002/8/4 .. 2002/8/15
	Copyright (C) 2002 by AKIYA
*/

#include "include\system.h"

#define MAIN_TCB( ent, pri, ssz ) VT_TCB main_tcb = {{NULL,NULL},\
	(TA_HLNG),(NULL),(ent),(pri),(ssz),NULL}

#define MAIN_TASK_PRI 1		/* 優先順位 */
#define MAIN_TASK_SSZ 4096	/* スタックサイズ */
#define TEST_TASK_PRI 2		/* 優先順位 */
#define TEST_TASK_SSZ 4096	/* スタックサイズ */

void main_task( VP_INT );
void test_task( VP_INT );

/* task tcb */
MAIN_TCB( main_task, MAIN_TASK_PRI, MAIN_TASK_SSZ );
VT_TCB test_tcb;

union led{
	unsigned char data;
	struct {
		int	:3;
		unsigned int	dot:1;
		unsigned int	num:4;
	} BIT;
};

#define LED (*(volatile union led *)0xb4000000)
volatile union led led_dat = 0x0;

void main_task( VP_INT exinf )
{
	{
		T_CTSK	pk_ctsk;

		pk_ctsk.tskatr = TA_HLNG | TA_ACT;
		pk_ctsk.exinf = NULL;
		pk_ctsk.task = (VP)test_task;
		pk_ctsk.itskpri = TEST_TASK_PRI;
		pk_ctsk.stksz = TEST_TASK_SSZ;
		pk_ctsk.stk = NULL;
		cre_tsk( P2ID(&test_tcb), &pk_ctsk );
	}
	for ( ; ; ) {
		dis_dsp();
		if ( ++led_dat.BIT.num > 9 )
			led_dat.BIT.num = 0;
		LED.data = led_dat.data;
		ena_dsp();
		dly_tsk(100);
	}
}

void test_task( VP_INT exinf )
{
	for ( ; ; ) {
		dly_tsk(500);
		dis_dsp();
		led_dat.BIT.dot ^= 1;
		LED.data = led_dat.data;
		ena_dsp();
	}
}

