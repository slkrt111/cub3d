/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:43:33 by slebik            #+#    #+#             */
/*   Updated: 2024/10/17 15:43:33 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

/* #include <strings.h>
#include <stdio.h>

int main() {
    char buffer[10];

    for (int i = 0; i < 10; i++)
        buffer[i] = 'A';

    ft_bzero(buffer, 10);

    for (int i = 0; i < 10; i++)
        printf("%d ", buffer[i]);

    return 0;
}*/