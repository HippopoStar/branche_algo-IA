#!/bin/sh

TMP_FILE_NAME='test_script_push_swap.tmp'

rm -f /tmp/${TMP_FILE_NAME}
touch /tmp/${TMP_FILE_NAME}

let "n = 100"
while test ${n} -gt 0 ; do
	ARG=`ruby -e "puts (1 .. 4).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker $ARG >> /tmp/${TMP_FILE_NAME} 2>&1
	ARG=`ruby -e "puts (1 .. 5).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker $ARG >> /tmp/${TMP_FILE_NAME} 2>&1
	ARG=`ruby -e "puts (1 .. 6).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker $ARG >> /tmp/${TMP_FILE_NAME} 2>&1
	ARG=`ruby -e "puts (1 .. 7).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker $ARG >> /tmp/${TMP_FILE_NAME} 2>&1
	ARG=`ruby -e "puts (1 .. 8).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker $ARG >> /tmp/${TMP_FILE_NAME} 2>&1
	ARG=`ruby -e "puts (1 .. 9).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker $ARG >> /tmp/${TMP_FILE_NAME} 2>&1
	ARG=`ruby -e "puts (1 .. 10).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker $ARG >> /tmp/${TMP_FILE_NAME} 2>&1
	ARG=`ruby -e "puts (1 .. 11).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker $ARG >> /tmp/${TMP_FILE_NAME} 2>&1
	ARG=`ruby -e "puts (1 .. 12).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker $ARG >> /tmp/${TMP_FILE_NAME} 2>&1
	ARG=`ruby -e "puts (1 .. 13).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker $ARG >> /tmp/${TMP_FILE_NAME} 2>&1
	ARG=`ruby -e "puts (1 .. 14).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker $ARG >> /tmp/${TMP_FILE_NAME} 2>&1
	ARG=`ruby -e "puts (1 .. 15).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker $ARG >> /tmp/${TMP_FILE_NAME} 2>&1
	ARG=`ruby -e "puts (1 .. 16).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker $ARG >> /tmp/${TMP_FILE_NAME} 2>&1
	let "n = n - 1"
done

cat /tmp/${TMP_FILE_NAME} | awk '!/OK/ { print $0 }'

