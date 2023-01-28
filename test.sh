#!/bin/bash

for ((i=0; i < 100; i++)); do
	RAND_NUM=`./push_swap_tester/random_numbers 500 1 1000`
	CMD=`./push_swap $RAND_NUM | wc -l`
	if [ $CMD -gt 5500 ]
	then
		echo -en "\033[49;31m$CMD\033[0m"
    else
		echo -en "\033[49;32m$CMD\033[0m"
	fi
	echo -n "	"
	./push_swap $RAND_NUM | ./checker_Mac $RAND_NUM
done