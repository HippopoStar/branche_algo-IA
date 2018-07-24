#!/bin/sh
git rm Makefile
git rm -r ./includes
git rm -r ./srcs_libft
git rm -r ./srcs_common_functions
git rm -r ./srcs_libftprintf
rm -rf /tmp/temporary_branche_algo_et_IA
git clone https://github.com/HippopoStar/branche_algo_et_IA.git /tmp/temporary_branche_algo_et_IA/
cp /tmp/temporary_branche_algo_et_IA/projet_ft_printf/libftprintf/Makefile ./
cp -r /tmp/temporary_branche_algo_et_IA/projet_ft_printf/libftprintf/includes ./
cp -r /tmp/temporary_branche_algo_et_IA/projet_ft_printf/libftprintf/srcs_libft ./
cp -r /tmp/temporary_branche_algo_et_IA/projet_ft_printf/libftprintf/srcs_common_functions ./
cp -r /tmp/temporary_branche_algo_et_IA/projet_ft_printf/libftprintf/srcs_libftprintf ./
echo '\033[36m_____\033[00m'
git status
git add *
echo '\033[36m_____\033[00m'
git status
git commit -m "Test de \"ft_printf\""
echo '\033[36m_____\033[00m'
git status
git push
echo '\033[36m_____\033[00m'
git status
