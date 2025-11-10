/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 07:52:09 by jemonthi          #+#    #+#             */
/*   Updated: 2025/11/10 07:53:39 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

size_t	len(const char *s);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);

char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

#endif
