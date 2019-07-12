#!/bin/sh

MY_DIR='champs_binaries'
REF_DIR='champs_binaries_by_zaz'

# La commande 'let'
# (OpenClassooms/Reprenez le controle a l'aide de Linux/Afficher et manipuler des variables)
# fonctionne sous 'bash' mais pas sous 'sh'

check_nb () {
	local REF_DIR_NB="$(ls -1 ${REF_DIR}/*.cor | wc -l)"
	local MY_DIR_NB="$(ls -1 ${MY_DIR}/*.cor | wc -l)"
	local DIFF="$((${REF_DIR_NB} - ${MY_DIR_NB}))"
	echo "ZaZ a compile ${DIFF} champions de plus que toi !"
}

check_diff () {
	ls -1 ${MY_DIR}/*.cor \
		| awk -v ref_dir="${REF_DIR}" \
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

