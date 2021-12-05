/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 09:55:33 by ozahir            #+#    #+#             */
/*   Updated: 2021/12/05 12:08:44 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>
void	*ft_memcpy(void *dst, const void *src, size_t n);
int	ft_strlen(char *s);
char	*ft_strdup(char *s1);
void	*sp_alloc(char *s1, char *s2);
char	*newline(char *left);
int nl_sig(char *str);
char	*get_next_line(int fd);


#endif
