/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 09:55:13 by ozahir            #+#    #+#             */
/*   Updated: 2021/12/05 12:14:06 by ozahir           ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*garb;
	char 	*play;
	int			i;

	if (garb && nl_sig(garb))
		return(newline(garb));
	else if (garb && !nl_sig(garb))
	{
		play = ft_strdup(garb);
		free(garb);
	}
	i = 0;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0)
		return (NULL);
	buffer[BUFFER_SIZE + 1] = '\0';
	while(1)
	{
		i = read(fd,buffer,BUFFER_SIZE);
		play = sp_alloc(play,buffer);
		if (nl_sig(play))
			return (newline(garb));
		if (i == 0 && !nl_sig(play))
			return (free(buffer), play);
	}
	return NULL;
}
