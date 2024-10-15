/* ADJ-702-248 (HITACH SuperH RISC engine compiler user's manual) p126 */

#ifdef __cplusplus
extern C{
#endif

void _INITSCT(void);
void _INITLIB(void);
void main(void);
void _CLOSEALL(void);
void _INIT(void);
/*void _call_init();*/
/*void _call_end();*/

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern C
#endif

#pragma noregsave (_INIT)

void _INIT( void )
{
	_INITSCT();
	_INITLIB();
/*	_call_init();	*/
	main();
/*	_call_end();	*/
	_CLOSEALL();
	for( ; ; )
		;
}