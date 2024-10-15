/*
	Program	_initlow.c
	Date	2002/7/14 .. 2002/8/15
	Copyright (C) 2002 by AKIYA

	システム初期化（デバッガ初期化＆起動）
*/

#include <machine.h>
#include "include\7750.h"

#pragma noregsave (_INIT_LOWLEVEL)

void _INIT_LOWLEVEL( void )
{
	dbg_ini();
	set_cr( get_cr()&0xcfffffff );
	set_imask(0);
/*	trapa(255);	/*dbg_mode_in();*/
}
