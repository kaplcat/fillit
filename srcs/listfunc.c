/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeqqo <gbeqqo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:03:43 by gbeqqo            #+#    #+#             */
/*   Updated: 2019/04/29 14:57:12 by bellyn-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = malloc(content_size);
		if (new->content == NULL)
			return (NULL);
		ft_memmove(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}

int			listlen(t_list *list)
{
	int n;

	n = 0;
	while (list)
	{
		list = list->next;
		n++;
	}
	return (n);
}

t_list		*createtr(char *buf, char a)
{
	t_list	*head;
	t_tetr	tetrimino;

	buf_checker(buf);
	tetrimino.letter = a;
	tetrimino.shape = createshape(buf, a);
	moveleft(tetrimino.shape, a);
	tetrimino.height = height(tetrimino.shape, a);
	moveup(tetrimino.shape, a, tetrimino.height);
	tetrimino.width = width(tetrimino.shape, a);
	valid_tetr(&tetrimino);
	head = ft_lstnew(&tetrimino, sizeof(tetrimino));
	head->pos = 0;
	head->content_size = 0;
	return (head);
}

void		deletelist(t_list **headref)
{
	t_list	*current;
	t_list	*next;
	char	**shape;
	t_tetr	*a;

	current = *headref;
	while (current != NULL)
	{
		a = current->content;
		shape = a->shape;
		freeshape(shape);
		next = current->next;
		free(a);
		free(current);
		current = next;
	}
	*headref = NULL;
}

void		push_end(t_list **list, t_list *head)
{
	t_list *new;

	new = *list;
	if (new == NULL)
	{
		*list = head;
	}
	else
	{
		while (new->next)
		{
			new = new->next;
		}
		new->next = head;
	}
}
