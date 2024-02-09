#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	size_cpy;
	
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (old_size < new_size)
		size_cpy = old_size;
	else
		size_cpy = new_size;
	ft_memcpy(new_ptr, ptr, size_cpy);
	free(ptr);
	return (new_ptr);
}
