/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoh <dgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:49:46 by dgoh              #+#    #+#             */
/*   Updated: 2023/02/14 12:12:06 by dgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strchr(char *str, int c)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
	{
		if (str[len] == (char)c)
			return ((char *)&str[len]);
		len++;
	}
	if (str[len] == (char)c)
	{
		return ((char *)&str[len]);
	}
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*concat;
	size_t	len;
	int		i;

	i = 0;
	if (!str1)
	{
		str1 = (char *)malloc(1 * sizeof(char));
		str1[0] = '\0';
	}
	len = ft_strlen(str1) + ft_strlen(str2);
	concat = malloc((len + 1) * sizeof(char));
	if (!concat || !str1 || !str2)
		return (NULL);
	while (str1[i])
	{
		concat[i] = str1[i];
		i++;
	}
	while (*str2)
		concat[i++] = *str2++;
	concat[i] = '\0';
	free(str1);
	return (concat);
}

char	*ft_current_line(char *left_str)
{
	int		size;
	char	*str;

	size = 0;
	if (!left_str[size])
		return (NULL);
	while (left_str[size] != '\n' && left_str[size])
		size++;
	str = (char *)malloc((size + 2) * sizeof(char));
	if (!str)
		return (NULL);
	size = 0;
	while (left_str[size] != '\n' && left_str[size])
	{
		str[size] = left_str[size];
		size++;
	}
	if (left_str[size] == '\n')
	{
		str[size] = left_str[size];
		size++;
	}
	str[size] = '\0';
	return (str);
}

char	*ft_new_line(char *left_str)
{
	int		size;
	int		concatsize;
	char	*str;

	size = 0;
	concatsize = 0;
	while (left_str[size] != '\n' && left_str[size])
		size++;
	if (!left_str[size])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(left_str) - size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	size++;
	while (left_str[size])
		str[concatsize++] = left_str[size++];
	str[concatsize] = '\0';
	free(left_str);
	return (str);
}
