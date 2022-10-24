/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:16:51 by rafilipe          #+#    #+#             */
/*   Updated: 2022/10/21 11:05:27 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wd_count(const char *s, char c)
{
	int			i;
	size_t		wd_count;

	i = 0;
	wd_count = 0;
	if (!s)
		return (1);
	if (ft_strchr(s, c) == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			wd_count++;
		i++;
	}
	return (wd_count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		idx;
	char	**matrix;

	if (!s)
		return (NULL);
	matrix = (char **)malloc((wd_count(s, c) + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	i = 0;
	idx = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		if ((s[i + j] == c && j > 0) || s[i + j] == '\0')
		{
			matrix[idx++] = ft_substr(s, i, j);
			if (s[i + j] == '\0')
				break ;
			i += j;
		}
		i++;
	}
	matrix[idx] = NULL;
	return (matrix);
}
