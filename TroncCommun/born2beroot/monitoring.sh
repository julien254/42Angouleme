#!/bin/sh
wall -n "#Architecture: $(uname -srvmo)
#CPU physical: $(grep 'physical id' /proc/cpuinfo | uniq | wc -l)
#vCPU : $(grep 'processor' /proc/cpuinfo | uniq | wc -l)
#Memory Usage: $(free -h | grep Mem | awk '{print $3}')/$(free -h | grep Mem | awk '{print $2}')($(free | grep Mem | awk '{printf("%.2f%%"), $3 / $2 * 100}'))
#CPU load: $(top -bn1 | grep '^%Cpu' | awk '{printf("%.1f%%"), $2 + $3 + $4}')
#Last boot: $(who -b | awk '{print($3 " " $4)}')
#LVM use: $(if [ $(lsblk | grep lvm | wc -l ) -eq 0 ]; then echo no; else echo yes; fi)
#Connection TCP: $(grep TCP /proc/net/sockstat | awk '{print $3}') ESTABLISHED
#User log: $(who -u | wc -l)
#Network: IP $(hostname -I | awk '{print $1}') ($(ip link show | grep link/ether | awk '{print $2}'))
#Sudo: $(cat /var/log/sudo/sudo.log | grep COMMAND | wc -l) cmd"
