/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esamad-j <esamad-j@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:42:58 by esamad-j          #+#    #+#             */
/*   Updated: 2023/02/05 05:11:44 by esamad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (0);
	i = 0;
	while (len > 0)
	{
			new[i] = s[start];
			i++;
			start++;
			len --;
	}
	new[i] = '\0';
	return (new);
}
/* int main()
{
	char	*str;
	int		m;
	int		n;

	str = "Hello Please Trim me !";
    m = 0;
    n = 23;
 
    char* dest = ft_substr(str, m, n);
 
    printf("%s\n", dest);
 
    return (0);
}
 */