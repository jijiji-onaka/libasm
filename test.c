#include "includes/libasm_bonus.h"

void	my_clang_list_sort(t_list **list, int (*cmp)())
{
	void	*tmp;
	t_list	*begin;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return ;
	begin = *list;
	while ((*list)->next)
	{
		if (cmp((*list)->data, (*list)->next->data) > 0)
		{
			tmp = (*list)->data;
			(*list)->data = (*list)->next->data;
			(*list)->next->data = tmp;
			*list = begin;
		}
		else
			*list = (*list)->next;
	}
	*list = begin;
}
