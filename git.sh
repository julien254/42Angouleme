#!/bin/bash
echo message commit ??
read message
git add -A && git commit -m "$message"
status=$?
if [ $status -eq 0 ]
then
	echo Fichier ajouter et commité !
fi
