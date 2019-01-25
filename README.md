# branche\_algo-IA
From ft\_printf to CoreWar

## In '**ft\_printf**'
- Erreur lors de la combinaison de
	- une *precision* de *0*
	- le flag '*+*' ou le flag ' '
	- une conversion d'un *0* signe
	Exemple : `ft_printf("%.0 i\n", 0);`
- Erreur concernant les unicodes
	- ne pas gerer la precision

## In '**push_swap**'
- Dans '*push\_swap*'
	- max 3 instructions avec l argument "2 1 0"
	- max 12 instructions avec l argument "1 5 2 4 3" **OU** 5 valeurs quelconques
	- max 5300 instructions avec 500 arguments
	```ARG=`ruby -e "puts (-250 .. 249).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | wc -l```
- Dans '*checker*'
	- aucun argument : rendre la main sans afficher 'error'
	- argument depassant INT_MAX : 'error'
