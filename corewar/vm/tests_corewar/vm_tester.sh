#!/bin/bash

RED=$(tput setaf 160)
GREEN=$(tput setaf 77)
YELLOW=$(tput setaf 220)
BLACK=$(tput setaf 235)
EOC=$(tput sgr0)

ORIG_VM="./test_vm/corewar_orig"
OUR_VM="../../corewar"

ARGS="$*"

mkdir -p temp_files/
ORIG_OUTPUT="temp_files/output_orig.txt"
OUR_OUTPUT="temp_files/output_our.txt"

$ORIG_VM $ARGS > $ORIG_OUTPUT 2>&1
$OUR_VM $ARGS > $OUR_OUTPUT 2>&1

ERROR=( `grep  "Error" temp_files/output_our.txt | cut -f1 -d ":"` )
USAGE=( `grep "Usage" temp_files/output_our.txt | cut -f1 -d ":"` )

if [ "$ERROR" == "Error" ]
then
	printf "${RED}Error occured${EOC}\n"
	while [[ "$ANSWER" != "n" && "$ANSWER" != "y" ]]
	do
		printf "Diff files anyway? (y/n)\n"
		read ANSWER
		if [ "$ANSWER" == "y" ]
		then
			ANSWER=""
			break
		elif [ "$ANSWER" == "n" ]
		then
			rm -rf $ORIG_OUTPUT
			rm -rf $OUR_OUTPUT
			printf "Exiting...\n"
			exit
		fi
	done
elif [ "$USAGE" == "Usage" ]
then
	printf "Printed usage, exiting...\n"
	rm -rf $ORIG_OUTPUT
	rm -rf $OUR_OUTPUT
	exit
else
	printf "${YELLOW}Running both VMs, this might take a while...${EOC}\n"
fi

DIFF_FILE="temp_files/diff.txt"
diff $ORIG_OUTPUT $OUR_OUTPUT > $DIFF_FILE

if [ -s $DIFF_FILE ]
then
	printf "Diff ${RED}KO${EOC}\n"
	printf "Saved files to ${YELLOW}$ORIG_OUTPUT${EOC} and ${YELLOW}$OUR_OUTPUT${EOC}\n"
else
	printf "Diff ${GREEN}OK${EOC}\n"
	rm -rf $ORIG_OUTPUT
	rm -rf $OUR_OUTPUT
	rm -rf $DIFF_FILE
fi
exit