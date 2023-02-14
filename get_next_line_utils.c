/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esamad-j <esamad-j@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:57:04 by esamad-j          #+#    #+#             */
/*   Updated: 2023/02/14 01:28:52 by esamad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	int		i;
	int		j;
	char	*new_str;
	size_t	new_len;

	i = 0;
	j = 0;
	new_len = (ft_strlen(str1) + ft_strlen(str2));
	new_str = malloc(sizeof(char) * (new_len + 1));
	if (!new_str || !str1 || !str2)
		return (0);
	while (str1[i] != '\0')
	{
		new_str[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		new_str[i] = str2[j];
		i++;
		j++;
	}
	new_str[i] = 0;
	return (new_str);
	
}

int	ft_strchr(const char *s, char c)
{
	int		i;
	char	aux;
	if(!s)
		return(-1);
	i = 0;
	aux = c;
	while (s[i] != '\0')
	{
		if (s[i] == aux)
		{
			return (i);
		}
		i++;
	}
	
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*new;

	len_s = ft_strlen(s);
	if (len + start > len_s)
		len = len_s - start;
	if (start > len_s)
		return (ft_strdup(""));
	if (start == 0 && len == 0)
		return ("\n");
	
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (0);
	i = 0;
	while ((int)len != -1)
	{
			new[i] = s[start];
			i++;
			start++;
			len --;
	}
	new[i] = '\0';
	return (new);
}

size_t	ft_strlen(const char *s)
{
	size_t	cont;
	if(!s)
		return (0);
	cont = 0;
	while (s[cont] != '\0')
		cont++;
	return (cont);
}
char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*src_with_memory;

	i = 0;
	j = 0;
	i = ft_strlen(src);
	src_with_memory = (char *)malloc(i * sizeof(char) + 1);
	if (src_with_memory == NULL)
		return (0);
	while (src[j] != '\0')
	{
		src_with_memory[j] = src[j];
		j++;
	}
	src_with_memory[j] = '\0';
	return (src_with_memory);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*new;
	int		i;

	if ((count >= SIZE_MAX && size > 1) || (size >= SIZE_MAX && count > 1))
		return (0);
	i = 0;
	new = (char *)malloc(count * size);
	if (new == NULL)
		return (0);
	while (i < (int)(count * size))
	{
		new[i] = 0;
		i++;
	}
	return (new);
}
