#!/bin/sh
echo "Installation et configuation du pare-feu UFW..."
sudo apt install ufw -y && sudo ufw enable && sudo systemctl start ufw && sudo systemctl enable ufw && sudo ufw allow 4242 && sudo ufw allow 22 && sudo systemctl restart ufw
echo "Installation et configuration du pare-feu UFW termine."
echo "Installation et configuration de SSH."
sudo apt install openssh-server -y
sudo curl https://raw.githubusercontent.com/julien254/42Angouleme/main/TroncCommun/born2beroot/sshd_config > /etc/ssh/sshd_config
