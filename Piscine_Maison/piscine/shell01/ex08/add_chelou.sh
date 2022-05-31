#!/bin/sh

echo "ibase=5;obase=23;$(echo $FT_NBR1+$FT_NBR2 | sed 'y/mrdoc/01234/' | tr \' 0 | tr '\\' '1' | tr \" 2 | tr \? 3 | tr \! 4)" | bc | tr '0123456789ABC' 'gtaio luSnemf'