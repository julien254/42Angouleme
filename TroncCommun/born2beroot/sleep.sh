#!/bin/sh

MIN=$(uptime -s | cut -d ":" -f 2)
SEC=$(uptime -s | cut -d ":" -f 3)
DELAY=$(echo $MIN%10*60+$SEC | bc)
sleep $DELAY
