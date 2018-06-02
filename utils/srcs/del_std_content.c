#include "utils.h"

void	del_std_content(void *content, size_t content_size)
{
	++content_size;
	free(content);
}
