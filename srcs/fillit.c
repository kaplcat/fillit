/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeqqo <gbeqqo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:07:00 by gbeqqo            #+#    #+#             */
/*   Updated: 2019/04/29 14:57:33 by bellyn-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			fillit(t_list *list, char **desk, int size, int a)
{
	while (list->pos < size * size)
	{
		a = adding(desk, size, list);
		if (a == 1)
			return (0);
		else
		{
			addtoboard(desk, size, list->content, list->pos);
			if (list->next != NULL)
			{
				a = fillit(list->next, desk, size, 0);
				if (a == 0)
				{
					default_tet(desk, list, size);
					list->pos += 1;
					list->next->pos = 0;
				}
				else
					return (1);
			}
			else
				return (1);
		}
	}
	return (0);
}

int			solver(t_list *list)
{
	char	**desk;
	int		size;

	size = boardsize(list);
	desk = createboard(size);
	while (!(fillit(list, desk, size, 0)))
	{
		emptyboard(desk, size);
		freeboard(desk, size);
		size += 1;
		if (!(desk = createboard(size)))
			return (0);
		restorepos(list);
	}
	printboard(desk, size);
	freeboard(desk, size);
	return (1);
}

int			adding(char **board, int size, t_list *list)
{
	int		a;
	t_tetr	*tetr;

	tetr = list->content;
	a = boardchecker(board, size, tetr, list->pos);
	if (a == 0)
		return (0);
	if (a == 1)
	{
		while (boardchecker(board, size, tetr, list->pos) == 1)
		{
			list->pos += 1;
			if (list->pos == size * size - 1)
				return (1);
		}
	}
	return (0);
}

void		restorepos(t_list *list)
{
	while (list != NULL)
	{
		list->pos = 0;
		list = list->next;
	}
}
