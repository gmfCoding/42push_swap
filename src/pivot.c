
typedef struct s_median
{
	int	*array;
	int size;
	int median;
	int num1;
	int num2;
	int answer;
} t_median;

void	swap(int *a, int *b)
{
	int temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

static int	partition(t_median *median, int left, int right)
{
	const int val = median->array[right];
	int			i;
	int			j;

	i = left;
	j = left;
	while (j < right)
	{
		if (median->array[j] < val)
		{
			swap(&median->array[i], &median->array[j]);
			i++;
		}
		j++;
	}
	swap(&median->array[i], &median->array[j]);
	return (i);
}

static void	median_correct(t_median *median, int left, int right, int select)
{
	int p_index;

	if (left < right)
	{
		swap(&median->[median->size / 2], &median->array[right]);
		p_index = partition(median, left, right);
		if (p_index == select)
		{
			median->num2 = median->array[p_index];
			if (median->num1 != -1)
				return ;
		}
		else if (p_index == select - 1)
		{
			median->num1 = median->array[p_index];
			if (median->num2 != -1)
				return ;
		}	
		if (p_index >= select)
				return (median_correct(median, left, p_index - 1, select));
		else
				return (median_correct(median, left, p_index + 1, select));
	}
}

int	median(t_median *median)
{
	median->a = -1;
	median->b = -1;
	median_correct(median, 0, median->size - 1, median->size / 2);
	if (median->size % 2 == 0)
		median->answer = (median->a + median->b) / 2;
	else
		median->answer =  median->num2;
	return (median->answer);
}
