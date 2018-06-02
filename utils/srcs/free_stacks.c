#include "utils.h"

void	free_stacks(t_stacks **stacks)
{
	ft_lstdel(&(*stacks)->a, del_stack);
	ft_lstdel(&(*stacks)->b, del_stack);
	free(*stacks);
	*stacks = NULL;
}
