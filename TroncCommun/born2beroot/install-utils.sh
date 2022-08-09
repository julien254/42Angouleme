#!/bin/bash
echo "Installation de Git ----->"
sudo apt install git -y
echo "Installation de Git termine"
echo "Installation de ZSH"
sudo apt install zsh -y
echo "Installation de ZSH termine"
echo "Installation de Oh-My-Zsh"
sudo apt install curl -y
curl -L https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh | sh
echo "Installation de Oh-My-Zsh termine"
echo "Configuration Zsh et vim en cours..."
cd ~
git clone https://github.com/julien254/42Angouleme.git
cd 42Angouleme/TheVim_and_Shell_conf/
cp -r .vim/ ~/
cp .vimrc ~/
cp .bashrc ~/
cp .zshrc ~/
