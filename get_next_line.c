/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 07:36:43 by ozahir            #+#    #+#             */
/*   Updated: 2021/12/01 07:56:12 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:02:56 by ozahir            #+#    #+#             */
/*   Updated: 2021/12/01 07:29:07 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
static int exist(char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
	}
		return (0);
}
static char *rest(char *s , int index)
{
	char *ret;
	ret = ft_substr(s, index,ft_strlen(s));
	if (!ret)
		return NULL;
	return ret;
}
char *get_next_line(int fd)
{
	char	*buffer = malloc(BUFFER_SIZE + 1);
	int			i;
	char		*retu = NULL;
	static char *rst;
	int s;

	i = 0;
	while (i > 0)
	{
		i = read(fd,buffer,BUFFER_SIZE);
		printf("%d: %s\n" ,i,buffer);
		if (rst)
		{
			buffer = ft_strjoin(rst,buffer);
			printf("%d: %s\n",i,buffer);
			free(rst);
		}
		else if (!retu)
		{
			retu = ft_strdup(buffer);
			printf("%d: %s",i,retu);
			s = exist(retu);
		buffer[BUFFER_SIZE + 1]= 0;
		}
		else if (s)
		{
			rst = rest(retu,s);
			printf("%d: %s",i,rst);
			retu = ft_substr(buffer,0,exist(s);
		}
		i++;
	}
	free(buffer);
	return (retu);
}
