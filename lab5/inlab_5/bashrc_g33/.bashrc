# .bashrc
#inlab 5
# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# User specific aliases and functions
echo "Hello (inlab message) "
export PS1="[\d \T][\W] -> \[$(tput sgr0)\]"

alias cd..="cd ../../"
alias cd....="cd ../../../"

