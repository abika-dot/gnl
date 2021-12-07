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


size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (src[count])
		count++;
	if (dstsize == 0)
		return (count);
	while (src[i] && dstsize != 0 && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
}

int	ft_strlen(char const *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strdup(char const *s1)
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

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s;
	size_t	l;
	size_t	k;

	k = 0;
	l = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}	
	s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (s1[k] != '\0')
	{
		s[k] = s1[k];
		k++;
	}
	while (s2[l] != '\0')
		s[k++] = s2[l++];
	s[k] = '\0';
	free (s1);
	return (s);
}

char	*newline(char *left)
{
	int		i;
	char	*nl;

	i = 0;
	if (!left)
	return NULL;
	while (left[i] && left[i] != '\n')
		i++;
	nl = malloc((i +2) * sizeof(char));
	if (!nl)
	return (0);
	i = 0;
	while (left[i] && left[i] != '\n')
	 {
		nl[i] = left[i];
		i++;
	}
	if (left[i] == '\n')
		nl[i++] = '\n';
	nl[i] = '\0';
	return (nl);
}
