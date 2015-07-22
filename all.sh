rm -f pdfs/*.pdf
# rm -f pdfs/*.pdf
root -b -q -l run.C
gs -dBATCH -dNOPAUSE -q -sDEVICE=pdfwrite -sOutputFile=mergedss.pdf pdfs/*.pdf
# gs -dBATCH -dNOPAUSE -q -sDEVICE=pdfwrite -sOutputFile=mergedss.pdf pdfs_hhbt0nj2met30/*.pdf
cp mergedss.pdf ~/public_html/dump/mergedSS.pdf
scp mergedss.pdf squark.physics.ucsb.edu:~/Desktop/
scp -rp pdfs/* squark.physics.ucsb.edu:~/Desktop/pdfs/
