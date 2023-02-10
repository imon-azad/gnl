/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esamad-j <esamad-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 03:40:13 by esamad-j          #+#    #+#             */
/*   Updated: 2023/02/10 20:01:39 by esamad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif
char *sobrante(char *buffer)
{
    char *guardado;
    int i;
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
		i++;
    guardado = malloc(i + 2);
    guardado = ft_substr(buffer, i + 1 , BUFFER_SIZE - i);
    
    return (guardado);
    
}
char *ft_read(int fd, char *buffer, int *nread)
{
  buffer = malloc(BUFFER_SIZE + 1);
  *nread = read(fd, buffer, BUFFER_SIZE);
    if (*nread == -1)
    {
        printf("ERROR EN READ");
        return (0);
    }
    return (buffer);
}
char *liberar(char *buffer, char *buf2)
{
    char *tem;
    
    tem = ft_strjoin(buffer, buf2);
    free(buffer);
    return (tem);
}
/* char *linea(char *buffer)
{
    
} */
char	*get_next_line(int fd)
{
    char *aux;
    static char *buffer;
    size_t nread;
    int j = 0;
    int i = 0;
    

    aux = malloc (150);

    printf("_%s_", buffer);
    if(buffer == NULL)
        buffer = ft_read(fd, buffer, &nread);
    
    while (ft_strchr(buffer, 10) == 0 && buffer[i])
    {
        while (buffer[i] != '\0')
        {
            aux[j] = buffer[i];
            i++;
            j++;
            
        }
        
        i = 0;
        free(buffer);
        buffer = ft_read(fd, buffer);
        
        /* if (!buffer[i])
        {
            
            if (ft_strchr(buffer, 10) == 0)
                {
                    buffer[i] = '\n';
                }
        } */
    }
    
    while (buffer[i] != '\0')
    {
        if (buffer[i] == 10)
        {
            aux = liberar(aux, ft_substr(buffer, 0, i));
            break;
        }
        i++;
    }
    buffer = sobrante(buffer);
    return (aux);
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
    leido = get_next_line(fd);
    printf("---main---\n");
    printf("%s", leido);
    free(leido);
    leido = get_next_line(fd);
    printf("---main---\n");
    printf("%s", leido); 
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