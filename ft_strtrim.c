/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:42:31 by rafilipe          #+#    #+#             */
/*   Updated: 2022/10/18 23:57:26 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		len;
	int		i;
	int		n;

	i = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1) - 1;
	while (s1[i] && len)
	{
		while (ft_isset(set, s1[i]))
			i++;
		while (ft_isset(set, s1[len]))
			len--;
		break ;
	}
	str = malloc((len - i) * sizeof(char) + 1);
	if (!str)
		return (NULL);
		n = 0;
	while (i <= len)
		str[n++] = s1[i++];
	return (str);
}
