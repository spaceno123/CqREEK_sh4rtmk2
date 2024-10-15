/* ADJ-702-248 (HITACH SuperH RISC engine C/C++ compiler user's manual) p123 */

extern int *_D_ROM, *_B_BGN, *_B_END, *_D_BGN, *_D_END;

#ifdef __cplusplus
extern C
#endif

#pragma noregsave (_INITSCT)

void _INITSCT( void )
{
	int *p, *q;

	for ( p = _B_BGN; p < _B_END; p++ )
		*p = 0;
	for ( p = _D_BGN, q = _D_ROM; p < _D_END; p++, q++ )
		*p = *q;
}
