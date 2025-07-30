/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:58:30 by sfiorini          #+#    #+#             */
/*   Updated: 2025/01/03 13:11:28 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*a;
	int		i;
	char	*d;

	a = (void *)malloc(size * nmemb);
	if (a == NULL)
		return (NULL);
	d = (char *)a;
	i = 0;
	while (i < (int)nmemb)
	{
		d[i] = 0;
		i++;
	}
	return (a);
}

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strdup1(char *s)
{
	char	*a;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\0')
		i++;
	a = (char *)ft_calloc((i + 1), sizeof(char));
	j = 0;
	while (j < i)
	{
		a[j] = s[j];
		j++;
	}
	return (a);
}

char	*strjoin1(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		k;
	int		len;

	if (s1 == NULL)
		return (ft_strdup1(s2));
	len = (ft_strlen(s1) + ft_strlen(s2));
	s = (char *)ft_calloc((len + 1), sizeof(char));
	k = 0;
	while (s1[k])
	{
		s[k] = s1[k];
		k++;
	}
	i = 0;
	while (k < len)
	{
		s[k] = s2[i];
		i++;
		k++;
	}
	s[k] = '\0';
	return (s);
}

char	*ft_strdup_str(char *s)
{
	char	*a;
	int		i;

	i = 0;
	while (s[i] && (s[i] != '\n'))
		i++;
	a = (char *)ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (s[i] && (s[i] != '\n'))
	{
		a[i] = s[i];
		i++;
	}
	if (s[i] != '\0' && s[i] == '\n')
		a[i++] = '\n';
	a[i] = '\0';
	return (a);
}
