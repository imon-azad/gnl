/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esamad-j <esamad-j@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:59:59 by esamad-j          #+#    #+#             */
/*   Updated: 2023/02/12 04:54:33 by esamad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

char *ft_read(int fd, size_t *byte_read, char *resto)
{
  char *aux;
  char *buffer;
  
  if (!resto)
    resto = ft_calloc(1,1);
  if(ft_strchr(resto, 10) != -1)
    return (resto);
  buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
  *byte_read += read(fd, buffer, BUFFER_SIZE);
  //printf("==%zu==",*byte_read);
  aux = ft_strjoin(resto, buffer);
  free(resto);
  free(buffer);
 
  resto = aux;
  
  return (resto);
}
char *guardar( size_t byte_read, char *resto)
{
  char *temp;
  temp = ft_substr(resto, ft_strchr(resto, 10) + 1, byte_read);
  free(resto);
  return(temp);
}
char	*get_next_line(int fd)
{
  static char *resto = NULL;
  size_t byte_read = 0;
  char *aux;
  printf("º%sº",resto);
  resto = ft_read(fd, &byte_read, resto);
 
  while(ft_strchr(resto, 10) == -1 && resto)
    resto = ft_read(fd, &byte_read, resto);
  resto[ft_strlen(resto)+1] = '\n';
  if(ft_strchr(resto, 10) != -1)
  {
    
    /* printf("SOBRA==%s==\n",ft_substr(resto, ft_strchr(resto, 10) + 1, byte_read)); */
    aux = ft_substr(resto, 0, ft_strchr(resto, 10));
    resto = guardar(byte_read, resto);
    printf("^%s^",resto);
  }
    return(aux);
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
   /*  printf("%s", leido);
    free(leido);
    leido = get_next_line(fd);
    printf("---main---\n");
    printf("%s", leido);
    free(leido);
    leido = get_next_line(fd);
    printf("---main---\n");
    printf("%s", leido);  */
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
}