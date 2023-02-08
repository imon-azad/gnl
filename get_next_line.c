/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esamad-j <esamad-j@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 03:40:13 by esamad-j          #+#    #+#             */
/*   Updated: 2023/02/08 13:23:56 by esamad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd)
{
    char *buffer;
    char *aux;
    char *aux2;
    static char *guardado;
    static int k = 0;
	size_t nread;
    int i = 0;
    buffer = malloc(BUFFER_SIZE);
    aux = malloc (150);
    aux2 = malloc (150);
    guardado = malloc(150);
    nread = read(fd, buffer, BUFFER_SIZE);
     if (nread == -1)
    {
        printf("ERROR EN READ");
        return (0);
    }

    while (ft_strchr(buffer, 10) == 0)
    {
        printf("%s\n", aux);
        while (buffer[i] != '\0')
        {
            aux[k] = buffer[i];
            i++;
            k++;
        }
        i = 0;
        printf("%s", aux);
        printf("%s\n", buffer);
        printf("-------\n");
        
        nread = read(fd, buffer, BUFFER_SIZE);
        /*  printf("%s\n", buffer);
         */
        /* if (ft_strchr(buffer, 10) == 0)
        {
            strcpy(aux, ft_strjoin(aux, buffer));
            printf("----if---\n");
            printf("%s\n", aux);
            printf("----if---\n");
        }  */
        
        /* printf("----2---\n");
        printf("%zi\n", nread);
        printf("%s\n", buffer);
        printf("%s\n", aux);
        printf("-------\n"); */
    }
    
    while (buffer[i] != '\0')
    {
        if (buffer[i] == 10)
        {
            aux2 = ft_substr(buffer, 0, i);
            strlcpy(guardado, buffer, BUFFER_SIZE + 1);
            printf("guardado:_%s_", guardado);
            break;
             printf("%s", aux2);
             printf("---aux2--\n");
        }
        i++;
    }
    
    printf("%s", aux2);
    return (ft_strjoin(aux, aux2));
}

int	main(void)
{
	char *leido;
    int fd;
    
	fd = open("hola.txt", O_RDONLY);
	if (fd < 0)
		printf("cagaste, ERROR EN OPEN");
    leido = get_next_line(fd);
    printf("---main---\n");
    printf("%s", leido);
  /*   free(leido);
    leido = get_next_line(fd);
    printf("---main---\n");
    printf("%s", leido); */
   /*  while (leido)
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