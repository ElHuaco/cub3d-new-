/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:54:27 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/01/31 14:36:22 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifdef BUFFER_SIZE
#  define BS BUFFER_SIZE
# endif

# include "libft.h"

int					get_next_line(int fd, char **line);
int					memread_update(int fd, char **mem, char **line);
int					read_update(int fd, char **mem, char *nlpos, char **line);
#endif
