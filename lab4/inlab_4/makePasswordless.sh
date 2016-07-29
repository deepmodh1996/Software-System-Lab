#! /bin/bash

if [ $# -ne 2 ]
then
  printf"give tw0 arguments";
  exit;
fi


ssh-keygen -t dsa -P '' -f ~/.ssh/id_dsa

scp ~/.ssh/id_dsa.pub $1@$2:~/.ssh/id_dsa.pub

 ssh $1@$2

 cat ~/.ssh/id_dsa.pub >> ~/.ssh/authorized_keys

exit
