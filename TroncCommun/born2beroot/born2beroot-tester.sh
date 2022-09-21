#!/bin/sh
echo Quel est votre nom user ?
read USER

PARTITION=$(if [ $(lsblk | grep lvm | wc -l) -gt 2 ]; then echo "OK"; else echo "\033[0;1;5;41;37mFailed...";fi)

PARTITIONBONUS=$(if [ $(lsblk | grep lvm | wc -l) -eq 7 ]; then echo OK; else echo "\033[0;1;5;41;37mFailed...";fi)

HOSTNAME=$(if [ $(hostname) = $(echo $USER"42") ]; then echo OK; else echo "\033[0;1;5;41;37mFailed...";fi)

GROUPUSER42=$(if [ $(getent group user42 | cut -d ':' -f 4) = $USER ]; then echo OK; else echo "\033[0;1;5;41;37mFailed...";fi)

GROUPSUDO=$(if [ $(getent group sudo | cut -d ':' -f 4) = $USER ]; then echo OK; else echo "\033[0;1;5;41;37mFailed...";fi)

REGLEEXPIR1=$(if [ $(cat /etc/login.defs | grep PASS_MAX_DAYS | grep 30 | awk '{print $2}') -eq 30 ]; then echo OK ; else echo "\033[0;1;5;41;37mFailed...";fi)

REGLEEXPIR2=$(if [ $(cat /etc/login.defs | grep PASS_MIN_DAYS | grep 2 | awk '{print $2}') -eq 2 ]; then echo OK ; else echo "\033[0;1;5;41;37mFailed...";fi)

REGLEEXPIR3=$(if [ $(cat /etc/login.defs | grep PASS_WARN_AGE | grep 7 | awk '{print $2}') -eq 7 ]; then echo OK ; else echo "\033[0;1;5;41;37mFailed...";fi)

REGLEEXPIR=$(if [ $(echo $REGLEEXPIR1$REGLEEXPIR2$REGLEEXPIR3) = "OKOKOK" ]; then echo OK; else echo "\033[0;1;5;41;37mFailed..."; fi)

ROOTEXPIR1=$(if [ $(sudo chage root -l | grep Minimum | awk '{print $9}') -eq 2 ]; then echo OK ; else echo "\033[0;1;5;41;37mFailed...";fi)

ROOTEXPIR2=$(if [ $(sudo chage root -l | grep Maximum | awk '{print $9}') -eq 30 ]; then echo OK ; else echo "\033[0;1;5;41;37mFailed...";fi)

ROOTEXPIR3=$(if [ $(sudo chage root -l | grep warning | awk '{print $10}') -eq 7 ]; then echo OK ; else echo "\033[0;1;5;41;37mFailed...";fi)

ROOTEXPIR=$(if [ $(echo $ROOTEXPIR1$ROOTEXPIR2$ROOTEXPIR3) = "OKOKOK" ]; then echo OK; else echo "\033[0;1;5;41;37mFailed..."; fi)

USEREXPIR1=$(if [ $(sudo chage jdetre -l | grep Minimum | awk '{print $9}') -eq 2 ]; then echo OK ; else echo "\033[0;1;5;41;37mFailed...";fi)

USEREXPIR2=$(if [ $(sudo chage jdetre -l | grep Maximum | awk '{print $9}') -eq 30 ]; then echo OK ; else echo "\033[0;1;5;41;37mFailed...";fi)

USEREXPIR3=$(if [ $(sudo chage jdetre -l | grep warning | awk '{print $10}') -eq 7 ]; then echo OK ; else echo "\033[0;1;5;41;37mFailed...";fi)

USEREXPIR=$(if [ $(echo $USEREXPIR1$USEREXPIR2$USEREXPIR3) = "OKOKOK" ]; then echo OK; else echo "\033[0;1;5;41;37mFailed..."; fi)

PWQUALITY=$(if [ $(cat /etc/pam.d/common-password | grep retry=3 | wc -l > stock.txt && echo "+" >> stock.txt && cat /etc/pam.d/common-password | grep minlen=10 | wc -l >> stock.txt && echo "+" >> stock.txt && cat /etc/pam.d/common-password | grep ucredit=-1 | wc -l >> stock.txt && echo "+" >> stock.txt && cat /etc/pam.d/common-password | grep dcredit=-1 | wc -l >> stock.txt && echo "+" >> stock.txt && cat /etc/pam.d/common-password | grep maxrepeat=3 | wc -l >> stock.txt && echo "+" >> stock.txt && cat /etc/pam.d/common-password | grep usercheck=1 | wc -l >> stock.txt && echo "+" >> stock.txt && cat /etc/pam.d/common-password | grep difok=7 | wc -l >> stock.txt && echo "+" >> stock.txt && cat /etc/pam.d/common-password | grep enforce_for_root | wc -l >> stock.txt && cat stock.txt | xargs | bc && rm stock.txt) -eq 8 ]; then echo OK; else echo "\033[0;1;5;41;37mFailed...";fi)

SUDOERS=$(if [ $(sudo cat /etc/sudoers | grep passwd_tries=3 > stock.txt && sudo cat /etc/sudoers | grep 'logfile="/var/log/sudo/sudo.log"' >> stock.txt && sudo  cat /etc/sudoers | grep 'badpass_message=' >> stock.txt && sudo cat /etc/sudoers | grep requiretty >> stock.txt && sudo cat /etc/sudoers | grep /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin >> stock.txt && sudo cat /etc/sudoers | grep log_input >> stock.txt && sudo cat /etc/sudoers | grep log_output >> stock.txt &&sudo cat stock.txt | wc -l && rm stock.txt) -eq 7 ]; then echo OK; else echo "\033[0;1;5;41;37mFailed...";fi)

SSH4242=$(if [ $(cat /etc/ssh/sshd_config | grep 4242 | wc -l) -eq 1 ]; then echo OK ; else echo "\033[0;1;5;41;37mFailed..." ; fi)

SSHACTIVE=$(if [ $(sudo systemctl status ssh | grep Active | awk '{print $2}') = "active" ]; then echo OK; else echo "\033[0;1;5;41;37mFailed...";fi)

UFW4242=$(if [ $(sudo ufw status | grep 4242 | wc -l) -eq 2 ]; then echo OK; else echo "\033[0;1;5;41;37mFailed..."; fi)

UFWACTIVE=$(if [ $(sudo systemctl status ufw | grep Active | awk '{print $2}') = "active" ]; then echo OK; else echo "\033[0;1;5;41;37mFailed...";fi)

APPARMOR=$(if [ $(sudo aa-status | grep 'apparmor module is loaded' | wc -l) -eq 1 ]; then echo OK; else echo "\033[0;1;5;41;37mFailed...";fi)

clear
echo "\n\n\033[1;40;37mWelcome to the Bonr2beroot's tester by jdetre42Angouleme" ; sleep 3
echo -n "\n\033[0;34;1mDemarrage du test"; sleep 1; echo -n "." ; sleep 1; echo -n "."; sleep 1; echo "."
echo -n "\n\033[0;34;1mVerification des partitions:"; sleep 1; if [ $PARTITION = "OK" ]; then echo "				\033[1;42;37m OK "; else echo "				\033[0;1;5;41;37m Failed... "; fi; sleep 1;
echo -n "\033[0;34;1mVerification des partitions bonus:"; sleep 1; if [ $PARTITIONBONUS = "OK" ]; then echo "			\033[1;42;37m OK "; else echo "			\033[0;1;5;41;37m Failed... "; fi; sleep 1;
echo -n "\033[0;34;1mVerification du Hostname:"; sleep 1; if [ $HOSTNAME = "OK" ]; then echo "				\033[1;42;37m OK "; else echo "				\033[0;1;5;41;37m Failed... "; fi; sleep 1;
echo -n "\033[0;34;1mVerification du groupe user42:"; sleep 1; if [ $GROUPUSER42 = "OK" ]; then echo "				\033[1;42;37m OK "; else echo "				\033[0;1;5;41;37m Failed... "; fi; sleep 1;
echo -n "\033[0;34;1mVerification du groupe sudo:"; sleep 1; if [ $GROUPSUDO = "OK" ]; then echo "				\033[1;42;37m OK "; else echo "				\033[0;1;5;41;37m Failed... "; fi; sleep 1;
echo -n "\033[0;34;1mVerification de la politique de mdp general:"; sleep 1; if [ $REGLEEXPIR = "OK" ]; then echo "		\033[1;42;37m OK "; else echo "		\033[0;1;5;41;37m Failed... "; fi; sleep 1;
echo -n "\033[0;34;1mVerification de la politique de mdp ROOT:"; sleep 1; if [ $ROOTEXPIR = "OK" ]; then echo "		\033[1;42;37m OK "; else echo "		\033[0;1;5;41;37m Failed... "; fi; sleep 1;
echo -n "\033[0;34;1mVerification de la politique de mdp USER:"; sleep 1; if [ $USEREXPIR = "OK" ]; then echo "		\033[1;42;37m OK "; else echo "		\033[0;1;5;41;37m Failed... "; fi; sleep 1;
echo -n "\033[0;34;1mVerification de la configuration de pw-quality:"; sleep 1;  if [ $PWQUALITY = "OK" ]; then echo "		\033[1;42;37m OK "; else echo "		\033[0;1;5;41;37m Failed... "; fi; sleep 1;
echo -n "\033[0;34;1mVerification du fichier sudoers:"; sleep 1; if [ $SUDOERS = "OK" ]; then echo "			\033[1;42;37m OK "; else echo "			\033[0;1;5;41;37m Failed... "; fi; sleep 1;
echo -n "\033[0;34;1mVerification de l'activation de SSH"; sleep 1; if [ $SSHACTIVE = "OK" ]; then echo "			\033[1;42;37m OK "; else echo "			\033[0;1;5;41;37m Failed... "; fi; sleep 1;
echo -n "\033[0;34;1mVerification du port utilse par SSH:"; sleep 1; if [ $SSH4242 = "OK" ]; then echo "			\033[1;42;37m OK "; else echo "			\033[0;1;5;41;37m Failed... "; fi; sleep 1;
echo -n "\033[0;34;1mVerification de l'activation de UFW:"; sleep 1; if [ $UFWACTIVE = "OK" ]; then echo "			\033[1;42;37m OK "; else echo "			\033[0;1;5;41;37m Failed... "; fi; sleep 1;
echo -n "\033[0;34;1mVerification des ports autorises:"; sleep 1; if [ $UFW4242 = "OK" ]; then echo "			\033[1;42;37m OK "; else echo "			\033[0;1;5;41;37m Failed... "; fi; sleep 1;
echo -n "\033[0;34;1mVerification de l'activation d'APPARMOR:"; sleep 1; if [ $APPARMOR = "OK" ]; then echo "		\033[1;42;37m OK "; else echo "			\033[0;1;5;41;37m Failed... "; fi; sleep 1;
if [ $(echo $PARTITION$HOSTNAME$GROUPUSER42$GROUPSUDO$REGLEEXPIR$ROOTEXPIR$USEREXPIR$PWQUALITY$SUDOERS) = "OKOKOKOKOKOKOKOKOK" ]; then echo "\n\n\033[0;1;5;32mFelicitations Vous avez passez 100% du test avec succes.\n\n"; else echo "\n\n\033[0;1;31mOups, certaine choses sont a revoir ;).\n\n";fi
