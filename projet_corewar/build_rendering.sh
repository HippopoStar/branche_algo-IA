#!/bin/sh

PATH_WORKING_DIR='/Users/lcabanes/Documents/branche_algo_et_IA/projet_corewar'
PATH_RENDERING="${PATH_WORKING_DIR}/rendu"
PATH_ASM="${PATH_WORKING_DIR}/ft_asm"
PATH_COREWAR='/tmp/cmiran_corewar'
PATH_LIBFT='/tmp/cmiran_libft'

mkdir -p ${PATH_RENDERING}/srcs_corewar
git clone https://github.com/cmiran/corewar.git ${PATH_COREWAR}
cp ${PATH_COREWAR}/*.c ${PATH_RENDERING}/srcs_corewar/
cp ${PATH_COREWAR}/corewar.h ${PATH_RENDERING}/includes/

mkdir -p ${PATH_RENDERING}/libft
mkdir -p ${PATH_RENDERING}/libft/includes
git clone https://github.com/cmiran/libft.git ${PATH_LIBFT}
cp ${PATH_LIBFT}/*.c ${PATH_RENDERING}/libft/
cp ${PATH_LIBFT}/*.h ${PATH_RENDERING}/libft/includes/
cp ${PATH_LIBFT}/Makefile ${PATH_RENDERING}/libft/

cp ${PATH_ASM}/srcs_asm/*.c ${PATH_RENDERING}/srcs_asm/

echo 'Ne pas omettre d adapter les variables suivantes :'
echo "1. \$(INC) de ./rendu/libft/Makefile"
echo "2. La dependance 'libft.h' de ./rendu/libft/Makefile"
echo "3. L'inclusion de header 'libft/libft.h' de ./rendu/includes/corewar.h"
echo "4. La variable de la macro 'BUFF_SIZE' de ./rendu/libft/includes/libft.h"

