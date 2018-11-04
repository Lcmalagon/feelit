/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:08:27 by bbixby            #+#    #+#             */
/*   Updated: 2018/11/01 14:08:28 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

int			*ft_setintarr(int *arr)
{
	arr[0] = -1;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
	arr[4] = -1;
	return (arr);
}

char	*ft_readfile(char *file, int *arr, char *str)
{
	int		ret;
	int		fd;

	str = (char*)malloc(sizeof(char) * 546);
	fd = open(file, O_RDONLY);
	while ((ret = read(fd, str, 545)) > 0 && ret < 545)
	{
		str[ret] = '\0';
		arr[0] = ((ret + 2) % 21 != 0 ? (0) : ((ret + 2) / 21));
	}
	if (arr[0] > 26 || arr[0] < 1 || ret > 544)
	{
		free (str);
		ft_putstr("error\n");
		return (NULL);
	}
	return (str);
}

int		ft_readandverify(char *argv, char ***pieces, int *arr)
{
	char	*str;

	str = ft_readfile(argv, arr, str);
	if (str)
	{
		ft_mallocpieces(pieces, arr[0]);
		return (ft_verify(str, arr, pieces));
	}
	return (0);
}

int			main(int argc, char **argv)
{
	int		fd;
	char	**pieces;
	int		verified;
	int		arr[5];

	*arr = *ft_setintarr(arr);
    if (argc != 2)
        ft_putstr("usage: fillit input_file\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		fd < 0 ? (ft_putstr("error\n")) :\
			(verified = ft_readandverify(argv[1], &pieces, arr));
		if (verified)
		{
			// ft_printshiznit(pieces, arr[0]);
			ft_solver(pieces, arr[0]);
		}
		close(fd);
	}
	return (0);
}