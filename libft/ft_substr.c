/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:26:26 by slebik            #+#    #+#             */
/*   Updated: 2024/11/03 17:26:26 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	s_len = ft_strlen (s);
	if (!(s))
		return (0);
	if (len > s_len - start)
		len = s_len - start;
	if (start >= s_len)
		return (ft_calloc(1, sizeof(char)));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_memcpy (str, s + start, len);
	str[len] = '\0';
	return (str);
}

/*int	main()
{
	char	str[] = "abcdefghijkl";
	ft_substr (str, 3, 1);
}*/
