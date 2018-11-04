/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 01:13:39 by bbixby            #+#    #+#             */
/*   Updated: 2018/11/03 01:13:41 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#define ABS(i)	((i < 0) ? (-i) : (i))

/*
** initializes board or increases board size, of newsize is 0 then it initializes board
** else pass this function the size you want it to be in new size
*/
void    newboard(char **board, int count, int newsize)
{
    int i;
    int j;

    i = 2;
    j = -1;
    count *= 4;
    if (!newsize)
        while (i *= i < count)
            i += 1;
    else
        i = newsize;
    if (!(board = (char **)malloc(sizeof(char *) * (i))))
        return ;
    while (++j < i)
        if (!(board[j] = (char *)malloc(sizeof(char) * i)))
            return;
}

void    ft_createpieces(char **pieces, int count, t_piece **arr)
{
    int i;
    int j;
    int hashcnt;
    int temp;

    i = -1;
    while (++i < count)
    {
        j = -1;
        hashcnt = 0;
        while (++j < 20)
        {
            if (pieces[i][j] == '#')
            {
                if (j < 4)
                    temp = 10 + j;
                else if (j < 9)
                    temp = 20 + j - 5;
                else if (j < 14)
                    temp = 30 + j - 10;
                else
                    temp = 40 + j - 15;
                arr[i]->pt[hashcnt] = temp;
                hashcnt++;
            }
        }
        arr[i]->w = ABS((arr[i]->pt[0] % 10 - arr[i]->pt[3] % 10)) + 1;
        arr[i]->h = ABS((arr[i]->pt[0] / 10 - arr[i]->pt[3] / 10)) + 1;
        printf("%s %s \n", "piece: ", pieces[i]);
        printf("%s %d %s %d  %s %d %d %d %d \n", "width: ", arr[i]->w, "height: ", arr[i]->h, "coords: ", arr[i]->pt[0], arr[i]->pt[1], arr[i]->pt[2], arr[i]->pt[3]);
    }
}

int     ft_solver(char **pieces, int count)
{
    char    c;
    char    **board;
    t_piece **piecearr;
    int     i;

    c = pieces[0][0];
    i = -1;
    newboard(board, count, 0);
    if (!(piecearr = (t_piece **)malloc(sizeof(t_piece *) * count)))
        return (0);
	while (++i < count)
		if (!((piecearr)[i] = (t_piece *)malloc(sizeof(t_piece))))
			return (0);
    ft_createpieces(pieces, count, piecearr);
    return (0);
}