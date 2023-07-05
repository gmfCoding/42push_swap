#include "pivot.h"

/* Returns the last index that is less than or equal to value.
 * Such that the next index is greater than value.
 * */
int med_first_idx_lte(t_median *med, int value)
{
	int i;

	i = 0;
	while (i < (med->size - 1))
	{
		if (med->array[i] <= value && med->array[i + 1] > value)
			return (i);
		i++;
	}
	return (i);
}

/* Returns the value less than curr,
 * if curr is the smallest value already it will return curr.
 */
int	med_first_value_lte(t_median *med, int curr)
{
	int index;
	
	index = med_first_idx_lte(med, curr);
	return (med->array[index]);
}

/* Returns the value less than curr,
 * if curr is the smallest value already it will return curr.
 */
int	median_prev(t_median *med, int curr)
{
	int index;
	
	index = med_first_idx_lte(med, curr);
	if (index == 0)
		index = 1;
	return (med->array[index - 1]);
}

/* Returns the next value greater than curr,
 * if curr is the largest value already it will return curr.
 */
int	median_next(t_median *med, int curr)
{
	int index;
	
	index = med_first_idx_lte(med, curr);
	if (index >= med->size)
		index--;
	return (med->array[index + 1]);
}
