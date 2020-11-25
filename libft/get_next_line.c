/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <sstench@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:20:22 by sstench           #+#    #+#             */
/*   Updated: 2020/08/11 11:10:11 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	add_to_line(char **line, char **full_fd)
{
	char	*tmp;
	int		index;

	index = 0;
	while ((*full_fd)[index] != '\n' && (*full_fd)[index] != '\0')
		index++;
	if ((*full_fd)[index] == '\n')
	{
		*line = ft_strsub(*full_fd, 0, index);
		tmp = ft_strdup(&((*full_fd)[index + 1]));
		free(*full_fd);
		(*full_fd) = tmp;
		if ((*full_fd)[0] == '\0')
			ft_strdel(full_fd);
	}
	else
	{
		*line = ft_strdup(*full_fd);
		ft_strdel(full_fd);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str_static[OPEN_MAX];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			byte_strg;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	while ((byte_strg = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[byte_strg] = '\0';
		if (str_static[fd] == NULL)
			str_static[fd] = ft_strnew(1);
		tmp = ft_strjoin(str_static[fd], buff);
		free(str_static[fd]);
		str_static[fd] = tmp;
		if (ft_strchr(str_static[fd], '\n'))
			break ;
	}
	if (byte_strg < 0)
		return (-1);
	else if (byte_strg == 0 && (str_static[fd] == NULL ||
				str_static[fd][0] == '\0'))
		return (0);
	return (add_to_line(line, &str_static[fd]));
}
