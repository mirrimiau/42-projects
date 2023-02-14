#!/bin/bash

RED=$(tput setaf 160)
GREEN=$(tput setaf 77)
YELLOW=$(tput setaf 220)
BLACK=$(tput setaf 235)
EOC=$(tput sgr0)

VM_TESTER="./vm_tester.sh"
DIFF_FILE="temp_files/diff.txt"

ARGS="$*"

if [ $# -eq 0 ]
then
	printf "No arguments, exiting...\n"
	exit
fi

for var 
do
	if [[ $var != *".cor" ]]
	then
		printf "File ${RED}$var${EOC} not supported, exiting...\n"
		exit
	fi
	if [ ! -f $var ]
	then
		printf "File ${RED}$var${EOC} not found, exiting...\n"
		exit
	fi
done

DUMP_CYCLE=0

while :
do
	if ! ((DUMP_CYCLE % 100))
	then
		printf "${YELLOW}Running both VMs in a loop, this WILL take a while${EOC}\n"
	fi
	$VM_TESTER -d $DUMP_CYCLE $ARGS > /dev/null
	if [ -s $DIFF_FILE ]
	then
		break
	fi
	((++DUMP_CYCLE))
done
printf "Diff occured at cycle ${GREEN}$DUMP_CYCLE${EOC}\n"
exit