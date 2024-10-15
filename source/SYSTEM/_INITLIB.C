/* ADJ-702-248 (HITACH SuperH RISC engine C/C++ compiler user's manual) p127 */

#include <errno.h>

#ifdef __cplusplus
extern C{
#endif

void _INIT_LOWLEVEL(void);
void _INIT_IOLIB(void);
void _INIT_OTHERLIB(void);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern C
#endif

void _INITLIB( void )
{
	errno=0;
	_INIT_LOWLEVEL();
	_INIT_IOLIB();
	_INIT_OTHERLIB();
}
