/* ADJ-702-248 (HITACH SuperH RISC engine C/C++ compiler user's manual) p128 */

#include <stdio.h>

#ifdef __cplusplus
extern C
#endif

void _INIT_IOLIB(void)
{
	FILE *fp;

	for ( fp = _iob; fp < _iob+_NFILE; fp++ ){
		fp->_bufptr = NULL;
		fp->_bufcnt = 0;
		fp->_buflen = 0;
		fp->_bufbase = NULL;
		fp->_ioflag1 = 0;
		fp->_ioflag2 = 0;
		fp->_iofd = 0;
	}

	if ( freopen( "stdin", "r", stdin ) == NULL )
		stdin->_ioflag1 = 0xff;
	stdin->_ioflag1 |= _IOUNBUF;

	if ( freopen( "stdout", "w", stdout ) == NULL )
		stdout->_ioflag1 = 0xff;
	stdout->_ioflag1 |= _IOUNBUF;

	if ( freopen( "stderr", "w", stderr ) == NULL )
		stderr->_ioflag1 = 0xff;
	stderr->_ioflag1 |= _IOUNBUF;
}
