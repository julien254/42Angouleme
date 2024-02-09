#include "libft.h"

int	main(int argc, char *argv[])
{
	char **map_2d;

	(void)argc;
	(void)argv;
	map_2d = ft_recover_fd(argv[1]);	
	ft_puttab2_fd(map_2d, 1);
	return (0);
}
