/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esamad-j <esamad-j@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 03:40:13 by esamad-j          #+#    #+#             */
/*   Updated: 2023/02/06 17:02:36 by esamad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *str1, char const *str2);

char	*get_next_line(int fd)
{
    char *buffer;
    char *aux;
    char *aux2;
	size_t nread;
    int i = 0;
    buffer = malloc(150);
    aux = malloc (150);
    aux2 = malloc (150);
    nread = read(fd, buffer, BUFFER_SIZE);
    
    strcpy(aux, buffer);
    /* printf("%s\n", aux); */
    /* buffer = bzero(buffer, BUFFER_SIZE); */
    /* printf("%s\n", aux); */
    while (ft_strchr(buffer, 10) == 0)
    {
        nread = read(fd, buffer, BUFFER_SIZE);
        if (ft_strchr(buffer, 10) == 0)
        {
            strcpy(aux, ft_strjoin(aux, buffer));
           /*  printf("----if---\n");
            printf("%s\n", aux);
            printf("----if---\n");*/
        } 
        
       /*  printf("----2---\n");
        printf("%zi\n", nread);
        printf("%s\n", buffer);
        printf("-------\n"); */
    }
    
    if (nread == -1)
    {
        printf("ERROR EN READ");
        return (0);
    }
    while (buffer[i] != '\0')
    {
        if (buffer[i] == 10)
        {
            aux2 = ft_substr(buffer, 0, i);
             /* printf("%s\n", aux2); */
        }
        i++;
    }
    if(buffer == NULL)
        return 0;
    return (ft_strjoin(aux, aux2));
}

int	main(void)
{
	char *leido;
    int i = 0;
	int fd = open("hola.txt", O_RDONLY);
	if (fd < 0)
		printf("cagaste, ERROR EN OPEN");
    leido = get_next_line(fd);
    printf("---main---\n");
    while (leido)
    {
    printf("%s\n", leido);
    free(leido);
    leido = get_next_line(fd);
    }
    printf("-------\n");
	close(fd);
	return (0);
}