/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:18:35 by qdo               #+#    #+#             */
/*   Updated: 2024/04/07 23:41:39 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*lstr[4096];
	char		*ret;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lstr[fd] = ft_read(fd, lstr[fd]);
	if (lstr[fd] == 0)
		return (0);
	temp = lstr[fd];
	lstr[fd] = ft_before_after_nl(lstr[fd], 1);
	if (lstr[fd] == 0)
		return (ft_free(temp, 0, 0));
	ret = ft_before_after_nl(temp, -1);
	if (ret == 0)
		return (ft_free(temp, 0, &lstr[fd]));
	ft_free(temp, 0, 0);
	return (ret);
}
