/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:24:08 by slebik            #+#    #+#             */
/*   Updated: 2024/10/17 14:24:08 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, unsigned int lim)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] && i < lim)
	{
		n = 0;
		while (str[i + n] && str[i + n] == to_find[n] && (i + n) < lim)
		{
			n++;
			if (to_find[n] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}

/*int	main()
{
	char	str[] = "outaipapaoutai";
	char	tofind[] = "e ";

	printf("%s", ft_strnstr(str,tofind,10));
}*/