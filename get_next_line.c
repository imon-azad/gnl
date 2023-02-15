/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esamad-j <esamad-j@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:59:59 by esamad-j          #+#    #+#             */
/*   Updated: 2023/02/15 02:38:40 by esamad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read(int fd, size_t *byte_read, char *resto)
{
  char *aux;
  char *buffer;
//printf("a");
  if (!resto)
    resto = ft_calloc(1,1);
  if(ft_strchr(resto, 10) != -1)
    return (resto);
  buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
  if (!buffer)
    return (NULL);
  *byte_read += read(fd, buffer, BUFFER_SIZE);
  
  if ((int)*byte_read == -1)
  {
    free(buffer);
    free(resto);
    return (NULL);
  }
 /*  if (buffer[i] == '\0' && byte_read)
  { 
    while (resto[i] != '\0')
      i++;
    resto[i] = '\n';
  }  */
  
  aux = ft_strjoin(resto, buffer);
  free(resto);
  free(buffer);
  resto = aux;
  //printf("fin");
  return (resto);
}

char *guardar(char *resto)
{
  char *temp;
  int i;
  if (!resto)
    return 0;
  i = 0;
  while (resto[i] && resto[i] != '\n')
		i++;
  if (resto[i])
    i++;
  temp = ft_strdup(&resto[i]);
  free(resto);
  return(temp);
}

char	*get_next_line(int fd)
{
  static char *resto = NULL;
  size_t byte_read = 0;
  char *aux;
  int i = 0;
  aux = NULL;
  if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
  //printf("^%s^",resto);
  resto = ft_read(fd, &byte_read, resto);
  //printf("a");
  if (!resto[i])
  {
    return (aux);
  }
  while(ft_strchr(resto, 10) == -1 && byte_read != 0)
  {
    resto = ft_read(fd, &byte_read, resto);
    if (byte_read == 0)
      break;
    if (resto == NULL)
      return (NULL);
    //printf("a");
  }
  if(ft_strchr(resto, 10) == -1)
  {
    while (resto[i] != '\0')
      i++;
    resto[i] = '\n';
  }
  if(ft_strchr(resto, 10) != -1)
  {
    // printf("SOBRA==%s==\n",ft_substr(resto, ft_strchr(resto, 10) + 1, byte_read));
    aux = ft_substr(resto, 0, ft_strchr(resto, 10));
    resto = guardar(resto);
    //printf("^%s^",resto);
  }
    return(aux);
}

void leaksssss()
{
	system ("leaks a.out");
	return;
}
/* int	main(void)
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
    leido = get_next_line(fd);
    printf("---main---\n");
    printf("%s", leido);
     
   while (leido)
    {
    printf("%s", leido);
    fflush(stdin);
    free(leido);
    leido = get_next_line(fd);
    } 
    
  free(leido);
	close(fd);
  //atexit(leaksssss);
	return (0);
} */