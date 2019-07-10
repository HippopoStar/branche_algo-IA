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
SRC_DIR='provided_champs'
DST_DIR='champs_binaries'

# / ! \ La variable ASM n'est pas utilisee dans ce script auxiliaire,
# pour modifier l'assembleur employer, modifier la valeur de cette variable
# dans le script parent

# / ! \ De meme, en cas de modification des variables SRC_DIR et DST_DIR,
# il est grandement recommende de les modifier dans le script parent egalement

compile_file () {
	if test -e ${2} && test -f ${2} ; then
		mv ${2} ${DST_DIR}
		./${1} ${DST_DIR}/$(basename ${2})
		mv ${DST_DIR}/$(basename ${2}) ${SRC_DIR}
		# Tel quel, les fichiers sources vont etres renvoyes
		# a la racine de leur repertoire d'origine
	else
		echo "Le fichier \"${2}\" n'existe pas ou est un repertoire"
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

if test ${#} -gt 1 ; then
	compile_file ${1} ${2}
else
	echo "${0}: aucun argument passe en parametre au programme"
fi

