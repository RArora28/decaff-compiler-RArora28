import os
import sys

file = sys.argv[1]
IR = "IR"

l = len(sys.argv)
if l <= 2:
	os.system("make clean")
	os.system("make")

os.system("./a.out" + " < " + file + " > " + IR)
os.system("lli " + IR)