#!/bin/bash

job=$(basename $PWD);
pdflatex -jobname $job 1.tex
rm $job.aux $job.log
