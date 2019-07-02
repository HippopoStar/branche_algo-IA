#!/bin/sh

MY_LOGIN='lcabanes'
DOWNLOADS_FOLDER="/Users/${MY_LOGIN}/Downloads"
ARCHIVE="${DOWNLOADS_FOLDER}/vm_champs.tar"
ARCHIVE_URL='https://projects.intra.42.fr/uploads/document/document/391/vm_champs.tar'
OP_H_URL='https://projects.intra.42.fr/uploads/document/document/27/op.h'
OP_C_URL='https://projects.intra.42.fr/uploads/document/document/26/op.c'

get_corewar_op_h () {
	if test ! -e 'op.h' ; then
		curl -o 'op.h' "${OP_H_URL}"
	fi
}

get_corewar_op_c () {
	if test ! -e 'op.c' ; then
		curl -o 'op.c' "${OP_C_URL}"
	fi
}

get_corewar_vm_and_champs () {
	# Si le repertoire 'vm_champs' est absent
	if test ! -e 'vm_champs' || test ! -d 'vm_champs' ; then
		mkdir 'vm_champs'
		# Si le fichier 'vm_champs.tar' est absent
		if test ! -e 'vm_champs.tar' || test ! -f 'vm_champs.tar' ; then
			# Si on est sur un poste a 42
			if test -e "${DOWNLOADS_FOLDER}" && test -d "${DOWNLOADS_FOLDER}" ; then
				# Si on ne possede pas l'archive dans son repertoire 'Downloads'
				if test ! -e "${ARCHIVE}" || test ! -f "${ARCHIVE}" ; then
					curl -o "${DOWNLOADS_FOLDER}/vm_champs.tar" "${ARCHIVE_URL}"
				fi
				cp "${ARCHIVE}" ./
			# Si on n'est pas sur un poste a 42
			else
				curl -o 'vm_champs.tar' "${ARCHIVE_URL}"
			fi
		fi
		tar -xvf 'vm_champs.tar' -C 'vm_champs'
	fi
}

get_corewar_op_h
get_corewar_op_c
get_corewar_vm_and_champs

