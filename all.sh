rm -f pdfs/*.pdf
root -b -q -l run.C
gs -dBATCH -dNOPAUSE -q -sDEVICE=pdfwrite -sOutputFile=mergedss.pdf pdfs/*.pdf
# cp mergedss.pdf ~/public_html/dump/
scp mergedss.pdf squark.physics.ucsb.edu:~/Desktop/
