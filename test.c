#include "includes/libasm_bonus.h"

void	ft_list_remove_if2(t_list **list,
			void *data, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*begin;
	t_list	*save;

	begin = *list;
	if (*list == NULL)
		return ;
	while (*list && (*list)->next)
	{
		if (cmp(data, (*list)->next->data) == 0)
		{
			save = (*list)->next;
			(*list)->next = (*list)->next->next;
			free(save->data);
			free(save);
		}
		*list = (*list)->next;
	}
	*list = begin;
	if (cmp(data, (*list)->data) == 0)
	{
		save = (*list)->next;
		free((*list)->data);
	    free(*list);
		*list = save;
	}
}
