/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:00:31 by jlara-na          #+#    #+#             */
/*   Updated: 2022/09/13 14:24:14 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//Here is is defined a buffer size to be used by the read function.

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//Here it is defined the max amount of file descriptor per process.

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

//This is the main function of the program, the one wich will return the line 
//from a file.

char	*get_next_line(int fd);

//UTILS

void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);

#endif
