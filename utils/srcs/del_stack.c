#include "utils.h"

void	del_stack(void *content, size_t content_size)
{
	++content_size;
	free(content);
}
