#!/bin/bash
echo "Installation de ZSH"
sudo apt install zsh -y
sudo cp 42Angouleme/TroncCommun/born2beroot/passwd /etc/passwd
echo "Installation de ZSH termine."
cd ~
sudo groupadd user42
sudo usermod -aG user42 jdetre
echo "Installation de Git ----->"
sudo apt install git -y
git clone https://github.com/julien254/42Angouleme.git
echo "Installation de Git termine."
echo "Installation des composant essentiel ----->"
sudo apt install -y build-essential python3.9 python3.9-dev libncurses-dev curl
echo "Installation des composant essentiel termine."
echo "Installation de vim 8.2 avec python ----->"
echo "Installation de vim 8.2 avec python termine."
echo "Installation de Oh-My-Zsh ----->"
curl -L https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh | sh
echo "Installation de Oh-My-Zsh termine."
echo "Configuration Zsh et vim en cours..."
cd 42Angouleme/ConfigLinux/
sudo cp -r .vim/ /root/
cp -r .vim/ ~/
sudo cp .vimrc /root/
cp .vimrc ~/
cp .zshrc ~/
sudo cp .zshrc /root/
sudo cp -r ~/.oh-my-zsh /root/
cd ~
echo "Configuration Zsh et vim termine"
echo "lancer vim et taper ':PlugInstall' pour finaliser l'installation des plugins. (Pour le compte utilisateur et le compte ROOT). Vous pouvez ensuite redemarrer le systeme pour aue tous les changements soient pris en compte."
