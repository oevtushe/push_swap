#include "checker.h"

void				free_bottom(t_bottom **b)
{
	if ((*b)->separator)
		free((*b)->separator);
	if ((*b)->name)
		free((*b)->name);
	free(*b);
	*b = NULL;
}
