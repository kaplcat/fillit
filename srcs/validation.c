/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeqqo <gbeqqo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:48:41 by gbeqqo            #+#    #+#             */
/*   Updated: 2019/04/29 15:23:15 by bellyn-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		count(char **shape, int y, int x, char a)
{
	int t;

	t = 0;
	if (shape[y][x] == a)
	{
		if (y == 3)
		{
			if ((shape[y - 1][x] == a) || (shape[y][x + 1] == a))
				t += 1;
			if (x > 0 && shape[y][x - 1] == a)
				t += 1;
		}
		else
		{
			if (shape[y][x + 1] == a)
				t += 1;
			if (x > 0 && shape[y][x - 1] == a)
				t += 1;
			if (y > 0 && shape[y - 1][x] == a)
				t += 1;
			if (shape[y + 1][x] == a)
				t += 1;
		}
	}
	return (t);
}

int		bricks_touch(char **shape, char a)
{
	int i;
	int j;
	int t;
	int y;

	i = 0;
	t = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			y = count(shape, i, j, a);
			t = y + t;
			j++;
		}
		i++;
	}
	return (t);
}

int		quantity(char **shape, char a)
{
	int i;
	int	j;
	int c;

	i = 0;
	c = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (shape[i][j] == a)
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

void	buf_checker(char *buf)
{
	int d;
	int l;
	int i;

	i = 0;
	d = 0;
	l = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '.')
			d += 1;
		if (buf[i] == '#')
			l += 1;
		i++;
	}
	if (d != 12 || l != 4)
		stop();
	end_checker(buf);
}

void	end_checker(char *buf)
{
	int flag;
	int i;

	flag = 0;
	i = 4;
	while (i < 20)
	{
		if (buf[i] != '\n')
			flag = 1;
		i += 5;
	}
	if (flag == 1)
		stop();
}
