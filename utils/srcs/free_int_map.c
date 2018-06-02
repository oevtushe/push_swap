#include "utils.h"

void	free_int_map(int ***map, int size)
{
	int i;

	i = 0;
	while (i < size)
		free((*map)[i++]);
	free(*map);
}
