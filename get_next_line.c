/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 09:55:13 by ozahir            #+#    #+#             */
/*   Updated: 2021/12/05 23:42:45 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int nl_sig(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char bufferfill(int fd, char *fill)
{
	char	*buffer;
	int 	bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (bytes != 0 && !nl_sig(buffer))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		fill = sp_alloc(fill, buffer);
	}
	free(buffer);
	return (fill);
}

char	*get_next_line(int fd)
{
	static char	*garb;
	char	*line

	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	garb = bufferfill(fd ,garb);
	if (!garb)
		return NULL;
	line = newline(garb);
	return (line);

}
