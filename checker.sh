#!/bin/bash
# ----------------------------------------------------------- #
#	Copyright (c) - 2024 Curs PA                              #
#	Authors 2020 : Rusu Gabriel & Tudose Ionut                #
#	Authors 2024 : Crantea Antonio Cristian                   #
#				   Dobre Andreea-Viktorya                     #
#				   Nițu Marius-Augustin                       #
# ----------------------------------------------------------- #
# ----------------------------------------------------------- #
# Permission to use, copy, modify, and / or distribute this   #
# software for any purpose with or without fee is hereby      #
# granted, provided that the above copyright notice and this  #
# permission notice appear in all copies.                     #
# ----------------------------------------------------------- #

EXEC_NAME=clasament

# Teste Normale.
FILE_TEST_DATE="Input/test%d.in"
FILE_TEST_OUT_1="OutputGraf/test%d.out"
FILE_TEST_OUT_2="OutputScor/test%d.out"
FILE_TEST_REF_1="RezultateGraf/test%d.out"
FILE_TEST_REF_2="RezultateScor/test%d.out"

NUM_TESTS=10

# Total Score.
SCORE_TESTS=0

# Delimiter.
DELIM="--------------------------------------------------"
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

points=0
test_point=5

function run_test {
	points=0
	status=""
	color=$RED

	./$EXEC_NAME $2 $3 $4 2>&1 | cat

	diff -Z -q $3 $5 >> /dev/null 2>&1
	if [ $? -eq 0 ];
	then
		points=$test_point
		SCORE_TESTS=$(($SCORE_TESTS+$test_point))
		status="PASSED"
		color=$GREEN
	else
		msg="FAILED"
		color=$RED
	fi
	
	printf "Test Graf %2d .............................. ${color}%6s${NC} (+%dp)\n" $1 $status $points

	diff -Z -q $4 $6 >> /dev/null 2>&1
	if [ $? -eq 0 ];
	then
		points=$test_point
		SCORE_TESTS=$(($SCORE_TESTS+$test_point))
		status="PASSED"
		color=$GREEN
	else
		status="FAILED"
		color=$RED
	fi
	
	printf "Test Scor %2d .............................. ${color}%6s${NC} (+%dp)\n" $1 $status $points
}

function run_tests {
	for i in `seq 1 1 $1`
	do
		printf -v file_date $2 $i
		printf -v file_out_1 $3 $i
		printf -v file_out_2 $4 $i
		printf -v file_ref_1 $5 $i
		printf -v file_ref_2 $6 $i
		run_test $i $file_date $file_out_1 $file_out_2 $file_ref_1 $file_ref_2 $7

	done
}

function run_normal_tests {
	echo $DELIM
	echo "[TESTE NORMALE]"
	run_tests $NUM_TESTS $FILE_TEST_DATE $FILE_TEST_OUT_1 $FILE_TEST_OUT_2 $FILE_TEST_REF_1 $FILE_TEST_REF_2 "$POINTS_TEST"

	echo
	printf "TOTAL ........................................... %3spt\n" $SCORE_TESTS 
	echo
}

function show_total {
	echo $DELIM

	echo
	printf "NOTA FINALA ..................................... %3spt\n" $(($SCORE_TESTS))
	echo	
}

# Prepare the output directories.
rm -rf OutputGraf
rm -rf OutputScor
mkdir OutputGraf
mkdir OutputScor

# Build the source.
make

# Run normal tests.
echo $DELIM
echo "Executabil = '$EXEC_NAME'"

run_normal_tests
show_total

make clean