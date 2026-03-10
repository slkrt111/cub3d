/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:51:49 by slebik            #+#    #+#             */
/*   Updated: 2024/10/12 16:51:49 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		size;
	int		i;
	char	*str1;
	char	*str2;

	i = 0;
	str2 = (char *)str;
	size = ft_strlen (str2);
	str1 = (char *) malloc ((size + 1) * sizeof(char));
	if (!str1)
		return (NULL);
	while (str2[i])
	{
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

/*
int	main()
{
	char	str[] = "hello";
	char	*str1;

	str1 = ft_strdup(str);
	printf("%s\n", str1);

	
	char	str2[] = "hello";
	char	*str3;

	str3 = strdup(str2);
	printf("%s\n", str3);
}*/