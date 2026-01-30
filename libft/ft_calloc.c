/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:01:53 by asyed             #+#    #+#             */
/*   Updated: 2024/05/03 13:09:36 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check for integer overflow -> (nmemb * size) / nmemb != size)
// calloc is the same as malloc
// initialised allocated memory garbage value to zero
// 2 parameters. no of element and size of.

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;

	ptr = malloc(nmemb * size);
	if (ptr != NULL)
		ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*
#include <stdio.h>

int main(void) 
{
    // Define the number of elements and the size of each element
    size_t nmemb = 5;
    size_t size = sizeof(int);
    size_t  i;

    // Allocate memory for an array of integers using ft_calloc
    int *arr = (int *)ft_calloc(nmemb, size);

    if (arr != NULL)
    {
        i = 0;
        printf("Array elements: ");
        while (i < nmemb)
        {
            arr[i] = i + 1;  // Initialize the array with some values
            printf("%d", arr[i]);
            i++;
        }
        // Print the values in the array
        printf("\n");
        // Free the allocated memory
        free(arr);
    } 
    else
    {
        // Allocation failed
        printf("Memory allocation failed.\n");
    }
    return (0);
}*/
