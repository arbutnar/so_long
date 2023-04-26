/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 23:27:04 by arbutnar          #+#    #+#             */
/*   Updated: 2022/02/13 23:28:05 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_get_line(char *save);
char	*ft_read_and_save(int fd, char *save);
char	*ft_save(char *save);
char	*ft_strchr(char *save);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);

#endif
