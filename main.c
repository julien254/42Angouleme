#include <stdio.h>
#include <unistd.h>

int main() {
	    long size = fpathconf(fileno(stdin), _PC_NAME_MAX);
		    if (size == -1) {
				        perror("Error getting buffer size");
						        return 1;
								    }

			    printf("Buffer size of stdin: %ld\n", size);

				    return 0;
}
