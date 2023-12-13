#!/bin/bash
echo "Installation de ZSH"
sudo apt-get install zsh -y
sudo chsh -s /bin/zsh
chsh -s /bin/zsh
echo "Installation de ZSH termine."
echo "Installation de Oh-My-Zsh ----->"
curl -L https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh | sh
sleep 10
echo "Installation de Oh-My-Zsh termine."
cd ~
sudo groupadd user42
sudo usermod -aG user42 judetre
echo "Installation des composant essentiel ----->"
sudo apt-get install -y build-essential python3.11 python3.11-dev libncurses-dev curl
echo "Installation des composant essentiel termine."
echo "Installation de vim 8.2 avec python ----->"
cd ~/42Angouleme/troncCommun2/born2beroot/vim/src/
make
sudo make install
cd ~
echo "Installation de vim 8.2 avec python termine."
echo "Configuration Zsh et vim en cours..."
cd 42Angouleme/ConfigLinux/
sudo cp -r .vim/ /root/
cp -r .vim/ ~/
sudo cp .vimrc /root/
cp .vimrc ~/
cp .zshrc ~/
sudo cp .zshrc /root/
sudo cp -r ~/.oh-my-zsh /root/
echo "Configuration Zsh et vim termine"
echo "lancer vim et taper ':PlugInstall' pour finaliser l'installation des plugins. (Pour le compte utilisateur et le compte ROOT). Vous pouvez ensuite redemarrer le systeme pour que tous les changements soient pris en compte."
