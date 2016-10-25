import os
import subprocess

try:

	print("Processing these files:")

	for root, dirs, files in os.walk("figures"):
		for file in files:
			if file.endswith(".png"):
				fullPath = os.path.join(root, file)
				print(fullPath)
				subprocess.check_call("ebb {fileName}".format(fileName=fullPath), shell=True)

except subprocess.CalledProcessError as ex:
	print(ex.output)
