#!/bin/sh

# $> which ls
# /bin/ls

# /bin/ls -1 -R
# /bin/ls --format=single-column --recursive

# Si on execute la commande '/bin/ls -1 -R ${SRC_DIR}/*.s'
# la commande 'ls' va-t-elle rentrer recursivement dans les
# repertoires dont le nom ne se termine pas par '.s' ?

# /bin/ls -1 -R ${SRC_DIR} | grep -e '\.s'

ASM='ft_asm/asm'
SRC_DIR='vm_champs/champs'
DST_DIR='champs_binaries'

compile_file () {
	if test -e ${1} && test -f ${1} ; then
		mv ${1} ${DST_DIR}
		./${ASM} ${DST_DIR}/$(basename ${1})
		mv ${DST_DIR}/$(basename ${1}) ${SRC_DIR}
		# Tel quel, les fichiers sources vont etres renvoyes
		# a la racine de leur repertoire d'origine
	else
		echo "Le fichier \"${1}\" n'existe pas ou est un repertoire"
	fi
}

# main () {
#	if test ${#} -gt 0 ; then
#		compile_file ${1}
#	else
#		echo "${0}: aucun argument passe en parametre au programme"
#	fi
# }
#
# main ${1}

if test ${#} -gt 0 ; then
	compile_file ${1}
else
	echo "${0}: aucun argument passe en parametre au programme"
fi

