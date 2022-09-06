#!/bin/sh
echo "Installation de BC (Calculatrice)..."
sudo apt-get install bc -y
cd ~
echo "Mise en place du monitoring.sh"
sudo systemctl enable cron
sudo cp 42Angouleme/TroncCommun/born2beroot/monitoring.sh /root/
sudo cp 42Angouleme/TroncCommun/born2beroot/sleep.sh /root/
sudo chmod 755 /root/monitoring.sh /root/sleep.sh
sudo cp 42Angouleme/TroncCommun/born2beroot/root-crontab.sh /var/spool/cron/crontabs/root
echo "Monitoring operationel !"
