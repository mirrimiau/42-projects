#!/usr/bin/env python3

import sys
import os

from os import path

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
no_diff = []
err_files = []

if len(sys.argv) != 2:
	print(YELLOW + "Usage:\n  " + EOC + "python3 valid.py <path>")
	sys.exit()

def	main():
	if os.path.isdir(sys.argv[1]) == False:
		print("  Not a valid path.")
		sys.exit()
	dir_path = sys.argv[1]
	if dir_path[-1] != '/':
		dir_path += "/"
	dir_cont = os.listdir(dir_path)
	print("Creating .cor files using project asm...")
	print("----------------------------------------")
	for file in dir_cont:
		if ".s" in file:
			s_file = "%s%s" % (dir_path, file)
			os.system("%s %s" % (real_asm, s_file))
			cor_file = s_file.replace(".s", ".cor")
			cmd = "hexdump %s > %s" % (cor_file, file.replace(".s", "_org.hex"))
			os.system(cmd)
			os.system("rm %s" % (cor_file))
	err_nbr = 1
	err_count = 0
	print("\nCreating .cor files using your asm...")
	print("--------------------------------------")
	for file in dir_cont:
		if ".s" in file:
			s_file = "%s%s" % (dir_path, file)
			os.system("%s %s" % (our_asm, s_file))
			cor_file = s_file.replace(".s", ".cor")
			if not path.exists(cor_file):
				no_diff.append(err_nbr)
				err_files.append(file)
				err_count += 1
			cmd = "hexdump %s > %s" % (cor_file, file.replace(".s", ".hex"))
			os.system(cmd)
			os.system("rm %s" % (cor_file))
			err_nbr += 1
	for file in dir_cont:
		if ".s" in file:
			cmd = "diff %s %s > %s" % (file.replace(".s", "_org.hex"), file.replace(".s", ".hex"), file.replace(".s", ".diff"))
			os.system(cmd)

	dir_cont.clear()
	dir_cont = os.listdir()
	count = 1
	i = 0
	for file in dir_cont:
		if ".diff" in file:
			try:
				fd = open(file, "r")
				hex_file = file.replace(".diff", ".hex")
				fd2 = open(hex_file, "r")
				if os.stat(hex_file).st_size == 0:
					print(str(count).rjust(3, ' '), end=" ")
					print(YELLOW + "Something went wrong with " + EOC, end="")
					print(file.replace(".diff", ".s"))
				elif os.stat(file).st_size == 0:
					print(str(count).rjust(3, ' '), end=" ")
					print(GREEN + "OK" + EOC)
					os.system("rm %s %s %s" % (file.replace(".diff", "_org.hex"), file.replace(".diff", ".hex"), file))
				else:
					print(str(count).rjust(3, ' '), end=" ")
					print(RED + "KO" + EOC)
					err_count += 1
				count += 1
			except OSError:
				print("Invalid file")
				sys.exit()
			fd.close()
			fd2.close()

	count -= 1
	correct = count - err_count
	print(SALMON +"________________________________________________________________________________________________")
	print(CYAN + "      ___           ___           ___           ___           ___           ___           ___   ")
	print("     /  /\         /  /\         /  /\         /  /\         /__/\         /  /\         /  /\ ")
	print("    /  /:/        /  /::\       /  /::\       /  /:/_       _\_ \:\       /  /::\       /  /::\   ")
	print("   /  /:/        /  /:/\:\     /  /:/\:\     /  /:/ /\     /__/\ \:\     /  /:/\:\     /  /:/\:\ ")
	print("  /  /:/  ___   /  /:/  \:\   /  /:/-/:/    /  /:/ /:/_   _\_ \:\ \:\   /  /:/-/::\   /  /:/-/:/  ")
	print(" /__/:/  /  /\ /__/:/ \__\:\ /__/:/ /:/___ /__/:/ /:/ /\ /__/\ \:\ \:\ /__/:/ /:/\:\ /__/:/ /:/___")
	print(" \  \:\ /  /:/ \  \:\ /  /:/ \  \:\/:::::/ \  \:\/:/ /:/ \  \:\ \:\/:/ \  \:\/:/__\/ \  \:\/:::::/")
	print("  \  \:\  /:/   \  \:\  /:/   \  \::/----   \  \::/ /:/   \  \:\ \::/   \  \::/       \  \::/---- ")
	print("   \  \:\/:/     \  \:\/:/     \  \:\        \  \:\/:/     \  \:\/:/     \  \:\        \  \:\     ")
	print("    \  \::/       \  \::/       \  \:\        \  \::/       \  \::/       \  \:\        \  \:\ ")
	print("     \__\/         \__\/         \__\/         \__\/         \__\/         \__\/         \__\/   ")
	print(SALMON +"_________________________________________________________________________________________________" + EOC)
	print(WHITE + "                                                                           by altikka & atenhune" + EOC)
	print(YELLOW + "Result:" + EOC)
	print(str(correct) + "/" + str(count))
	if correct == count:
		print(GREEN + "SUCCESS" + EOC)
	else:
		print(RED + "FAILURE" + EOC)
		ans = input("Do you want to remove logged files?\n" + GRAY + ITALIC)
		if ans == "yes" or ans == "y":
			os.system("rm *.diff *.hex")
		print(EOC, end="")
if __name__ == "__main__":
	main()
