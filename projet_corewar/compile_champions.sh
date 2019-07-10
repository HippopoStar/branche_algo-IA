#!/bin/sh

# Droits d'acces d'un fichier a '-rw-r--r--':
# chmod 644 <file>

# $> which ls
# /bin/ls

# /bin/ls -1 -R
# /bin/ls --format=single-column --recursive

# Si on execute la commande '/bin/ls -1 -R ${SRC_DIR}/*.s'
# la commande 'ls' va-t-elle rentrer recursivement dans les
# repertoires dont le nom ne se termine pas par '.s' ?

# /bin/ls -1 -R ${SRC_DIR} | grep -e '\.s'

ASM='ft_asm/asm'
SRC_DIR='provided_champs'
DST_DIR='champs_binaries'

# / ! \
# Si on modifie les valeurs des variables SRC_DIR et DST_DIR,
# il est grandement recommende de les modifier dans le script auxiliaire egalement

# Dans le fichier 'aux_compile_champions.sh'
# (l'interet de ce script auxiliaire par rapport a
# appeler l'executable de l'assembleur directement
# dans la fonction 'compile_directory'
# est de remettre en place les fichiers sources

# compile_file () {
#	if test -e ${1} && test -f ${1} ; then
#		mv ${1} ${DST_DIR}
#		./${ASM} ${DST_DIR}/$(basename ${1})
#		mv ${DST_DIR}/$(basename ${1}) ${SRC_DIR}
#		# Tel quel, les fichiers sources vont etres renvoyes
#		# a la racine de leur repertoire d'origine
#	else
#		echo "Le fichier \"${1}\" n'existe pas ou est un repertoire"
#	fi
# }

compile_directory () {
	if test -e ${SRC_DIR} && test -d ${SRC_DIR} ; then
		# awk - exec
		# awk - system
		# xargs
		# sh
		# sh -c
		# sh -s
		# aux_compile_champions.sh
		# compile_file
		ls -1 ${SRC_DIR}/*.s | awk -v asm="${ASM}" '{ print "sh aux_compile_champions.sh " asm " " $0 }' | sh -s
	else
		echo "Le repertoire \"${SRC_DIR}\" n'existe pas ou est un fichier"
	fi
}

main () {
	if test -e ${DST_DIR} ; then
		if test -f ${DST_DIR} ; then
			echo "Un fichier portant le nom \"${DST_DIR}\" existe deja"
		fi
	else
		echo "Creation du repertoire \"${DST_DIR}\""
		mkdir -p ${DST_DIR}
	fi
	if test -e ${ASM} && test -f ${ASM} ; then
		compile_directory ${DST_DIR}
	else
		echo "Le fichier \"${ASM}\" est introuvable. Avez-vous compile ?"
	fi
}

main

