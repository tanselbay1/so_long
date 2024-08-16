/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:00:32 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/08/16 11:12:27 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen1(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup1(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = malloc(ft_strlen1(str) + 1);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = (char *)malloc((ft_strlen1(s1) + ft_strlen1(s2) + 1)
			* sizeof(char));
	if (!new_str)
		return (0);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = 0;
	return (new_str);
}

size_t	ft_strlcpy1(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr1(char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substring;
	size_t	end;

	if (!s)
		return (NULL);
	s_len = ft_strlen1(s);
	if (start >= s_len)
		return (ft_strdup1(""));
	end = start + len;
	if (end > s_len)
		end = s_len;
	substring = malloc(end - start + 1);
	if (!substring)
		return (NULL);
	ft_strlcpy1(substring, s + start, end - start + 1);
	return (substring);
}
