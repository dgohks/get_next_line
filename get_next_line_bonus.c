/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoh <dgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:47:27 by dgoh              #+#    #+#             */
/*   Updated: 2023/01/18 12:34:15 by dgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_reading(int fd, char *left_str)
{
	char	*buffer;
	int		readsize;

	readsize = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (readsize != 0 && !ft_strchr(left_str, '\n'))
	{
		readsize = read(fd, buffer, BUFFER_SIZE);
		if (readsize == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readsize] = '\0';
		left_str = ft_strjoin(left_str, buffer);
	}
	free(buffer);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str[1024];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	left_str[fd] = ft_reading(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_current_line(left_str[fd]);
	left_str[fd] = ft_new_line(left_str[fd]);
	return (line);
}
