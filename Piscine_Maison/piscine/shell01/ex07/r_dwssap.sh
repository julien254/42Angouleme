#!/bin/sh

cat /etc/passwd | grep -v "#" | sed -n 2~2p | cut -d : -f 1 | rev | sort -r | sed -n ''"$FT_LINE2"','"$FT_LINE2"'p' | tr '\n' ',' | sed 's/,$//' | sed 's/$/./'