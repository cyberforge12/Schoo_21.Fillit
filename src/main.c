#include "fillit.h"

void	ft_free_list(void *content, size_t size)
{
	t_tetris	*tet;

	tet = (t_tetris*)content;
	if (!content)
		return ;
	ft_clear_table(tet->table, tet->height + 1);
	free(tet);
	tet = NULL;
	size = 0;
}


int		main(int argc, char **argv)
{
	int		fd;
	t_list	*list;
	char	**map;
	int		size;

	if (argc != 2)
	{
		ft_putstr("usage: fillit source file\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	list = ft_read_fd(fd);
	map = ft_fill_square(list, &size);
	ft_display(map);
	ft_clear_table(map, size);
	ft_lstdel(&list, &ft_free_list);
	close (fd);
	return (0);
}