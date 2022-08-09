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

