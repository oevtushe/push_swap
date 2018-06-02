#include "checker.h"

void				pfmt_prep_to_next(t_pformat *pfmt)
{
	ft_strdel(&pfmt->ba->name);
	ft_strdel(&pfmt->ba->separator);
	ft_strdel(&pfmt->bb->name);
	ft_strdel(&pfmt->bb->separator);
}
