/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:08:36 by bbixby            #+#    #+#             */
/*   Updated: 2018/11/01 14:08:37 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_piece
{
    int             w;
    int             h;
    int             pt[4];
}					t_piece;

int			*ft_setintarr(int *arr);
char	    *ft_readfile(char *file, int *arr, char *str);
int		    ft_readandverify(char *argv, char ***pieces, int *arr);

int			ft_verify(char *str, int *arr, char ***pieces);
void        ft_mallocpieces(char ***pieces, int count);
int		    tetriminocheck(char *piece);
int         ft_error(void);
void        ft_printshiznit(char **pieces, int count);

int         ft_solver(char **pieces, int count);
void        newboard(char **board, int count, int newsize);
void        ft_createpieces(char **pieces, int count, t_piece **arr);

#endif