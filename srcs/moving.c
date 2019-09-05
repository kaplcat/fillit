/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellyn-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:59:16 by bellyn-t          #+#    #+#             */
/*   Updated: 2019/04/29 11:59:19 by bellyn-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		ass(char **shape, int h)
{
	if (h == 1)
	{
		ft_memcpy(shape[0], shape[1], 4);
		default_line(shape[1]);
	}
	else if (h == 2)
	{
		ft_memcpy(shape[0], shape[1], 4);
		default_line(shape[1]);
		ft_memcpy(shape[1], shape[2], 4);
		default_line(shape[2]);
	}
	else if (h == 3)
	{
		ft_memcpy(shape[0], shape[1], 4);
		default_line(shape[1]);
		ft_memcpy(shape[1], shape[2], 4);
		default_line(shape[2]);
		ft_memcpy(shape[2], shape[3], 4);
		default_line(shape[3]);
	}
}

void		moveleft(char **shape, char a)
{
	int		i;
	int		j;
	int		move;

	i = 0;
	move = needtomove(shape, a, 0, 0);
	if (move == 0)
		return ;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (shape[i][j] == a)
			{
				shape[i][j - move] = shape[i][j];
				shape[i][j] = '.';
			}
			j++;
		}
		i++;
	}
}

int			needtomove(char **shape, char a, int i, int j)
{
	int n;
	int space;

	space = 0;
	while (j < 4)
	{
		i = 0;
		n = 0;
		while (i < 4)
		{
			if (shape[i][j] == '.')
				n++;
			else if (shape[i][j] == a)
				return (space);
			i++;
		}
		if (n == 4)
			++space;
		j++;
	}
	return (space);
}

void		moveup(char **shape, char a, int h)
{
	int s;

	s = checkmoveup(shape, a, 0, 0);
	if (s == 3)
	{
		ft_memcpy(shape[0], shape[3], 4);
		default_line(shape[3]);
	}
	else if (s == 2)
	{
		ft_memcpy(shape[0], shape[2], 4);
		ft_memcpy(shape[1], shape[3], 4);
		default_line(shape[2]);
		default_line(shape[3]);
	}
	else if (s == 1)
	{
		ass(shape, h);
	}
}

int			checkmoveup(char **shape, char a, int i, int j)
{
	int f;
	int space;

	space = 0;
	while (i < 4)
	{
		j = 0;
		f = 0;
		while (j < 4)
		{
			if (shape[i][j] == '.')
				f++;
			else if (shape[i][j] == a)
				return (space);
			j++;
		}
		if (f == 4)
			++space;
		i++;
	}
	return (space);
}
