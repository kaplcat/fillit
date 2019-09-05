/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slavastrdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeqqo <gbeqqo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:38:46 by gbeqqo            #+#    #+#             */
/*   Updated: 2019/04/29 13:45:19 by bellyn-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		valid_tetr(t_tetr *tetr)
{
	int t;
	int q;

	t = bricks_touch(tetr->shape, tetr->letter);
	q = quantity(tetr->shape, tetr->letter);
	if (q == 4 && t == 8)
	{
		if (tetr->height != 2 && tetr->width != 2)
			stop();
	}
	else if (q == 4 && t != 6)
		stop();
}

void		freeshape(char **shape)
{
	int i;

	i = 0;
	while (i < 5)
		free(shape[i++]);
	free(shape);
}

char		**createshape(char *buf, char a)
{
	char	*newbuf;
	char	**shape;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	newbuf = (char *)malloc(sizeof(char) * 17);
	trim(&newbuf, buf, a);
	if (!(shape = (char**)malloc(sizeof(char *) * 5)))
		return (NULL);
	shape[4] = NULL;
	while (i < 4)
	{
		if (!(shape[i] = (char*)malloc(5)))
			return (NULL);
		j = 0;
		while (j < 4)
			shape[i][j++] = newbuf[k++];
		shape[i++][j] = '\0';
	}
	free(newbuf);
	return (shape);
}

void		trim(char **bufnew, char *buf, char a)
{
	char	*new;
	int		i;
	int		j;
	int		c;

	j = 0;
	i = 0;
	c = 0;
	new = *bufnew;
	while (j < 16)
	{
		if (buf[c] == '#')
		{
			new[i++] = a;
			j++;
		}
		else if (buf[c] == '.')
		{
			new[i++] = '.';
			j++;
		}
		c++;
	}
	new[i] = '\0';
}

void		default_tet(char **board, t_list *list, int size)
{
	int		i;
	int		j;
	t_tetr	*tetr;

	tetr = list->content;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (board[i][j] == tetr->letter)
				board[i][j] = '.';
			j++;
		}
		i++;
	}
}
