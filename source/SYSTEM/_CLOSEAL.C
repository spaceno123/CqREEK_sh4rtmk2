/* ADJ-702-248 (HITACH SuperH RISC engine C/C++ compiler user's manual) p130 */

#include <stdio.h>

#ifdef __cplusplus
extern C
#endif

void _CLOSEALL( void )
{
	int i;

	for ( i = 0; i < _NFILE; i++ )
		if( _iob[i]._ioflag1 & (_IOREAD|_IOWRITE|_IORW) )
			fclose( &_iob[i] );
}
