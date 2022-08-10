#!/bin/bash
cd ~
sudo groupadd user42
sudo usermod -aG user42 jdetre
echo "Installation de Git ----->"
sudo apt install git -y
echo "Installation de Git termine."
echo "Installation des composant essentiel ----->"
sudo apt install -y build-essential python3.9 python3.9-dev libncurses-dev curl
echo "Installation des composant essentiel termine."
echo "Installation de vim 8.2 avec python ----->"
git clone https://github.com/vim/vim.git
curl -L https://raw.githubusercontent.com/julien254/42Angouleme/main/ConfigLinux/vimCompilMakefile/Makefile > ~/vim/src/Makefile
cd ~/vim/src/
make
sudo make install
cd ../.. && rm -rf ~/vim/
echo "Installation de vim 8.2 avec python termine."
echo "Installation de ZSH"
sudo apt install zsh -y
echo "Acces ROOT requis pour configurer ZSH par defaut"
chsh -s /bin/zsh
echo "Installation de ZSH termine."
echo "Installation de Oh-My-Zsh ----->"
curl -L https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh | sh
echo "Installation de Oh-My-Zsh termine."
echo "Configuration Zsh et vim en cours..."
git clone https://github.com/julien254/42Angouleme.git
cd 42Angouleme/ConfigLinux/
cp -r .vim/ ~/
cp .vimrc ~/
cp .bashrc ~/
cp .zshrc ~/
cd ~ && rm -rf 42Angouleme/
echo "Configuration Zsh et vim termine"
echo "rebooter le systeme, puis lancer vim et taper ':PlugInstall' pour finaliser l'installation de vim."
