/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imonazad <imonazad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:57:23 by esamad-j          #+#    #+#             */
/*   Updated: 2023/02/25 02:31:22 by imonazad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h> //open in main
# include <stdio.h> //printf and fflush
# include <stdlib.h> //malloc free
# include <unistd.h> //read, close

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);

char	*ft_strjoin_gnl(char *str1, char *str2);
int		ft_strchr_gnl(const char *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *src);
void	*ft_calloc(size_t count, size_t size);

#endif