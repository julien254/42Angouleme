#!/bin/sh

id -Gn $FT_USER | tr ' ' ',' | tr -d '\n'

groups $FT_USER | tr ' ' ',' | tr -d '\n'
