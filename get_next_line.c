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
	if(!str)
	return 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *bufferfill(int fd,char *temp)
{
	char	*buffer;
	int 	total;


	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	total = 1;
	while (total != 0 && !nl_sig(temp))
	{
		total = read(fd, buffer, BUFFER_SIZE);
		if (total == -1)
		{
			free(buffer);
			return(0);
		}
		buffer[total ] = 0;
		temp = ft_strjoin(temp, buffer);
	}
	return (temp);
}
char	*rest(char	*str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!str)
		return NULL;
	while(str[i] && str[i] != '\n')
		i++;
	tmp = ft_strdup(str + i+1);
	free(str);
	return (tmp);
}
char	*get_next_line(int fd)
{
	static char	*garb;
	char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (0);
	garb = bufferfill(fd ,garb);
	if (!garb)
	{
		free(garb);
		garb = NULL;
		return (NULL);
	}
	str = newline(garb);
	garb = rest(garb);
	return (str);
}
