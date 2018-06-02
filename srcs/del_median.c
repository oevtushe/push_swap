#include "push_swap.h"

void	del_median(void *content, size_t content_size)
{
	++content_size;
	free(content);
}
