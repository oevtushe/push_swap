#include "checker.h"

t_list	*read_args_stack(char **data, int size)
{
	int		cnt;
	int		val;
	t_list	*lst;
	t_list	*cur;

	cnt = size;
	lst = NULL;
	if (data && *data)
	{
		while (cnt--)
		{
			val = ft_atoi(data[cnt]);
			cur = ft_lstnew(&val, sizeof(int));
			ft_lstadd(&lst, cur);
		}
	}
	return (lst);
}

t_list	*read_operations(int fd)
{
	char	*line;
	t_list	*op_stack;
	t_list	*tmp;

	op_stack = NULL;
	while (get_next_line(fd, &line))
	{
		tmp = ft_lstnew(line, ft_strlen(line) + 1);
		ft_lstadd(&op_stack, tmp);
		ft_strdel(&line);
	}
	return (op_stack);
}
