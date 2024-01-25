#include <unistd.h>
int	main(int argc, char *argv[], char**envp)
{
	(void)argc;
	(void)argv;
	execve("/bin/awk",(char*[]){"awk", "{ total += $1 } END { print \"Sum:\", total }", NULL}, envp); 
	return (0);
}
