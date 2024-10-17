#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*array;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	array = (int *)malloc(size * sizeof(int));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}
/*
#include <stdio.h>

int	main()
{
	int min;
	int max;
	int *range_array;
	int i;
	
	min = 5;
	max = 40;
	range_array = ft_range(min, max);
	
	if (range_array == NULL) {
        printf("No range available.\n");
	}
	else
	{
		i = 0;
		while (i < (max - min))
			printf("%d ", range_array[i++]);
		printf("\n");
		free(range_array);
		range_array = NULL;
	}
	return 0;
}*/
