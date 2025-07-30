/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:49:25 by sfiorini          #+#    #+#             */
/*   Updated: 2025/01/03 13:08:34 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <strings.h>
# include <string.h>
# include <bsd/string.h>
# include <fcntl.h>
# include <unistd.h>
# include <linux/stat.h>

void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(char *c);
char	*ft_strdup1(char *s);
char	*strjoin1(char *s1, char *s2);
char	*ft_strdup_str(char *s);
char	*get_next_line(int fd);
char	*readline(int fd, char **nextl, char *buf);
char	*ft_substr(char *s, int start, int end);
int		check_nexl(char *str);

#endif