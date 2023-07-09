# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    gitp.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdetre <julien.detre.dev@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 16:15:12 by jdetre            #+#    #+#              #
#    Updated: 2023/07/09 16:19:08 by jdetre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#!/bin/bash

git add -A && git commit -m "..."
status=$?
if [ $status -eq 0 ]
then
	echo Fichier ajouter, commité!
fi
git push
status=$?
if [ $status -eq 0 ]
then
	echo Fichier pusher!
fi
