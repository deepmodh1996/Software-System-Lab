ROOT=./

.PHONY: plot ProjectProposal GayatriMantra clean

plot:
	@octave gradient_descent.m
	@gnuplot plot.gnu

ProjectProposal:
	@pdflatex ProjectProposal.tex
	@bibtex ProjectProposal.aux
	@pdflatex ProjectProposal.tex
	@pdflatex ProjectProposal.tex

GayatriMantra: 
	@devnag GayatriMantra
	@pdflatex GayatriMantra.tex


clean:
	@$(RM) -rf $(ROOT)/GayatriMantra.aux
	@$(RM) -rf $(ROOT)/GayatriMantra.pdf
	@$(RM) -rf $(ROOT)/GayatriMantra.tex
	@$(RM) -rf $(ROOT)/texput.log
	@$(RM) -rf $(ROOT)/GayatriMantra.log
	@$(RM) -rf $(ROOT)/ProjectProposal.log
	@$(RM) -rf $(ROOT)/ProjectProposal.blg
	@$(RM) -rf $(ROOT)/ProjectProposal.bbl
	@$(RM) -rf $(ROOT)/ProjectProposal.aux
	@$(RM) -rf $(ROOT)/ProjectProposal.pdf
	@$(RM) -rf $(ROOT)/ProjectProposal.out

