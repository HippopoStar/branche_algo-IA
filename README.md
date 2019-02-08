# branche\_algo-IA
From ft\_printf to CoreWar

## In '**ft\_printf**'
[Sujet](https://cdn.intra.42.fr/pdf/pdf/20/ft_printf.fr.pdf)  
[Video de l'e-learning](https://elearning.intra.42.fr/notions/printf/subnotions/printf-introduction/videos/introduction-74)  
- Erreur lors de la combinaison de
	- une *precision* de *0*
	- le flag '*+*' ou le flag ' '
	- une conversion d'un *0* signe
	Exemple : `ft_printf("%.0 i\n", 0);`
- Erreur concernant les unicodes
	- ne pas gerer la precision

## In '**push\_swap**'
[Sujet](https://cdn.intra.42.fr/pdf/pdf/650/push_swap.fr.pdf)  
[Video de l'e-learning](https://elearning.intra.42.fr/notions/push_swap/subnotions/introduction-e9cc20a3-1ab4-484c-93c8-e585f81bfa61/videos/introduction-push_swap)  
- Dans '*push\_swap*'
	- max 3 instructions avec l argument "2 1 0"
	- max 12 instructions avec l argument "1 5 2 4 3" **OU** 5 valeurs quelconques
	- max 5300 instructions avec 500 arguments
	```
	ARG=`ruby -e "puts (-250 .. 249).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | wc -l
	```
- Dans '*checker*'
	- aucun argument : rendre la main sans afficher 'error'
	- argument depassant INT_MAX : 'error'

## In '**lem-in**'
[Sujet](https://cdn.intra.42.fr/pdf/pdf/185/lem-in.fr.pdf)  
[Video de l'e-learning](https://elearning.intra.42.fr/notions/lem_in/subnotions/video-de-presentation/videos/video-de-presentation)  
Documentation :
[Algo' de chemins disjoints de Bhandari](http://www.macfreek.nl/memory/Disjoint_Path_Finding)  

## In '**CoreWar**'
[Sujet](https://cdn.intra.42.fr/pdf/pdf/30/corewar.fr.pdf)  
[Video de l'e-learning](https://elearning.intra.42.fr/notions/corewar/subnotions/corewar-introduction/videos/corewar-introduction)  
[Ressources](https://cdn.intra.42.fr/pdf/pdf/31/resources_corewar.pdf)  
[op.h](https://projects.intra.42.fr/uploads/document/document/27/op.h)  
[op.c](https://projects.intra.42.fr/uploads/document/document/26/op.c)  
[VM and champs](https://projects.intra.42.fr/uploads/document/document/391/vm_champs.tar)  

