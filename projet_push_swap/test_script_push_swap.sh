#!/bin/sh

TMP_FILE_NAME='test_script_push_swap.tmp'

usage () {
	echo "usage: ${0} [first nb] [last nb] [nb of iterations]"
}

if test ${#} -ne 3 || test ${3} -le 0 || test ${1} -gt ${2} ; then
	usage
else
	rm -f /tmp/${TMP_FILE_NAME}
	touch /tmp/${TMP_FILE_NAME}

	let "n = ${3}"
	while test ${n} -gt 0 ; do
		{ ARG=`ruby -e "puts (${1} .. ${2}).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker $ARG ; } >> /tmp/${TMP_FILE_NAME} 2>&1
		let "n = n - 1"
	done

	cat /tmp/${TMP_FILE_NAME} | awk '!/OK/ { print $0 }'
	echo "Pour consulter les logs : \`cat /tmp/${TMP_FILE_NAME}\`"
	echo "(nombre de lignes du fichier de log : `cat /tmp/${TMP_FILE_NAME} | wc -l`)"
fi

