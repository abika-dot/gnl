/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 09:55:04 by ozahir            #+#    #+#             */
/*   Updated: 2021/12/05 12:08:00 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ddst;
	char	*ssrc;
	int		i;

	if (!dst && !src)
		return (NULL);
	ddst = (char *)dst;
	ssrc = (char *)src;
	i = 0;
	while (n)
	{
		ddst[i] = ssrc[i];
		n--;
		i++;
	}
	return ((void *)(dst));
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strdup(char *s1)
{
	int		i;
	int		s;
	char	*str;

	i = 0;
	s = ft_strlen(s1);
	str = malloc(((size_t)s) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*sp_alloc(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		b;
	
	if (!s1)
	{
		new = ft_strdup(s2);
		free(s2);
		return (new);
	}
	i = ft_strlen(s1);
	b = i + BUFFER_SIZE;
	if (i == -1)
		return (NULL);
	new = malloc((b + 1) * sizeof(char));
	if (!new)
		return (NULL);
	new[b] = '\0';
	new = ft_memcpy(new, s1, i);
	new = ft_memcpy(new + i, s2, BUFFER_SIZE);
	free(s1);
	return (new - i);
}

char	*newline(char *left)
{
	int		i;
	char	*nl;
	char	*tmp;


	tmp = NULL;
	i = 0;
	while (left[i] && left[i] != '\n')
		i++;
	nl = malloc((i + 2) * sizeof(char));
	if (!nl)
	return (0);
	nl[i + 1] = 0;
	nl = ft_memcpy(nl, left, i + 1);
	free(tmp);
	return (nl);
}
