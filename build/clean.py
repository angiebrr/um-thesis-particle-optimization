import os
import traceback

try:

	print("Cleaning these files:")

	for root, dirs, files in os.walk("."):
		for file in files:
			if file.endswith((".aux", ".bbl", ".log", ".lof", ".lot", ".out", ".toc", ".lol", ".bb")):
				fullPath = os.path.join(root, file)
				print(fullPath)
				os.remove(fullPath)

except Exception as ex:
	print(traceback.format_exc())