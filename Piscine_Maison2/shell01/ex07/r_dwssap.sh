#!/bin/sh
cat /etc/passwd | grep -v "^#" | awk 'NR % 2 == 0' | rev | awk -F":" '{print $NF}' | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | sed ':a;N;$!ba;s/\n/, /g' | tr '\n' '.'
