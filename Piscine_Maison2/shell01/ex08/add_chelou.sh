#!/bin/sh
NBR1=$(echo $FT_NBR1 | tr '\\' '1' | tr "'\"?\!" "0234") ; NBR2=$(echo $FT_NBR2 | tr "mrdoc" "01234"); echo "obase=13;ibase=5;$NBR1 + $NBR2" | bc | tr "0123456789ABC" "gtaio luSnemf"
