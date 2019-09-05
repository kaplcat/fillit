/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtwo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeqqo <gbeqqo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:09:16 by gbeqqo            #+#    #+#             */
/*   Updated: 2019/04/29 11:56:45 by bellyn-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		default_line(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		line[i] = '.';
		i++;
	}
}

int			height(char **shape, char a)
{
	int i;
	int j;
	int h;

	i = 0;
	h = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (shape[i][j] == a)
			{
				h++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (h);
}

int			width(char **shape, char a)
{
	int i;
	int j;
	int c;
	int t;

	t = 0;
	c = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (shape[i][j] == a)
				c = j + 1;
			j++;
		}
		if (c >= t)
			t = c;
		i++;
	}
	return (t);
}

size_t		factorial(size_t n)
{
	if (n == 0)
		return (1);
	return (n * factorial(n - 1));
}
