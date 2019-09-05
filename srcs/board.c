/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeqqo <gbeqqo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:36:48 by gbeqqo            #+#    #+#             */
/*   Updated: 2019/04/29 12:00:08 by bellyn-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**createboard(int s)
{
	int		i;
	int		j;
	char	**board;

	i = 0;
	if (!(board = (char **)malloc(sizeof(char *) * s)))
		return (NULL);
	while (i < s)
	{
		board[i] = (char *)malloc(sizeof(char) * s + 1);
		i++;
	}
	i = 0;
	while (i < s)
	{
		j = 0;
		while (j < s)
		{
			board[i][j++] = '.';
		}
		board[i][j] = '\0';
		i++;
	}
	return (board);
}

void	freeboard(char **board, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(board[i]);
		i++;
	}
	free(board);
}

void	printboard(char **desk, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr(desk[i]);
		ft_putchar('\n');
		i++;
	}
}

int		boardsize(t_list *list)
{
	int		i;
	int		fig_count;
	t_tetr	*tetr;

	i = 2;
	fig_count = listlen(list);
	tetr = list->content;
	if (fig_count == 1)
	{
		if (tetr->width == 4 || tetr->height == 4)
			return (4);
		if (tetr->width == 3 || tetr->height == 3)
			return (3);
		if (tetr->width == 2 || tetr->height == 2)
			return (2);
	}
	while (i * i < fig_count * 4)
		i++;
	return (i);
}

void	emptyboard(char **board, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			board[i][j] = '.';
			j++;
		}
		i++;
	}
}
