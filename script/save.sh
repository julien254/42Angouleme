#!/bin/bash
echo Nom du fichier ?
read message
cp $message ~/Bureau/Devlinux/42Angouleme/save/save_$message;
status=$?
if [ $status -eq 0 ]
then
	echo "Fichier sauvegarde dans le repertoire "42Angouleme/save/".  (save_$message)"
fi
