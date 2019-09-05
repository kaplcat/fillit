/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeqqo <gbeqqo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:31:09 by gbeqqo            #+#    #+#             */
/*   Updated: 2019/04/29 11:52:56 by bellyn-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_list{
	void			*content;
	size_t			content_size;
	int				pos;
	struct s_list	*next;
}					t_list;

typedef struct		s_tetr{
	int				height;
	int				width;
	char			letter;
	char			**shape;
	int				i;
	int				j;
	int				c;
	int				x;
	int				y;
}					t_tetr;

t_list				*read_and_getlst(const int fd);
t_list				*createtr(char *buf, char a);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				deletelist(t_list **headref);
void				push_end(t_list **list, t_list *head);
char				**createshape(char *buf, char a);
void				trim(char **bufnew, char *buf, char a);
void				freeshape(char **shape);
int					height(char **shape, char a);
int					width(char **shape, char a);
int					bricks_touch(char **shape, char a);
int					count(char **shape, int i, int j, char a);
int					quantity(char **shape, char a);
void				valid_tetr(t_tetr *tetr);
void				stop(void);
void				buf_checker(char *buf);
void				end_checker(char *buf);
int					boardsize(t_list *list);
char				**createboard(int s);
int					checkmoveup(char **shape, char a, int i, int j);
void				default_line(char *line);
void				moveup(char **shape, char a, int h);
int					needtomove(char **shape, char a, int i, int j);
void				moveleft(char **shape, char a);
void				default_tet(char **board, t_list *list, int size);
int					addtoboard(char **board, int size, t_tetr *tetr, int pos);
int					listlen(t_list *list);
void				freeboard(char **board, int size);
int					boardchecker(char **board, int size, t_tetr *tetr, int pos);
void				emptyboard(char **board, int size);
void				restorepos(t_list *list);
size_t				factorial(size_t n);
int					fillit(t_list *list, char **desk, int size, int a);
int					solver(t_list *list);
int					adding(char **board, int size, t_list *list);
void				ass(char **shape, int h);
void				printboard(char **desk, int size);
void				ft_putstr(char const *s);
void				ft_putchar(char c);

#endif
