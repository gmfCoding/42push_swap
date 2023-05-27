#include "sort.h"
#include "stack.h"

int	is_sorted(t_sort *sort)
{
	t_node	*next;
	int prev;

	if (sort->b->count != 0)
		return (0);
	next = sort->a->head;
	prev = next->value;
	next = next->next;
	while (next)
	{
		if (next->value < prev)
			return (0);
		prev = next->value;
		next = next->next;
	}
	return (1);
}
