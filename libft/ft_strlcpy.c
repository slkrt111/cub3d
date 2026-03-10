/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:22:00 by slebik            #+#    #+#             */
/*   Updated: 2024/11/12 01:22:00 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

/*int	main()
{
	char	src[] = "Hello";
	char	dest[] = "cavaaaaaaaaaaaaaaaaaaaaaaaaa";

	char	src1[] = "Hello";
	char	dest1[] = "cavaaaaaaaaaaaaaaaaaaaaa";

	ft_strlcpy(dest, src, 15);
	printf ("%s\n", dest);
	strlcpy(dest1, src1, 15);
	printf ("%s\n", dest1);
}*/