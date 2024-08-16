/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:07:44 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/08/16 11:12:31 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*set_line(char *line);
static char	*complete_line(int fd, char *temp, char *buffer);
static char	*ft_strchr(char *s, int c);

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*buffer;
	char		*line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(temp);
		free(buffer);
		temp = NULL;
		buffer = NULL;
		return (0);
	}
	if (!buffer)
		return (NULL);
	line = complete_line(fd, temp, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	temp = set_line(line);
	return (line);
}

static char	*set_line(char *line)
{
	char	*temp;
	ssize_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0)
		return (0);
	temp = ft_substr1(line, i + 1, ft_strlen1(line) - i);
	if (*temp == 0)
	{
		free(temp);
		temp = NULL;
	}
	line[i + 1] = 0;
	return (temp);
}

static char	*complete_line(int fd, char *temp, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(temp);
			return (0);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = 0;
		if (!temp)
			temp = ft_strdup1("");
		tmp = temp;
		temp = ft_strjoin1(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (temp);
}

static char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (NULL);
}

// #include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	// Open a file for reading
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	// Read lines from the file using get_next_line
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s\n", line);
// 		free(line); // Free memory allocated by get_next_line
// 	}
// 	// Close the file descriptor
// 	close(fd);
// 	return (0);
// }
