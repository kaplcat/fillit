/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellyn-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 12:01:09 by bellyn-t          #+#    #+#             */
/*   Updated: 2019/04/29 12:03:37 by bellyn-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	stop(void)
{
	ft_putstr("error\n");
	exit(0);
}

t_list	*read_and_getlst(const int fd)
{
	t_list	*list;
	t_list	*head;
	int		ret;
	char	buf[21];
	char	a;

	a = 'A';
	list = NULL;
	while ((ret = read(fd, buf, 21)) && ret != -1)
	{
		buf[ret] = '\0';
		if (buf[0] == '\n')
			stop();
		if (a > 'Z')
			stop();
		if (buf[ret - 1] != '\n')
			stop();
		head = createtr(buf, a++);
		push_end(&list, head);
	}
	if (list == NULL || buf[20] == '\n')
		stop();
	return (list);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*list;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			stop();
		fd = open(argv[1], O_RDONLY);
		list = read_and_getlst(fd);
		if (close(fd) == -1)
			stop();
		solver(list);
		deletelist(&list);
	}
	else
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" [input_file]\n");
		return (-1);
	}
	return (0);
}
