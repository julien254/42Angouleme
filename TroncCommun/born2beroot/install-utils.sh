#!/bin/bash
cd ~
echo "Installation de Git ----->"
sudo apt install git -y
echo "Installation de Git termine."
echo "Installation des composant essentiel ----->"
sudo apt install build-essential python3.9
echo "Installation des composant essentiel termine."
echo "Installation de vim 8.2 avec python ----->"
git clone https://github.com/vim/vim.git
curl -L https://raw.githubusercontent.com/julien254/42Angouleme/main/ConfigLinux/vimCompilMakefile/Makefile > ~/vim/src/Makefile
cd ~/vim/src/
make
sudo make install
echo "Installation de vim 8.2 avec python termine."
echo "Installation de ZSH"
sudo apt install zsh -y
echo "Installation de ZSH termine."
echo "Installation de Oh-My-Zsh ----->"
sudo apt install curl -y
curl -L https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh | sh
echo "Installation de Oh-My-Zsh termine."
echo "Configuration Zsh et vim en cours..."
git clone https://github.com/julien254/42Angouleme.git
cd 42Angouleme/ConfigLinux/
cp -r .vim/ ~/
cp .vimrc ~/
cp .bashrc ~/
cp .zshrc ~/
cd ~
chsh -s /bin/zsh
