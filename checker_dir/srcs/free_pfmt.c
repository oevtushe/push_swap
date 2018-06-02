#include "checker.h"

void				free_pfmt(t_pformat **pfmt)
{
	free_bottom(&(*pfmt)->ba);
	free_bottom(&(*pfmt)->bb);
	free((*pfmt)->color);
	free(*pfmt);
	*pfmt = NULL;
}
