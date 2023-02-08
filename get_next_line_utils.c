/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esamad-j <esamad-j@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:57:04 by esamad-j          #+#    #+#             */
/*   Updated: 2023/02/08 12:27:14 by esamad-j         ###   ########.fr       */
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
	new_len = (strlen(str1) + strlen(str2));
	new_str = malloc(sizeof(char) * (new_len + 1));
	if (!new_str)
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

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	aux;

	i = 0;
	aux = c;
	while (s[i] != '\0')
	{
		if (s[i] == aux)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (aux == '\0')
		return ((char *)&s[i]);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*new;

	len_s = strlen(s);
	if (len + start > len_s)
		len = len_s - start;
	if (start > len_s)
		return (strdup(""));
	if (start == 0 && len == 0)
		return ("\n");
	
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (0);
	i = 0;
	while (len != -1)
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

	cont = 0;
	while (s[cont] != '\0')
		cont++;
	return (cont);
}
