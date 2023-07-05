#include <stdio.h>
#include <stddef.h>
#include "sort.h"


// *
// **
// ***
//
// **
// *
// ***
//
// ***
// **
// *
//
// ***
// *
// **
//
// **
// ***
// *
//
// 123 x x x 
// 132 x x x
// 213 x x x
// 231 x x x
// 312 x x x
// 321 x x x


static int eval(t_sort *sort, int n, int x)
{
	if (n == 1)
		return (sort->a->head->value == x);
	else if (n == 2)
		return (sort->a->head->next->value == x);
	else if (n == 3)
		return (sort->a->head->next->next->value == x);
}

void tiny_sort(t_sort *sort)
{
	if (sort->a->count > 4 || sort->a->count < 3)
		return ;
	
	if (eval(sort, 1, 3) && eval(sort, 3, 2))
		op_ra(sort);
	if (eval(sort, 1, 1) && eval(sort, 3, 2))
		op_rra(sort);
	if (eval(sort, 1, 2) && eval(sort, 3, 1))
		op_rra(sort);
	if (eval(sort, 1, 2) && eval(sort, 3, 3))
		op_sa(sort);
	else if (eval(sort, 1, 3) && eval(sort, 3, 1))
	{	
		op_sa(sort);
		op_rra(sort);
	}
}

void cost_sort(t_sort *sort)
{
	while (sort->a->count > 3)
		op_pb(sort);	
	tiny_sort(sort);
}
