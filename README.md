# branche\_algo-IA
From ft\_printf to CoreWar

## In '**ft\_printf**'
- Erreur lors de la combinaison de
	- une *precision* de *0*
	- le flag '*+*' ou le flag ' '
	- une conversion d'un *0* signe
	Exemple : `ft_printf("%.0 i\n", 0);`
- Erreurs concernant les unicodes
	- erreur au-dela d'un certain seuil
	- ne pas gerer la precision
