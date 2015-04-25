MAIN = Documentation
NAME = RCCPP

full: $(MAIN.tex)
	latex $(MAIN).tex
	latex $(MAIN).tex
	# bibtex $(MAIN)
#-------Beginn: Dazu falls Abkuerzungs- und Symbolverzeichnis bzw Glossar
#	latex $(MAIN).tex
#	makeglossaries $(MAIN)
#	latex $(MAIN).tex
#	bibtex $(MAIN)
#	makeglossaries $(MAIN)
#-------Ende: Dazu falls Abkuerzungs- und Symbolverzeichnis bzw Glossar
	latex $(MAIN).tex
	latex $(MAIN).tex
	dvips $(MAIN).dvi
	ps2pdf $(MAIN).ps $(NAME).pdf
#-------Beginn: Update Metadaten (Wegen \hypersetup{...} in $(MAIN).tex nicht notwendig)
#	ps2pdf $(MAIN).ps Paper1.pdf
#	pdftk Paper1.pdf dump_data output report.txt
#	sed -i.bak "\$$aInfoKey: Title" report.txt
#	sed -i.bak "\$$aInfoValue: Reservoir Theory and its Application on Peripheral Arteries" report.txt
#	sed -i.bak "\$$aInfoKey: Author" report.txt
#	sed -i.bak "\$$aInfoValue: Michael Ebner" report.txt
#	sed -i.bak "\$$aInfoKey: Subject" report.txt
#	sed -i.bak "\$$aInfoValue: Diploma Thesis" report.txt
#	sed -i.bak "\$$aInfoKey: Keywords" report.txt
#	sed -i.bak "\$$aInfoValue: Reservoir Theory, Windkessel Model, Peripheral Arteries" report.txt
#	pdftk Paper1.pdf update_info report.txt output Michael\ Ebner_Diploma\ Thesis.pdf
#	rm report.txt*
#	rm Paper1.pdf
#-------Ende: Update Metadaten
	open $(NAME).pdf 	

clean:
	rm -f *.o *.c~ \#*	
	rm -rf *~  *.bak *.lof
	rm -rf *.dvi *.ps
	rm -rf *.aux *.log *.nav *.out *.snm *.toc *.bbl *.blg
	rm -rf *.acn *.acr *.alg *.glg *.glo *.glo *.gls *.ist *.slg *.syg *.syi
	rm -rf *.backup
