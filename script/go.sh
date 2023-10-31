#!/bin/bash

if [ $# -lt 1 ]; then
	echo "Usage : go [Nom du Fichier/Dossier] [Pattern 1] [Pattern 2]... (plus il y a de Pattern, plus la recherche serat precise.)"
	exit 1
fi
ways=$(find ~/ -type d -iwholename "*/$1" -o -type f -iwholename "*/$1" 2> /dev/null)
for arg in "$@"
do
	ways=$(echo $ways | tr ' ' '\n' | grep -i $arg)
done

ways=$(echo $ways | tr '\n' ' ')

read -r -a ways_array <<< "$ways"

if [ ${#ways_array[@]} -le 1 ]; then
	path="${ways_array[0]}"
	if [ -f "$path" ]; then
		vim "$path"
	else
		cd "$path"
		exec zsh
	fi
	exit 1
else
	# Afficher chaque chemin du ways_array
	i=1
	for way in "${ways_array[@]}"; do
		echo "$i : $way"
		i=$(($i+1))
	done
	read -p "Which folder/file do you want to go ? " choice
	path="${ways_array[choice - 1]}"
	if [ -f "$path" ]; then
		vim "$path"
	else
		echo $path
		cd "$path"
		exec zsh
	fi
fi


#faire les commentaire
#creer le raccourci dans le zshrc
#creer un script d'installation
