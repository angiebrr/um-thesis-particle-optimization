import subprocess
import os
import sys

try:
	# Ensure that we're in the main directory before continuing
	os.chdir(os.path.dirname(sys.argv[0]))
	os.chdir("..")

	print("======================================================")
	print("FIGURE BOUNDING BOXES")
	print("======================================================")
	subprocess.check_call("python build/makeFigureBoundingBox.py", shell=True)

	print("======================================================")
	print("BUILDING THESIS TEX AND BIBTEX")
	print("======================================================")
	subprocess.check_call("pdflatex -quiet Thesis.tex", shell=True)
	subprocess.check_call("bibtex -quiet Thesis", shell=True)
	subprocess.check_call("pdflatex -quiet Thesis.tex", shell=True)
	subprocess.check_call("bibtex -quiet Thesis", shell=True)
	subprocess.check_call("pdflatex -quiet Thesis.tex", shell=True)

	print("======================================================")
	print("BUILDING THESIS PDF FROM DVI")
	print("======================================================")
	subprocess.check_call("dvipdfm Thesis.dvi", shell=True)

	print("======================================================")
	print("CLEANING UP")
	print("======================================================")
	subprocess.check_call("python build/clean.py", shell=True)

except subprocess.CalledProcessError as ex:
	print(ex.output)
