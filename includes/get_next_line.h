/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeoffro <lgeoffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 15:33:53 by lgeoffro          #+#    #+#             */
/*   Updated: 2021/08/06 14:07:24 by lgeoffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/resource.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>

# define GNL_ERROR NULL
# define GNL_FOUND_LINEBREAK 1
# define GNL_FOUND_EOF NULL
# define MAX_FD RLIMIT_NOFILE
# define HAV_BRK_LINE 1
# define HAVNT_BRK_LINE 0
# define READ_AND_JOINED_OR_EOF 1
# define BUFFER_SIZE 128

void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strchr_GNL(char *s, char c);
char	*ft_strjoin(char*s1, char *s2);
int		ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dst, char *src, size_t size);

#endif
