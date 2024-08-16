/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:09:22 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/08/16 11:12:35 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen1(const char *str);
char	*ft_strdup1(char *str);
char	*ft_strjoin1(char *s1, char *s2);
size_t	ft_strlcpy1(char *dst, const char *src, size_t size);
char	*ft_substr1(char *s, unsigned int start, size_t len);

#endif