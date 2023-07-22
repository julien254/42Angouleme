#include <unistd.h>

void print_solution(int *array, int array_size)
{
    int i;

    i = 0;
    while (i < (array_size * array_size))
    {
        write (1, &(char){array[i] + 48}, 1);

        if (i % array_size  < array_size - 1)
        {
            write (1, " ", 1);
        }
        if (i % array_size == array_size -1)
        {
            write(1, "\n", 1);
        }

        i++;
    }

}
