/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:55:08 by sfiorini          #+#    #+#             */
/*   Updated: 2025/01/17 17:12:29 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_nexl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

char	*ft_substr(char *s, int start, int end)
{
	char	*a;
	int		i;

	if (start < 0)
		return (NULL);
	if (end > start)
		a = (char *)ft_calloc(((end - start) + 1), sizeof(char));
	else
		return (NULL);
	i = 0;
	while (start < end && s[i] != '\0')
	{
		a[i] = s[start];
		i++;
		start++;
	}
	a[i] = '\0';
	return (a);
}

char	*readline(int fd, char **nextl, char *buf)
{
	int		check;
	char	*tmp;

	check = 1;
	tmp = NULL;
	while (check > 0)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check == 0)
		{
			tmp = ft_strdup1(*(nextl));
			return (free(*(nextl)), tmp);
		}
		if (check == -1)
			return (NULL);
		if (check < BUFFER_SIZE)
			buf[check] = '\0';
		tmp = *(nextl);
		*(nextl) = strjoin1(tmp, buf);
		free(tmp);
		if (check_nexl(*(nextl)) >= 0)
			return (*(nextl));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*nextl;
	char		*str;
	char		*tmp;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = NULL;
	buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	tmp = readline(fd, &nextl, buf);
	free(buf);
	if (nextl != NULL)
	{
		str = ft_strdup_str(tmp);
		nextl = ft_substr(tmp, check_nexl(tmp), ft_strlen(tmp));
		free(tmp);
	}
	return (str);
}
/* 
int	main(void)
{
    int     fd;
    char    *str;

	fd = open("mhanz.txt", O_RDONLY);
    if (fd == -1)
        return (-1);
    while (1)
    {
        str = get_next_line(fd);
        if (str == NULL)
            break ;
        printf("get_next_line: {%s}", str);
        free(str);
    }
    str = NULL;
    close(fd);
}
 */