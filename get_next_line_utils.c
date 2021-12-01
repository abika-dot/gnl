/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 21:38:04 by ozahir            #+#    #+#             */
/*   Updated: 2021/12/01 06:24:37 by ozahir           ###   ########.fr       */
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
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ss;
	int		ln1;
	int		ln2;
	int		j;

	j = 0;
	if (!s1 || !s2)
		return (NULL);
	ln1 = ft_strlen(s1);
	ln2 = ft_strlen(s2);
	ss = malloc((ln1 + ln2) * sizeof(char) + 1);
	if (!ss)
		return (NULL);
	ft_memcpy(ss, s1, ln1);
	while (s2[j])
	{
		ss[ln1 + j] = s2[j];
		j++;
	}
	ss[ln1 + ln2] = 0;
	return (ss);
}
char	*ft_strdup(const char *s1)
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
static char	*zerorule(char *ss)
{
	ss[0] = 0;
	return (ss);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ss;
	unsigned int	i;
	unsigned int	sl;

	i = 0;
	if (!s)
		return (NULL);
	sl = ft_strlen(s);
	if (len > sl)
		len = sl;
	ss = malloc(len * sizeof(char) + 1);
	if (!ss)
		return (NULL);
	if (start > sl)
		return (zerorule(ss));
	while (s[start] && i < len)
	{
		ss[i] = s[start];
		i++;
		start++;
	}
	ss[i] = 0;
	return (ss);
}
