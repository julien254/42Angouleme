#!/bin/sh
echo Quel est votre nom user ?
read USER

function opt_sleep() {
	sleep $1
}

PARTITION=$(if [ $(lsblk | grep lvm | wc -l) -gt 2 ]; then echo -e "OK"; else echo -e "KO";fi)

PARTITIONBONUS=$(if [ $(lsblk | grep lvm | wc -l) -eq 7 ]; then echo -e OK; else echo -e "KO";fi)

HOSTNAME=$(if [ $(hostname) = $(echo -e $USER"42") ]; then echo -e OK; else echo -e "KO";fi)

GROUPUSER42=$(if [ $(getent group user42 | cut -d ':' -f 4) = $USER ]; then echo -e OK; else echo -e "KO";fi)

GROUPSUDO=$(if [ $(getent group sudo | cut -d ':' -f 4) = $USER ]; then echo -e OK; else echo -e "KO";fi)

REGLEEXPIR1=$(if [ $(cat /etc/login.defs | grep PASS_MAX_DAYS | grep 30 | awk '{print $2}') -eq 30 ]; then echo -e OK ; else echo -e "KO";fi)

REGLEEXPIR2=$(if [ $(cat /etc/login.defs | grep PASS_MIN_DAYS | grep 2 | awk '{print $2}') -eq 2 ]; then echo -e OK ; else echo -e "KO";fi)

REGLEEXPIR3=$(if [ $(cat /etc/login.defs | grep PASS_WARN_AGE | grep 7 | awk '{print $2}') -eq 7 ]; then echo -e OK ; else echo -e "KO";fi)

REGLEEXPIR=$(if [ $(echo -e $REGLEEXPIR1$REGLEEXPIR2$REGLEEXPIR3) = "OKOKOK" ]; then echo -e OK; else echo -e "KO"; fi)

ROOTEXPIR1=$(if [ $(sudo chage root -l | grep Minimum | awk '{print $9}') -eq 2 ]; then echo -e OK ; else echo -e "KO";fi)

ROOTEXPIR2=$(if [ $(sudo chage root -l | grep Maximum | awk '{print $9}') -eq 30 ]; then echo -e OK ; else echo -e "KO";fi)

ROOTEXPIR3=$(if [ $(sudo chage root -l | grep warning | awk '{print $10}') -eq 7 ]; then echo -e OK ; else echo -e "KO";fi)

ROOTEXPIR=$(if [ $(echo -e $ROOTEXPIR1$ROOTEXPIR2$ROOTEXPIR3) = "OKOKOK" ]; then echo -e OK; else echo -e "KO"; fi)

USEREXPIR1=$(if [ $(sudo chage $USER -l | grep Minimum | awk '{print $9}') -eq 2 ]; then echo -e OK ; else echo -e "KO";fi)

USEREXPIR2=$(if [ $(sudo chage $USER -l | grep Maximum | awk '{print $9}') -eq 30 ]; then echo -e OK ; else echo -e "KO";fi)

USEREXPIR3=$(if [ $(sudo chage $USER -l | grep warning | awk '{print $10}') -eq 7 ]; then echo -e OK ; else echo -e "KO";fi)

USEREXPIR=$(if [ $(echo -e $USEREXPIR1$USEREXPIR2$USEREXPIR3) = "OKOKOK" ]; then echo -e OK; else echo -e "KO"; fi)

PWQUALITY=$(if [ $(cat /etc/pam.d/common-password | grep retry=3 | wc -l > stock.txt && echo -e "+" >> stock.txt && cat /etc/pam.d/common-password | grep minlen=10 | wc -l >> stock.txt && echo -e "+" >> stock.txt && cat /etc/pam.d/common-password | grep ucredit=-1 | wc -l >> stock.txt && echo -e "+" >> stock.txt && cat /etc/pam.d/common-password | grep dcredit=-1 | wc -l >> stock.txt && echo -e "+" >> stock.txt && cat /etc/pam.d/common-password | grep maxrepeat=3 | wc -l >> stock.txt && echo -e "+" >> stock.txt && cat /etc/pam.d/common-password | grep usercheck=1 | wc -l >> stock.txt && echo -e "+" >> stock.txt && cat /etc/pam.d/common-password | grep difok=7 | wc -l >> stock.txt && echo -e "+" >> stock.txt && cat /etc/pam.d/common-password | grep enforce_for_root | wc -l >> stock.txt && cat stock.txt | xargs | bc && rm stock.txt) -eq 8 ]; then echo -e OK; else echo -e "KO";fi)

SUDOERS=$(if [ $(sudo cat /etc/sudoers | grep passwd_tries=3 > stock.txt && sudo cat /etc/sudoers | grep 'logfile="/var/log/sudo/sudo.log"' >> stock.txt && sudo  cat /etc/sudoers | grep 'badpass_message=' >> stock.txt && sudo cat /etc/sudoers | grep requiretty >> stock.txt && sudo cat /etc/sudoers | grep /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin >> stock.txt && sudo cat /etc/sudoers | grep log_input >> stock.txt && sudo cat /etc/sudoers | grep log_output >> stock.txt &&sudo cat stock.txt | wc -l && rm stock.txt) -eq 7 ]; then echo -e OK; else echo -e "KO";fi)

SSH4242=$(if [ $(cat /etc/ssh/sshd_config | grep 4242 | wc -l) -eq 1 ]; then echo -e OK ; else echo -e "KO" ; fi)

SSHACTIVE=$(if [ $(sudo systemctl status ssh | grep Active | awk '{print $2}') = "active" ]; then echo -e OK; else echo -e "KO";fi)

UFW4242=$(if [ $(sudo ufw status | grep 4242 | wc -l) -eq 2 ]; then echo -e OK; else echo -e "KO"; fi)

UFWACTIVE=$(if [ $(sudo systemctl status ufw | grep Active | awk '{print $2}') = "active" ]; then echo -e OK; else echo -e "KO";fi)

APPARMOR=$(if [ $(sudo aa-status | grep 'apparmor module is loaded' | wc -l) -eq 1 ]; then echo -e OK; else echo -e "KO";fi)

clear
echo -e "\n\n\033[1;40;37mWelcome to the Born2beroot's tester by jdetre42Angouleme" ; opt_sleep 3
echo -e -n "\n\033[0;34;1mDémarrage du test"; opt_sleep 1; echo -e -n "." ; opt_sleep 1; echo -e -n "."; opt_sleep 1; echo -e "."
echo -e -n "\n\033[0;34;1mVérification des partitions:"; opt_sleep 1; if [ $PARTITION = "OK" ]; then echo -e "					\033[1;42;37m OK "; else echo -e "					\033[0;1;5;41;37m Failed... "; fi; opt_sleep 1;
echo -e -n "\033[0;34;1mVérification des partitions bonus:"; opt_sleep 1; if [ $PARTITIONBONUS = "OK" ]; then echo -e "				\033[1;42;37m OK "; else echo -e "				\033[0;1;5;41;37m Failed... "; fi; opt_sleep 1;
echo -e -n "\033[0;34;1mVérification du Hostname:"; opt_sleep 1; if [ $HOSTNAME = "OK" ]; then echo -e "						\033[1;42;37m OK "; else echo -e "						\033[0;1;5;41;37m Failed... "; fi; opt_sleep 1;
echo -e -n "\033[0;34;1mVérification du groupe user42:"; opt_sleep 1; if [ $GROUPUSER42 = "OK" ]; then echo -e "					\033[1;42;37m OK "; else echo -e "					\033[0;1;5;41;37m Failed... "; fi; opt_sleep 1;
echo -e -n "\033[0;34;1mVérification du groupe sudo:"; opt_sleep 1; if [ $GROUPSUDO = "OK" ]; then echo -e "					\033[1;42;37m OK "; else echo -e "					\033[0;1;5;41;37m Failed... "; fi; opt_sleep 1;
echo -e -n "\033[0;34;1mVérification de la politique de mdp general:"; opt_sleep 1; if [ $REGLEEXPIR = "OK" ]; then echo -e "	\033[1;42;37m OK "; else echo -e "	\033[0;1;5;41;37m Failed... "; fi; opt_sleep 1;
echo -e -n "\033[0;34;1mVérification de la politique de mdp ROOT:"; opt_sleep 1; if [ $ROOTEXPIR = "OK" ]; then echo -e "		\033[1;42;37m OK "; else echo -e "		\033[0;1;5;41;37m Failed... "; fi; opt_sleep 1;
echo -e -n "\033[0;34;1mVérification de la politique de mdp USER:"; opt_sleep 1; if [ $USEREXPIR = "OK" ]; then echo -e "		\033[1;42;37m OK "; else echo -e "		\033[0;1;5;41;37m Failed... "; fi; opt_sleep 1;
echo -e -n "\033[0;34;1mVérification de la configuration de pw-quality:"; opt_sleep 1;  if [ $PWQUALITY = "OK" ]; then echo -e "	\033[1;42;37m OK "; else echo -e "	\033[0;1;5;41;37m Failed... "; fi; opt_sleep 1;
echo -e -n "\033[0;34;1mVérification du fichier sudoers:"; opt_sleep 1; if [ $SUDOERS = "OK" ]; then echo -e "				\033[1;42;37m OK "; else echo -e "				\033[0;1;5;41;37m Failed... "; fi; opt_sleep 1;
echo -e -n "\033[0;34;1mVérification de l'activation de SSH"; opt_sleep 1; if [ $SSHACTIVE = "OK" ]; then echo -e "				\033[1;42;37m OK "; else echo -e "				\033[0;1;5;41;37m Failed... "; fi; opt_sleep 1;
echo -e -n "\033[0;34;1mVérification du port utilsé par SSH:"; opt_sleep 1; if [ $SSH4242 = "OK" ]; then echo -e "			\033[1;42;37m OK "; else echo -e "			\033[0;1;5;41;37m Failed... "; fi; opt_sleep 1;
echo -e -n "\033[0;34;1mVérification de l'activation de UFW:"; opt_sleep 1; if [ $UFWACTIVE = "OK" ]; then echo -e "			\033[1;42;37m OK "; else echo -e "			\033[0;1;5;41;37m Failed... "; fi; opt_sleep 1;
echo -e -n "\033[0;34;1mVérification des ports autorisés:"; opt_sleep 1; if [ $UFW4242 = "OK" ]; then echo -e "				\033[1;42;37m OK "; else echo -e "				\033[0;1;5;41;37m Failed... "; fi; opt_sleep 1;
echo -e -n "\033[0;34;1mVérification de l'activation d'APPARMOR:"; opt_sleep 1; if [ $APPARMOR = "OK" ]; then echo -e "		\033[1;42;37m OK "; else echo -e "		\033[0;1;5;41;37m Failed... "; fi; opt_sleep 1;

if [ $(echo -e $PARTITION$HOSTNAME$GROUPUSER42$GROUPSUDO$REGLEEXPIR$ROOTEXPIR$USEREXPIR$PWQUALITY$SUDOERS) = "OKOKOKOKOKOKOKOKOK" ]; then 
	echo -e "\n\n\033[0;1;5;32mFelicitations! Vous avez passé 100% du test avec succès.\n\n"; 
else 
	echo -e "\n\n\033[0;1;31mOups, certaines choses sont à revoir ;).\n\n";
fi
echo -en "\033[0;m"
