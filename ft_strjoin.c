/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:39:56 by rafilipe          #+#    #+#             */
/*   Updated: 2022/10/17 19:01:44 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	if (len == ft_strlen(s1))
		str = (ft_strdup(s1));
	else
		str = (char *)malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (s2[j])
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		str[i + j] = s2[j];
		j++;
	}
	return (str);
}
