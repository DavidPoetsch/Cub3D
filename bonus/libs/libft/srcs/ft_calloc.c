/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:26:17 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:40:54 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief The calloc() function allocates memory for  an  array  of
					nmemb  elements  of size bytes each and returns a pointer
					to the allocated memory.  The memory is set to zero.   If
					nmemb or size is 0, then calloc() returns either NULL, or
					a unique pointer value that  can  later  be  successfully
					passed  to  free().   If  the multiplication of nmemb and
					size would result in integer overflow, then calloc()  re‐
					turns  an  error.  By contrast, an integer overflow would
					not be detected in the following call to  malloc(),  with
					the  result  that  an  incorrectly  sized block of memory
					would be allocated.
 * @param nmemb	amount of elements
 * @param size	size of each element
 * @return void*	pointer to the allocated memory
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	length;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size > SIZE_MAX / nmemb)
		return (NULL);
	length = nmemb * size;
	ptr = (void *)malloc(length);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, length);
	return (ptr);
}

/*
#include <stdio.h>

int	main(void)
{
	int	*arr;
	int	n;

	n = 10;
	arr = (int *)ft_calloc(n, 0);
	printf("Array elements initialized by calloc:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d=%d\n", i, arr[i]);
	}
	return (0);
}
 */