/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imonazad <imonazad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:59:59 by esamad-j          #+#    #+#             */
/*   Updated: 2023/02/20 23:18:59 by imonazad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *resto)
{
	char	*buffer;
	int		byte_read;

	byte_read = 1;
	if (ft_strchr_gnl(resto, 10) != -1)
		return (resto);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while ((ft_strchr_gnl(resto, 10) == -1) && byte_read)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == 0)
			break ;
		if (byte_read == -1)
		{
			free(buffer);
			free(resto);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		resto = ft_strjoin_gnl(resto, buffer);
	}
	free(buffer);
	return (resto);
}

char	*guardar(char *resto)
{
	char	*temp;
	int		i;

	if (!resto)
		return (NULL);
	i = 0;
	while (resto[i] && resto[i] != '\n')
		i++;
	if (!resto[i] || !resto[i + 1])
	{
		free(resto);
		return (NULL);
	}
	if (resto[i])
		i++;
	temp = ft_strdup(&resto[i]);
	free(resto);
	return (temp);
}

char	*primersalto(char *resto)
{
	int		i;
	char	*aux;

	if (!resto)
		return (NULL);
	i = 0;
	while (resto[i] != '\n' && resto[i])
		i++;
	if (resto[i])
		i++;
	aux = ft_calloc((i + 1), sizeof(char));
	i = 0;
	while (resto[i] && resto[i] != '\n')
	{
		aux[i] = resto[i];
		i++;
	}
	if (resto[i] == '\n')
		aux[i] = '\n';
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*resto = NULL;
	char		*aux;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	aux = NULL;
	resto = ft_read(fd, resto);
	aux = primersalto(resto);
	resto = guardar(resto);
	return (aux);
}

/* 
void	leaksssss(void)
{
	system ("leaks -q a.out");
}
int	main(void)
{
	int		fd;
	int		i;
	char	*c;
	i = 0;
	fd = open("hola.txt", O_RDONLY);
	while (i < 10)
	{
		c = get_next_line(fd);
		printf("--->%s", c);
		free(c);
		i++;
	}
	close(fd);
} */
/* int	main(void)
{
  //atexit(leaksssss);
	char *leido;
  int fd;
	fd = open("hola.txt", O_RDONLY);
	if (fd < 0)
	{
    printf("cagaste, ERROR EN OPEN");
    return (0);
  }
  leido = get_next_line(fd);
  printf("---main---\n");
  while (leido)
  {
    printf("%s", leido);
    fflush(stdin);
    free(leido);
    leido = get_next_line(fd);
  } 
  
  free(leido);
	close(fd);
  
	return (0);
} */