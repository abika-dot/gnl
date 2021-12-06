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

char *bufferfill(int fd)
{
	char	*buffer;
	int 	total;
	char	*temp;

	temp = NULL;
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
		buffer[total] = 0;
		temp = sp_alloc(temp, buffer);
	}
	return (temp);
}
char	*rest(char	*rest)
{
	char	*temp;
	int i;
	int j;

	j = 0;
	i = 0;
	if (!rest)
	return NULL;
	while(rest[i] && rest[i] != '\n')
		i++;
	temp = malloc((ft_strlen(rest) - i ) * sizeof(char));
	if (!temp)
	return NULL;
	i++;
	if (rest[i] == 0)
	return 0;
	while(rest[i])
	{
		temp[j] = rest[i];
		j++;
		i++;
	}
	temp[j] = 0;
	free(rest);
	return(temp);
}

char	*get_next_line(int fd)
{
	static char	*garb;
	char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (0);
	garb = bufferfill(fd );
	if (!garb)
		return NULL;
	str = newline(garb);
	garb = rest(garb);
	return (str);
}
