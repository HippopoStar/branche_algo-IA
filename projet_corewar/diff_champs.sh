#!/bin/sh

MY_DIR='champs_binaries'
REF_DIR='champs_binaries_by_zaz'

check_nb () {
	let "a = `ls -1 ${REF_DIR}/*.cor | wc -l`"
	let "b = `ls -1 ${MY_DIR}/*.cor | wc -l`"
	let "c = a - b"
	echo "ZaZ a compile ${c} champions de plus que toi !"
}

check_diff () {
	ls -1 ${MY_DIR}/*.cor \
		| awk -v ref_dir="${REF_DIR}" -v log="${LOG_FILE}" \
			'{ print "echo ./" $0 "\ndiff " $0 " " ref_dir "/$(basename " $0 ")" }' \
		| sh -s
}

main () {
	if ! test -e ${MY_DIR} || ! test -d ${MY_DIR} ; then
		echo "Impossible de trouver le dossier \"${MY_DIR}\""
	elif ! test -e ${REF_DIR} || ! test -d ${REF_DIR} ; then
		echo "Impossible de trouver le dossier \"${REF_DIR}\""
	else
		check_diff
		check_nb
	fi
}

main

