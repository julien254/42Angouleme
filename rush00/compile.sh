#!/bin/bash
echo Compilation rush00
echo Numero de l\'ex a compiler ?
read ex
gcc -Wall -Werror -Wextra main.c rush$ex.c ft_putchar.c
status=$?
if [ $status -eq 0 ]
then
	echo pas d\'erreur de compil
fi
