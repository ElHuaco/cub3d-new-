/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:53:32 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/01/31 14:35:31 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		memread_update(int fd, char **mem, char **line)
{
	char		*nlpos;

	if ((nlpos = ft_strchr(mem[fd], '\n')))
		return (read_update(fd, mem, nlpos, line));
	else
	{
		*line = ft_strdup(mem[fd]);
		free(mem[fd]);
		mem[fd] = 0;
	}
	return (0);
}

int		read_update(int fd, char **mem, char *nlpos, char **line)
{
	char	*temp;

	*nlpos = '\0';
	*line = ft_strdup(mem[fd]);
	temp = ft_strdup(mem[fd] + ft_strlen(*line) + 1);
	free(mem[fd]);
	mem[fd] = temp;
	return (1);
}

static	void	mem_update(int fd, char **mem, char *buff)
{
	char	*temp;

	temp = ft_strjoin(mem[fd], buff);
	free(mem[fd]);
	mem[fd] = temp;
}

static	char	*ft_zalloc(int n)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * n);
	if (!result)
		return (0);
	i = -1;
	while (++i < n)
		result[i] = 0;
	return (result);
}

int				get_next_line(int fd, char **line)
{
	int				bytes_read;
	static char		*mem[4096];
	char			*buff;

	if (!line || fd < 0 || BS <= 0 || !(buff = malloc(sizeof(char) * (BS + 1))))
		return (-1);
	if (!mem[fd])
		mem[fd] = ft_zalloc(1);
	while ((bytes_read = read(fd, buff, BS)) > 0)
	{
		buff[bytes_read] = '\0';
		mem_update(fd, mem, buff);
		if ((ft_strchr(mem[fd], '\n')))
		{
			free(buff);
			return (read_update(fd, mem, ft_strchr(mem[fd], '\n'), line));
		}
		free(buff);
		buff = malloc(sizeof(char) * (BS + 1));
	}
	if (buff)
		free(buff);
	if (bytes_read == 0)
		return (memread_update(fd, mem, line));
	return (-1);
}
