#!/bin/bash

for ((i=0; i < 1000; i++)); do
	RAND_NUM=`./push_swap_tester/random_numbers 5 1 1000`
	CMD=`./push_swap $RAND_NUM | wc -l`
	if [ $CMD -gt 12 ]
	then
		echo -en "\033[49;31m$CMD\033[0m"
    else
		echo -en "\033[49;32m$CMD\033[0m"
	fi
	echo -n "	"
	./push_swap $RAND_NUM | ./checker_Mac $RAND_NUM
done