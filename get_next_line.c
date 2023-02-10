/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esamad-j <esamad-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:59:59 by esamad-j          #+#    #+#             */
/*   Updated: 2023/02/10 21:10:22 by esamad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif


char	*get_next_line(int fd)
{
  static char *resto;
  char *buffer;
  char *aux;
  int i;
  
  i = 1;
  buffer = ft_calloc(sizeof(char), BUFFER_SIZE);
  i = read(fd, buffer, BUFFER_SIZE);
  printf("%ld\n", ft_strchr(buffer, 10) - buffer);
  
  // ft_substr(buffer, 0, )
return (NULL);

  /* if(ft_strchr(resto, 10) == 0) */
 /*  while (i >= 0)
  {
    buffer = ft_calloc(sizeof(char), BUFFER_SIZE);
    i = read(fd, buffer, BUFFER_SIZE);
    while(ft_strchr(buffer, 10) == 0)
      {
        aux = ft_strjoin(resto, buffer);
        free(resto);
        free(buffer);
        buffer = ft_calloc(sizeof(char), BUFFER_SIZE);
        i += read(fd, buffer, BUFFER_SIZE);
        resto = aux;
      }
      
  } */
  
    
}

int	main(void)
{
	char *leido;
    int fd;
    int i = 0;
	fd = open("hola.txt", O_RDONLY);
	if (fd < 0)
	{
        printf("cagaste, ERROR EN OPEN");
        return (0);
    }
    leido = get_next_line(fd);
    printf("---main---\n");
    printf("%s", leido);
    free(leido);
    /* leido = get_next_line(fd);
    printf("---main---\n");
    printf("%s", leido);
    free(leido);
    leido = get_next_line(fd);
    printf("---main---\n");
    printf("%s", leido);  */
  /*   while (leido)
    {
    printf("%s", leido);
    fflush(stdin);
    free(leido);
    leido = get_next_line(fd);
    } */
    
  free(leido);
	close(fd);
	return (0);
}