/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esamad-j <esamad-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 02:36:33 by esamad-j          #+#    #+#             */
/*   Updated: 2023/02/07 17:59:03 by esamad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
/*  int	main(void)
{
	char *s1 = "hola";
	char *s2 = " que tal";

	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}  */