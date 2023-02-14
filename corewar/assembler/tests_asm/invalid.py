#!/usr/bin/env python3

import sys
import os
import os.path
from os import path
import subprocess
from subprocess import run
import signal

EOC = "\033[0m"
GREEN = "\033[38;5;70m"
RED  = "\033[38;5;124m"
YELLOW = "\033[38;5;220m"
SALMON  = "\033[38;5;203m"
RUST = "\033[38;5;130m"
CYAN = "\033[38;5;43m"
GRAY = "\033[38;5;240m"
WHITE = "\033[38;5;231m"
ITALIC = "\033[3m"

real_asm = "./asm"
our_asm = "../../asm"
real_segs = []
our_segs = []
no_error = []

if len(sys.argv) != 2:
	print(YELLOW + "Usage:\n  " + EOC + "python3 invalid.py <path>")
	sys.exit()

def signal_handler(sig, frame):
	sys.exit()

def main():
	signal.signal(signal.SIGINT, signal_handler)
	if os.path.isdir(sys.argv[1]) == False:
		print("  Not a valid path.")
		sys.exit()
	dir_path = sys.argv[1]
	if dir_path[-1] != '/':
		dir_path += "/"
	dir_cont = os.listdir(dir_path)
	for file in dir_cont:
		if ".s" in file:
			s_file = "%s%s" % (dir_path, file)
			print(GRAY + "##################################################################################" + EOC)
			print(WHITE + s_file + "\n" + EOC)
			print(GREEN + "Real asm: " + EOC)
			output = run([real_asm, s_file ], capture_output=True)
			print(output.stdout.decode('ascii'))
			if output.returncode == -11:
				real_segs.append(s_file)
				print("SEGFAULT!")
			print(SALMON + "Tested asm: " + EOC)
			output = run([our_asm, s_file ], capture_output=True)
			print(output.stderr.decode('ascii'), end="")
			if "Writing" in str(output.stdout):
				no_error.append(s_file)
			if output.returncode == -11:
				our_segs.append(s_file)
				print("SEGFAULT!")
	print(GRAY + "##################################################################################\n\n" + EOC)
	print(YELLOW + "\n\nSUMMARY:" + EOC)
	print("Real asm segfaults: %s" % str(len(real_segs)))
	if len(real_segs) != 0:
		print(RED + '\n' .join(real_segs) + EOC)
	print("\nTested asm segfaults: %s" % str(len(our_segs)))
	if len(our_segs) != 0:
		print(RED + '\n' .join(our_segs) + EOC)
	if len(no_error) != 0:
		print(YELLOW + "\nThese files didn't cause an error:")
		print(GRAY + ITALIC + '\n' .join(no_error) + EOC)

if __name__ == "__main__":
	main()