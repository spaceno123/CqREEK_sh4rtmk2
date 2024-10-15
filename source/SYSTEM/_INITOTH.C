/* ADJ-702-248 (HITACH SuperH RISC engine C/C++ compiler user's manual) p129 */

#include <stddef.h>

extern char *_s1ptr;
extern void srand( unsigned int );

#ifdef __cplusplus
extern C
#endif

void _INIT_OTHERLIB( void )
{
	srand( 1 );
	_s1ptr = NULL;
}
