/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:37:45 by slebik            #+#    #+#             */
/*   Updated: 2024/10/16 19:37:45 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	i;

	i = ft_strlen(str);
	if ((char)ch == '\0')
	{
		return ((char *)&str[i]);
	}
	while (i >= 0)
	{
		if (str[i] == (char)ch)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}

/*int	main()
{
	char	str[] = "le Mundo Mais DOuceMent quand mm";
	int u = 'M';

	printf("%s\n", strrchr(str,u));
	printf("%s", ft_strrchr(str,u));
}*/