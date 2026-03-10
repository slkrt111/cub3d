/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:26:01 by slebik            #+#    #+#             */
/*   Updated: 2024/10/17 15:26:01 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t	size)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)str;
	while (i < size)
	{
		s[i] = (char)c;
		i++;
	}
	return (str);
}

/* jdois cast strsi mon int c est un charactere alors mettre (char)c*/
/*#include <stdio.h>
#include <string.h>

int main() 
{
    char array[10];


    ft_memset(array, 'A', 10);


    for (int i = 0; i < 10; i++) {
        printf("%c ", array[i]);
    }
}*/