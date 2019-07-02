#!/bin/sh

# Les lignes suivantes peuvent etre modifiees selon les besoins de l'utilisateur
MY_LOGIN='lcabanes'
WORKING_DIR='.'
OP_H_DIR="${WORKING_DIR}/."
OP_C_DIR="${WORKING_DIR}/."
VM_CHAMPS_DIR="${WORKING_DIR}/."

# Les lignes suivantes ne sont pas supposees etre modifiees par l'utilisateur
OP_H_FILE="${OP_H_DIR}/op.h"
OP_C_FILE="${OP_C_DIR}/op.c"
DOWNLOADS_FOLDER="/Users/${MY_LOGIN}/Downloads"
VM_CHAMPS_ARCHIVE_NAME='vm_champs.tar'
VM_CHAMPS_ARCHIVE_FILE="${VM_CHAMPS_DIR}/${VM_CHAMPS_ARCHIVE_NAME}"
PRE_EXISTING_VM_CHAMPS_ARCHIVE_FILE="${DOWNLOADS_FOLDER}/${VM_CHAMPS_ARCHIVE_NAME}"
VM_CHAMPS_ARCHIVE_URL='https://projects.intra.42.fr/uploads/document/document/391/vm_champs.tar'
OP_H_URL='https://projects.intra.42.fr/uploads/document/document/27/op.h'
OP_C_URL='https://projects.intra.42.fr/uploads/document/document/26/op.c'

get_corewar_op_h () {
	if test -e "${OP_H_DIR}" && test -d "${OP_H_DIR}" ; then
		if test ! -e "${OP_H_FILE}" || test ! -f "${OP_H_FILE}" ; then
			curl -o "${OP_H_FILE}" "${OP_H_URL}"
		fi
	else
		echo "Erreur : Le repertoire \"${OP_H_DIR}\" est inexistant"
	fi
}

get_corewar_op_c () {
	if test -e "${OP_C_DIR}" && test -d "${OP_C_DIR}" ; then
		if test ! -e "${OP_C_FILE}" ; then
			curl -o "${OP_C_FILE}" "${OP_C_URL}"
		fi
	else
		echo "Erreur : Le repertoire \"${OP_C_DIR}\" est inexistant"
	fi
}

get_corewar_vm_and_champs () {
	if test -e "${VM_CHAMPS_DIR}" && test -d "${VM_CHAMPS_DIR}" ; then
		# Si le repertoire 'vm_champs' est absent
		if test ! -e "${VM_CHAMPS_DIR}/vm_champs" || test ! -d "${VM_CHAMPS_DIR}/vm_champs" ; then
			mkdir "${VM_CHAMPS_DIR}/vm_champs"
			# Si le fichier 'vm_champs.tar' est absent
			if test ! -e "${VM_CHAMPS_ARCHIVE_FILE}" || test ! -f "${VM_CHAMPS_ARCHIVE_FILE}" ; then
				# Si on est sur un poste a 42
				if test -e "${DOWNLOADS_FOLDER}" && test -d "${DOWNLOADS_FOLDER}" ; then
					# Si on ne possede pas l'archive dans son repertoire 'Downloads'
					if test ! -e "${PRE_EXISTING_VM_CHAMPS_ARCHIVE_FILE}" || test ! -f "${PRE_EXISTING_VM_CHAMPS_ARCHIVE_FILE}" ; then
						curl -o "${PRE_EXISTING_VM_CHAMPS_ARCHIVE_FILE}" "${VM_CHAMPS_ARCHIVE_URL}"
					fi
					cp "${PRE_EXISTING_VM_CHAMPS_ARCHIVE_FILE}" "${VM_CHAMPS_DIR}"
				# Si on n'est pas sur un poste a 42
				else
					curl -o "${VM_CHAMPS_ARCHIVE_FILE}" "${VM_CHAMPS_ARCHIVE_URL}"
				fi
			fi
			tar -xvf "${VM_CHAMPS_ARCHIVE_FILE}" -C "${VM_CHAMPS_DIR}/vm_champs"
		fi
	else
		echo "Erreur : Le repertoire \"${VM_CHAMPS_DIR}\" est inexistant"
	fi
}

get_corewar_dependencies () {
	if test -e ${WORKING_DIR} && test -d ${WORKING_DIR} ; then
		get_corewar_op_h
		get_corewar_op_c
		get_corewar_vm_and_champs
	fi
}

remove_corewar_dependencies () {
	if test -e ${WORKING_DIR} && test -d ${WORKING_DIR} ; then
		rm -f "${OP_H_FILE}"
		rm -f "${OP_C_FILE}"
		rm -f "${VM_CHAMPS_ARCHIVE_FILE}"
		# Le fait d'ecrire le nom de repertoire 'vm_champs' en dur apporte notamment une securite supplementaire dans la commande suivante
		rm -rf "${VM_CHAMPS_DIR}/vm_champs"
#		rm -f "${VM_CHAMPS_DIR}/vm_champs/._asm"
#		rm -f "${VM_CHAMPS_DIR}/vm_champs/._corewar"
#		rm -f "${VM_CHAMPS_DIR}/vm_champs/._champs"
#		rm -df "${VM_CHAMPS_DIR}/vm_champs"
	fi
}

if test ${#} -ne 1 || test ! "x${1}" = 'xrm' ; then
	get_corewar_dependencies
else
	remove_corewar_dependencies
fi
