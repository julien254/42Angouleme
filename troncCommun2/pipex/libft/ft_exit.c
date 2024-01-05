#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
void	ft_exit(int nbFd, int nbptr, int exit_type, ...)
{
	va_list	args;
	int	i;

	i = 0;
	while (i <= nbFd)
	{
		close(va_arg(args, int));
		i++;
	}

	while (i <= nbFd + nbptr)
	{
		free(va_arg(args, void *));
		i++;
	}
	if (exit_type == 1)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}
#include <stdio.h>
int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	char	*ptr;
	int	*ptrint;

	ptr = (malloc(10));
	ptrint = (malloc(sizeof(int) * 2));
	ptrint[0] = 1;
	ptrint[1] = 2;
	ptr[0]= '7';
//	ft_exit(0, 2, 1, ptr, ptrint);
	printf("%d", ptrint[1]);

	return (0);
}
