
SHELL	=bash
ECHO	=/bin/echo
.PHONY: install uninstall

install:
	@cd ~;\
	mv .bashrc bashrc.bak;
	@printf '$PATH=$(PATH):$(pwd))' >> $(pwd).bashrc
	@mv $(pwd).bashrc ~/.bashrc;
	@source ~/.bashrc;

uninstall:

	@mv ~/.bashrc  $(pwd).bashrc;
	@cd ~;\
	 mv bashrc.bak .bashrc;

